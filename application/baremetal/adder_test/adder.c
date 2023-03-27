#include "hbirdv2.h"
#include "adder.h"

int32_t adder_config(ADD_CFG_TypeDef *cfg, uint32_t augend, uint32_t addend)
{
    if (__RARELY(cfg == NULL)) {
        return -1;
    }
    cfg-> AUGEND = augend;
    cfg-> ADDEND = addend;

    return 0;
}


int32_t adder_start(ADD_CFG_TypeDef *cfg)
{
    if (__RARELY(cfg == NULL)) {
        return -1;
    }
    cfg->CONTROL = 0x1;

    return 0;
}

int32_t adder_sum(ADD_CFG_TypeDef *cfg)
{
    if (__RARELY(cfg == NULL)) {
        return -1;
    }
    int32_t status = cfg->STATUS;
    
    if(status) {
    	cfg->STATUS = 0x0;
    }

    return status;
}

