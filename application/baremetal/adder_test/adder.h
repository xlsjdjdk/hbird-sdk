// See LICENSE for license details.
#ifndef _HBIRDV2_ADD_CFG_H
#define _HBIRDV2_ADD_CFG_H

#ifdef __cplusplus
 extern "C" {
#endif

int32_t adder_loadNum(ADD_CFG_TypeDef *cfg, int32_t augend, int32_t addend);
int32_t adder_enable(ADD_CFG_TypeDef *cfg);
int32_t adder_disable(ADD_CFG_TypeDef *cfg);
int32_t adder_clear(ADD_CFG_TypeDef *cfg);
int32_t adder_readSum(ADD_CFG_TypeDef *cfg);
int32_t adder_readOfsign(ADD_CFG_TypeDef *cfg);
int32_t adder_readNum(ADD_CFG_TypeDef *cfg, int32_t option);

#ifdef __cplusplus
}
#endif
#endif /* _HBIRDV2_ADD_CFG_H */