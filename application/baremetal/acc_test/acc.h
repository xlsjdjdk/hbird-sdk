// See LICENSE for license details.
#ifndef _HBIRDV2_ACC_CFG_H
#define _HBIRDV2_ACC_CFG_H

#ifdef __cplusplus
 extern "C" {
#endif

int32_t acc_StartCalc(ACC_CFG_TypeDef *cfg);

int32_t acc_ConfigCalc(ACC_CFG_TypeDef *cfg, int32_t calc_mode, int32_t cs, int32_t k, int32_t r, int32_t c);

int32_t acc_ConfigMode(ACC_CFG_TypeDef *cfg, int32_t work_mode, int32_t cs);

int32_t acc_CfgCalcAddr(ACC_CFG_TypeDef *cfg, int32_t base_row, int32_t base_col, int32_t wb_addr);

int32_t acc_CfgRWAddr(ACC_CFG_TypeDef *cfg, int32_t base_row, int32_t base_col);

int32_t acc_WaitCalc(ACC_CFG_TypeDef *cfg);

int32_t acc_ReadSRAM(ACC_CFG_TypeDef *cfg, int32_t addr);

int32_t acc_WriteSRAM(ACC_CFG_TypeDef *cfg, int32_t addr, int32_t data);

#ifdef __cplusplus
}
#endif
#endif /* _HBIRDV2_ACC_CFG_H */