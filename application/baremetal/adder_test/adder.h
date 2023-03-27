// See LICENSE for license details.
#ifndef _HBIRDV2_ADD_CFG_H
#define _HBIRDV2_ADD_CFG_H

#ifdef __cplusplus
 extern "C" {
#endif

int32_t adder_config(ADD_CFG_TypeDef *cfg, uint32_t augend, uint32_t addend);
int32_t adder_start(ADD_CFG_TypeDef *cfg);
int32_t adder_sum(ADD_CFG_TypeDef *cfg);

#ifdef __cplusplus
}
#endif
#endif /* _HBIRDV2_ADD_CFG_H */