#include "hbirdv2.h"
#include "adder.h"

int32_t adder_loadNum(ADD_CFG_TypeDef *cfg, uint32_t augend, uint32_t addend)
{
    if (__RARELY(cfg == NULL)) {
        return -1;
    }
    cfg-> AUGEND = augend;
    cfg-> ADDEND = addend;

    return 0;
}

int32_t adder_enable(ADD_CFG_TypeDef *cfg)
{
    if (__RARELY(cfg == NULL)) {
        return -1;
    }
    cfg-> CTRL = cfg-> CTRL | 0x00000001;
}

int32_t adder_disable(ADD_CFG_TypeDef *cfg)
{
    if (__RARELY(cfg == NULL)) {
        return -1;
    }
    cfg-> CTRL = cfg-> CTRL & 0x00000000;
}

int32_t adder_clear(ADD_CFG_TypeDef *cfg)
{
    if (__RARELY(cfg == NULL)) {
        return -1;
    }
    cfg-> CTRL = cfg-> CTRL | 0x00000002;
}

int32_t adder_readSum(ADD_CFG_TypeDef *cfg)
{
    if (__RARELY(cfg == NULL)) {
        return -1;
    }

    return adder_readNum(ADD_CFG, 4);
}

int32_t adder_readOfsign(ADD_CFG_TypeDef *cfg)
{
    if (__RARELY(cfg == NULL)) {
        return -1;
    }

    return adder_readNum(ADD_CFG, 3);
}

int32_t adder_readNum(ADD_CFG_TypeDef *cfg, int option)
{
    if (__RARELY(cfg == NULL)) {
        return -1;
    }
    
    int num;

    if (option == 0) {
        num = ADD_CFG -> AUGEND;
    }
    else if (option == 1) {
        num = ADD_CFG -> ADDEND;
    }
    else if (option == 2) {
        num = ADD_CFG -> CTRL;
    }
    else if (option == 3) {
        num = ADD_CFG -> OFSIGN;
    }
    else if (option == 4) {
        num = ADD_CFG -> SUM;
    }
    else {
        return -1;
    }

    return num;
}
