
#include <PS4USB.h>
#include <SPI.h>

#include "filter_sred.h"

// GLOBAL STATES

#define VREF 3.3f
#define JOY_BAT_PIN A8

#define JOY_R1 336
#define JOY_R2 645
#define JOY_MIN_V 3.7f
#define JOY_MAX_V 4.2f

float joyBatVoltage;
uint16_t joyBatInt1;
uint16_t joyBatInt2;
float joyBatPercent;
uint16_t joyBatPercentInt;

FILTER_REG Filter1;
uint16_t adc1;
uint16_t adcFilterBuff1[COUNT_FILTER];
uint16_t adcFilter1;

uint32_t feedbackCount = 0;
uint32_t msgSendCount = 0;
uint32_t goodPackages = 0;
uint32_t badPackages = 0;

uint8_t joyState = 0;
uint8_t feedState = 0;

// END GLOBAL STATES

// TATICOMA STATES

uint8_t taticomaMode = 0;
uint8_t taticomaGaitMode = 0;

// END TATICOMA STATES

// PS4 VAL

USB Usb;
PS4USB PS4(&Usb);

#define HAT_TRESHOLD 15

#define CHECKSUM 0x10
#define FEEDBACK 0x20
#define HEADER 0x71

#define CMD_OPTIONS 0x68
#define CMD_CHANGE_HAT_LX 0x80
#define CMD_CHANGE_HAT_LY 0x81
#define CMD_CHANGE_HAT_RX 0x82
#define CMD_CHANGE_HAT_RY 0x83
#define CMD_CHANGE_L2 0x84
#define CMD_CHANGE_R2 0x85
#define CMD_CHANGE_L1 0x86
#define CMD_CHANGE_R1 0x87
#define CMD_CHANGE_TRIANGLE 0x88

#define FEED_MODE 0x58
#define FEED_GAIT_MODE 0x59

#define MSG_BUFFER_SIZE 10

struct Msg {
    uint8_t cmd;
    uint8_t data;
};

Msg outputMsgBuffer[MSG_BUFFER_SIZE];

uint8_t counter;

unsigned long lastMsgTime;

uint8_t options = 0;
uint8_t lx = 127;
uint8_t ly = 127;
uint8_t rx = 127;
uint8_t ry = 127;
uint8_t l2 = 0;
uint8_t r2 = 0;
uint8_t l1 = 0;
uint8_t r1 = 0;
uint8_t triangle = 0;

uint8_t lx_read = 127;
uint8_t ly_read = 127;
uint8_t rx_read = 127;
uint8_t ry_read = 127;
uint8_t l2_read = 0;
uint8_t r2_read = 0;
uint8_t l1_read = 0;
uint8_t r1_read = 0;

uint8_t _byte;
uint16_t sendChecksum;
uint16_t readChecksum;
uint8_t originalChecksum;

uint8_t* sendBuffer3;
uint8_t* readBuffer3;

bool receiveFlag = true;

// END PS4 VAL

// GLOBAL OPERATION

void joyVoltageHandle() {
  
    adc1 = analogRead(JOY_BAT_PIN);
    adcFilter1 = filter_sred(adc1, adcFilterBuff1, &Filter1);

    float batVoltage = adcFilter1 * (VREF / 4095.0);
    joyBatVoltage = batVoltage * (JOY_R1 + JOY_R2) / JOY_R2;

    joyBatInt1 = joyBatVoltage;
    float tmpFrac = joyBatVoltage - joyBatInt1;
    joyBatInt2 = trunc(tmpFrac * 100);

    joyBatPercent = ((JOY_MIN_V - joyBatVoltage) * 100) / (JOY_MIN_V - JOY_MAX_V);
    joyBatPercentInt = joyBatPercent;
}

// END GLOBAL OPERATION

// NEXTION OPERATION

void nextionSetup() {
    Serial2.begin(9600);
    delay(1500);
    Serial2.print("baud=115200");
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.end();
    Serial2.begin(115200);
}

void nextionSendData(String dev, String data) {
    Serial2.print(dev);
    Serial2.print("=");
    Serial2.print(data);
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
}

void nextionHandle() {

    nextionSendData("joyState.val", String(joyState, DEC));
    nextionSendData("feedState.val", String(feedState, DEC));

    nextionSendData("taticomaMode.val", String(taticomaMode, DEC));
    nextionSendData("taticomaGMode.val", String(taticomaGaitMode, DEC));

    nextionSendData("feedbackCount.val", String(feedbackCount, DEC));
    nextionSendData("msgSendCount.val", String(msgSendCount, DEC));
    nextionSendData("goodPackages.val", String(goodPackages, DEC));
    nextionSendData("badPackages.val", String(badPackages, DEC));

    nextionSendData("joyBatInt1.val", String(joyBatInt1, DEC));  
    nextionSendData("joyBatInt2.val", String(joyBatInt2, DEC));  
    nextionSendData("joyBatPerInt.val", String(joyBatPercentInt, DEC));  
}

