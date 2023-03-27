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
    uint32_t augend = 0x1111;
    uint32_t addend = 0x2222;
    uint32_t sum;
    printf("Hello World From RISC-V Processor!\n");


    adder_config(ADD_CFG,augend,addend);


    // adder_start(ADD_CFG);

    int result = adder_sum(ADD_CFG);
    /*int errors = 0;*/

    printf("%d\n",result);
   
    return 0;

}
