#ifndef FILTER_SRED_H
#define FILTER_SRED_H

#define COUNT_FILTER 128

typedef union {
    unsigned int Val;
    struct
    {
        unsigned Flag : 1;
        unsigned Index : 8;
        unsigned Filter_sum : 23;
    } Reg;
} FILTER_REG;

unsigned short int filter_sred(unsigned short int ADC_val, unsigned short int* buf, FILTER_REG* filter_reg) {

    if (filter_reg->Reg.Flag) {
        filter_reg->Reg.Filter_sum -= buf[filter_reg->Reg.Index];
        filter_reg->Reg.Filter_sum += ADC_val;
        buf[filter_reg->Reg.Index] = ADC_val;
        if (filter_reg->Reg.Index >= COUNT_FILTER - 1) {
            filter_reg->Reg.Index = 0;
        } else {
            filter_reg->Reg.Index++;
        }
    } else {
        filter_reg->Reg.Filter_sum += ADC_val;
        buf[filter_reg->Reg.Index] = ADC_val;
        if (filter_reg->Reg.Index >= COUNT_FILTER - 1) {
            filter_reg->Reg.Index = 0;
            filter_reg->Reg.Flag = 1;
        } else {
            filter_reg->Reg.Index++;
        }
    }
    return (filter_reg->Reg.Filter_sum / COUNT_FILTER);
}

#endif // FILTER_SRED_H