// END NEXTION OPERATION

// PS4 OPERATION

unsigned long now() {
    return millis();
}

void setBuffers() {
    sendBuffer3 = new uint8_t[3 * sizeof(uint8_t)];
    memset(sendBuffer3, 0, 3 * sizeof(uint8_t));
    readBuffer3 = new uint8_t[3 * sizeof(uint8_t)];
    memset(readBuffer3, 0, 3 * sizeof(uint8_t));

    for (uint16_t i = 0; i < MSG_BUFFER_SIZE; i++) {
        outputMsgBuffer[i].data = 0;
    }

    outputMsgBuffer[0].cmd = CMD_OPTIONS;
    outputMsgBuffer[1].cmd = CMD_CHANGE_HAT_LX;
    outputMsgBuffer[2].cmd = CMD_CHANGE_HAT_LY;
    outputMsgBuffer[3].cmd = CMD_CHANGE_HAT_RX;
    outputMsgBuffer[4].cmd = CMD_CHANGE_HAT_RY;
    outputMsgBuffer[5].cmd = CMD_CHANGE_L2;
    outputMsgBuffer[6].cmd = CMD_CHANGE_R2;
    outputMsgBuffer[7].cmd = CMD_CHANGE_L1;
    outputMsgBuffer[8].cmd = CMD_CHANGE_R1;
    outputMsgBuffer[9].cmd = CMD_CHANGE_TRIANGLE;
}

uint8_t* prepareSimpleMsg3Bytes(uint8_t* buffer, uint8_t cmd, uint8_t data) {
    sendChecksum = 0;
    buffer[0] = cmd;
    buffer[1] = data;
    sendChecksum += buffer[0];
    sendChecksum += buffer[1];
    buffer[2] = sendChecksum & CHECKSUM;
    return buffer;
}

void sendMsg(uint8_t cmd, uint8_t data) {
    sendBuffer3 = prepareSimpleMsg3Bytes(sendBuffer3, cmd, data);
    Serial3.write(HEADER);
    Serial3.write(sendBuffer3, 3);
    msgSendCount++;
}

void parseMsg(uint8_t feed, uint8_t data) {
    if (feed == FEED_MODE) {
        if (taticomaMode != data) {
            taticomaMode = data;
        }
    }
    if (feed == FEED_GAIT_MODE) {
        if (taticomaGaitMode != data) {
            taticomaGaitMode = data;
        }
    }
}

bool readMsg() {
    Serial3.readBytes(readBuffer3, 3);
    readChecksum = 0;
    originalChecksum = readBuffer3[2];
    readChecksum += readBuffer3[0];
    readChecksum += readBuffer3[1];
    uint8_t result = readChecksum & CHECKSUM;
    if (originalChecksum == result) {
        parseMsg(readBuffer3[0], readBuffer3[1]);
        goodPackages++;
        return true;
    } else {
        badPackages++;
        return false;
    }
}

void checkPSUpdates() {

    if (PS4.getButtonClick(OPTIONS)) {
        options = !options;
        outputMsgBuffer[0].data = options;
    }

    l1_read = PS4.getButtonPress(L1);
    r1_read = PS4.getButtonPress(R1);

    lx_read = PS4.getAnalogHat(LeftHatX);
    if (lx_read < 127 + HAT_TRESHOLD && lx_read > 127 - HAT_TRESHOLD)
        lx_read = 127;

    ly_read = PS4.getAnalogHat(LeftHatY);
    if (ly_read < 127 + HAT_TRESHOLD && ly_read > 127 - HAT_TRESHOLD)
        ly_read = 127;

    rx_read = PS4.getAnalogHat(RightHatX);
    if (rx_read < 127 + HAT_TRESHOLD && rx_read > 127 - HAT_TRESHOLD)
        rx_read = 127;

    ry_read = PS4.getAnalogHat(RightHatY);
    if (ry_read < 127 + HAT_TRESHOLD && ry_read > 127 - HAT_TRESHOLD)
        ry_read = 127;

    l2_read = PS4.getAnalogButton(L2);
    r2_read = PS4.getAnalogButton(R2);

    if (PS4.getButtonClick(TRIANGLE)) {
        triangle = !triangle;
        outputMsgBuffer[9].data = triangle;
    }
}

