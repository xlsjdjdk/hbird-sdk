#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "hbird_sdk_soc.h"
#include "adder.h"

// #define AUGEND_OFFSET (0x0)
// #define ADDEND_OFFSET (0x00004)
// #define SUM_OFFSET    (0x00008)
// #define START_OFFSET  (0x0000a)


int main(void)
{
    int32_t augend;
    int32_t addend;
    int32_t sum;
    printf("Hello World From RISC-V Processor!\n");

    printf("\n\n\n########## Test case 1 ##########\n\n\n");
    augend = 10;
    addend = -10;
    printf("Input = %d, %d\n", augend, addend);
    adder_loadNum(ADD_CFG,augend,addend);
    adder_enable(ADD_CFG);
    int32_t result = adder_readSum(ADD_CFG);
    printf("result = %d\n", result);
    int32_t ofsign = adder_readOfsign(ADD_CFG);
    printf("ofsign = %d\n", ofsign);

    printf("\n\n\n########## Test case 2 ##########\n\n\n");
    augend = 0x80000000;
    addend = 0x80000000;
    printf("Input = %d, %d\n", augend, addend);
    adder_loadNum(ADD_CFG,augend,addend);
    adder_enable(ADD_CFG);
    result = adder_readSum(ADD_CFG);
    printf("result = %d\n", result);
    ofsign = adder_readOfsign(ADD_CFG);
    printf("ofsign = %d\n", ofsign);

    printf("\n\n\n########## Test case 3 ##########\n\n\n");
    augend = 0x7FFFFFFF;
    addend = 0x7FFFFFFF;
    printf("Input = %d, %d\n", augend, addend);
    adder_loadNum(ADD_CFG,augend,addend);
    adder_enable(ADD_CFG);
    result = adder_readSum(ADD_CFG);
    printf("result = %d\n", result);
    ofsign = adder_readOfsign(ADD_CFG);
    printf("ofsign = %d\n", ofsign);
    

    printf("\n\n\n########## Test case 4 ##########\n\n\n");
    adder_clear(ADD_CFG);

    int32_t augend_r, addend_r;
    augend_r = adder_readNum(ADD_CFG, 0);
    addend_r = adder_readNum(ADD_CFG, 1);
    result = adder_readSum(ADD_CFG);
    ofsign = adder_readOfsign(ADD_CFG);
    printf("Input after clear: %d,%d\n", augend_r,addend_r);
    printf("result & ofsign after clear: %d,%d\n", result,ofsign);

    printf("\n\n\n########## Test case 5 ##########\n\n\n");
    adder_disable(ADD_CFG);
    adder_loadNum(ADD_CFG,augend,addend);
    printf("Input = %d, %d\n", augend, addend);
    result = adder_readSum(ADD_CFG);
    ofsign = adder_readOfsign(ADD_CFG);
    printf("disable result = %d\n", result);
    printf("disable ofsign = %d\n", ofsign);

    printf("\n\n\n########## Test case 6 ##########\n\n\n");
    adder_enable(ADD_CFG);
    result = adder_readSum(ADD_CFG);
    ofsign = adder_readOfsign(ADD_CFG);
    printf("enable result = %d\n", result);
    printf("enable ofsign = %d\n", ofsign);

    return 0;

}
