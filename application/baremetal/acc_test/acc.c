#include "hbirdv2.h"
#include "acc.h"

int32_t acc_StartCalc(ACC_CFG_TypeDef *cfg){
    if (__RARELY(cfg == NULL)) {
        return -1;
    }
    ACC_CFG -> STAT_REG = ACC_CFG -> STAT_REG ^ 0x00000001;
    return 0;
}

int32_t acc_ConfigCalc(ACC_CFG_TypeDef *cfg, int32_t calc_mode, int32_t cs, int32_t k, int32_t r, int32_t c){
    if (__RARELY(cfg == NULL)) {
        return -1;
    }
    ACC_CFG -> CONFIG_REG = (c << 24) | (r << 16) | (k << 8) | (cs << 3) | calc_mode;
    return 0;
}

int32_t acc_ConfigMode(ACC_CFG_TypeDef *cfg, int32_t work_mode, int32_t cs){
    if (__RARELY(cfg == NULL)) {
        return -1;
    }
    ACC_CFG -> CONFIG_REG = (work_mode << 1) | (cs << 3);
    return 0;
}

int32_t acc_CfgCalcAddr(ACC_CFG_TypeDef *cfg, int32_t base_row, int32_t base_col, int32_t wb_addr){
    if (__RARELY(cfg == NULL)) {
        return -1;
    }
    ACC_CFG -> CALCBASE_REG = (base_col << 16) + base_row;
    ACC_CFG -> STAT_REG = wb_addr << 1;
    return 0;
}

int32_t acc_CfgRWAddr(ACC_CFG_TypeDef *cfg, int32_t base_row, int32_t base_col){
    if (__RARELY(cfg == NULL)) {
        return -1;
    }
    ACC_CFG -> RWBASE_REG = (base_col << 16) + base_row;
    return 0;
}

int32_t acc_WaitCalc(ACC_CFG_TypeDef *cfg){
    if (__RARELY(cfg == NULL)) {
        return -1;
    }
    while((ACC_CFG -> STAT_REG & 0x00010000) == 0){}

    return 0;
}

int32_t acc_ReadSRAM(ACC_CFG_TypeDef *cfg, int32_t addr){
    if (__RARELY(cfg == NULL)) {
        return -1;
    }

    int32_t data;

    data = *(&(ACC_CFG->STAT_REG) + (addr * 8 + 4));

    return data;
}

int32_t acc_WriteSRAM(ACC_CFG_TypeDef *cfg, int32_t addr, int32_t data){
    if (__RARELY(cfg == NULL)) {
        return -1;
    }
    *(&(ACC_CFG->STAT_REG) + (addr * 8 + 4)) = data;

    return 0;
}

int32_t acc_LoadInput(ACC_CFG_TypeDef *cfg, int32_t data[768]){
    if (__RARELY(cfg == NULL)) {
        return -1;
    }
    acc_ConfigMode(ACC_CFG, 1, 0);
    for (int i=0; i<12; i++){
        acc_CfgRWAddr(ACC_CFG, 64*i, 0);
        for (int j=0; j<64; j++){
            acc_WriteSRAM(ACC_CFG, j, data[64*i+j]);
        }
    }
}

int32_t acc_LoadWeight(ACC_CFG_TypeDef *cfg, int32_t data[6912]){
    if (__RARELY(cfg == NULL)) {
        return -1;
    }
    acc_ConfigMode(ACC_CFG, 1, 1);
    for (int i=0; i<108; i++){
        acc_CfgRWAddr(ACC_CFG, 0, 64*i);
        for (int j=0; j<64; j++){
            acc_WriteSRAM(ACC_CFG, j, data[64*i+j]);
        }
    }
}

int32_t acc_calcQ(ACC_CFG_TypeDef *cfg){
    if (__RARELY(cfg == NULL)) {
        return -1;
    }
    acc_ConfigCalc(ACC_CFG, 0, 0, 96, 8, 12);
    acc_CfgCalcAddr(ACC_CFG, 0, 0, 768);
    acc_StartCalc(ACC_CFG);
    acc_WaitCalc(ACC_CFG);
    acc_ConfigCalc(ACC_CFG, 0, 0, 96, 8, 12);
    acc_CfgCalcAddr(ACC_CFG, 0, 1152, 1152);
    acc_StartCalc(ACC_CFG);
    acc_WaitCalc(ACC_CFG);
}

int32_t acc_calcK(ACC_CFG_TypeDef *cfg){
    if (__RARELY(cfg == NULL)) {
        return -1;
    }
    acc_ConfigCalc(ACC_CFG, 0, 1, 96, 8, 12);
    acc_CfgCalcAddr(ACC_CFG, 0, 2304, 7296);
    acc_StartCalc(ACC_CFG);
    acc_WaitCalc(ACC_CFG);
    acc_ConfigCalc(ACC_CFG, 0, 1, 96, 8, 12);
    acc_CfgCalcAddr(ACC_CFG, 0, 3456, 7680);
    acc_StartCalc(ACC_CFG);
    acc_WaitCalc(ACC_CFG);
}