void serialSend() {
    if (receiveFlag == true) {
        switch (counter) {
        case 0:
            sendMsg(outputMsgBuffer[0].cmd, outputMsgBuffer[0].data);
            counter++;
            lastMsgTime = now();
            receiveFlag = false;
            break;
        case 1:
            if (lx != lx_read) {
                lx = lx_read;
                outputMsgBuffer[1].data = lx;
                sendMsg(outputMsgBuffer[1].cmd, outputMsgBuffer[1].data);
                counter++;
                lastMsgTime = now();
                receiveFlag = false;
                break;
            } else {
                counter++;
                break;
            }
        case 2:
            if (ly != ly_read) {
                ly = ly_read;
                outputMsgBuffer[2].data = ly;
                sendMsg(outputMsgBuffer[2].cmd, outputMsgBuffer[2].data);
                counter++;
                lastMsgTime = now();
                receiveFlag = false;
                break;
            } else {
                counter++;
                break;
            }
        case 3:
            if (rx != rx_read) {
                rx = rx_read;
                outputMsgBuffer[3].data = rx;
                sendMsg(outputMsgBuffer[3].cmd, outputMsgBuffer[3].data);
                counter++;
                lastMsgTime = now();
                receiveFlag = false;
                break;
            } else {
                counter++;
                break;
            }
        case 4:
            if (ry != ry_read) {
                ry = ry_read;
                outputMsgBuffer[4].data = ry;
                sendMsg(outputMsgBuffer[4].cmd, outputMsgBuffer[4].data);
                counter++;
                lastMsgTime = now();
                receiveFlag = false;
                break;
            } else {
                counter++;
                break;
            }
        case 5:
            if (l2 != l2_read) {
                l2 = l2_read;
                outputMsgBuffer[5].data = l2;
                sendMsg(outputMsgBuffer[5].cmd, outputMsgBuffer[5].data);
                counter++;
                lastMsgTime = now();
                receiveFlag = false;
                break;
            } else {
                counter++;
                break;
            }
        case 6:
            if (r2 != r2_read) {
                r2 = r2_read;
                outputMsgBuffer[6].data = r2;
                sendMsg(outputMsgBuffer[6].cmd, outputMsgBuffer[6].data);
                counter++;
                lastMsgTime = now();
                receiveFlag = false;
                break;
            } else {
                counter++;
                break;
            }
        case 7:
            if (l1 != l1_read) {
                l1 = l1_read;
                outputMsgBuffer[7].data = l1;
                sendMsg(outputMsgBuffer[7].cmd, outputMsgBuffer[7].data);
                counter++;
                lastMsgTime = now();
                receiveFlag = false;
                break;
            } else {
                counter++;
                break;
            }
        case 8:
            if (r1 != r1_read) {
                r1 = r1_read;
                outputMsgBuffer[8].data = r1;
                sendMsg(outputMsgBuffer[8].cmd, outputMsgBuffer[8].data);
                counter++;
                lastMsgTime = now();
                receiveFlag = false;
                break;
            } else {
                counter++;
                break;
            }
        case 9:
            sendMsg(outputMsgBuffer[9].cmd, outputMsgBuffer[9].data);
            counter++;
            lastMsgTime = now();
            receiveFlag = false;
            break;
        case MSG_BUFFER_SIZE:
            counter = 0;
            break;
        }
    }

    if (receiveFlag == false) {
        if ((now() - lastMsgTime) >= 1000) {
            feedState = 0;
            receiveFlag = true;
        }
    }
}

void ps4LedControl() {
    switch (taticomaMode) {
    case 0:
        PS4.setLed(Yellow);
        break;
    case 1:
        PS4.setLed(Red);
        break;
    case 2:
        PS4.setLed(Blue);
        break;
    case 3:
        PS4.setLed(Green);
        break;
    }
    PS4.setLedFlash(0, 0);
}

// END PS4 OPERATION

void setup() {
    Usb.Init();
    setBuffers();
    
    nextionSetup();

    Serial3.begin(115200);

    analogReadResolution(12);
    pinMode(JOY_BAT_PIN, OUTPUT);
    Filter1.Val = 0;
    
    counter = 0;
}

void loop() {

    joyVoltageHandle();
    
    serialSend();

    Usb.Task();
    
    if (PS4.connected()) {
      
        joyState = 1;

        checkPSUpdates();
        modeControl();
        gaitModeControl();

    } else{
        joyState = 0;
    } 
    
    nextionHandle();
}

void serialEvent3() {
    while (Serial3.available()) {
        _byte = Serial3.read();

        if (_byte == FEEDBACK) {
            feedbackCount++;
            feedState = 1;
            if (readMsg()) {
                receiveFlag = true;
            }
        }
    }
}
