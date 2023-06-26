#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "hbird_sdk_soc.h"
#include "acc.h"

// #define AUGEND_OFFSET (0x0)
// #define ADDEND_OFFSET (0x00004)
// #define SUM_OFFSET    (0x00008)
// #define START_OFFSET  (0x0000a)


int main(void)
{

    // printf("###########Begin Test!!!###########\n\n\n");

    // int8_t input[32][96] = {8};
    // int8_t W[6][96][48] = {16};
    // int8_t qkv[6][32][48] = {0};
    // int8_t kT[2][48][32] = {0};
    // int8_t qkT[2][32][32] = {0};
    // int8_t res[2][32][48] = {0};

    // for (int i=0; i<32; i++){
    //     for (int j=0; j<96; j++){
    //         input[i][j] = i*j;
    //     }
    // }

    // for (int c=0; c<6; c++){
    //     for (int i=0; i<96; i++){
    //         for (int j=0; j<48; j++){
    //             W[c][i][j] = i*j;
    //         }
    //     }
    // }

    // for (int c=0; c<4; c++){
    //     for (int i=0; i<32; i++){
    //         for (int j=0; j<48; j++){
    //             for (int k=0; k<96; k++){
    //                 qkv[c][i][j] += input[i][k] * W[c][k][j];
    //             }
    //         }
    //     }
    // }
    
    // for (int c=0; c<2; c++){
    //     for (int i=0; i<32; i++){
    //         for (int j=0; j<48; j++){
    //             kT[c][i][j] = qkv[2*c][j][i];
    //         }
    //     }
    // }

    // for (int c=0; c<2; c++){
    //     for (int i=0; i<32; i++){
    //         for (int j=0; j<32; j++){
    //             for (int k=0; k<48; k++){
    //                 qkT[c][i][j] += qkv[c][i][k] * kT[c][k][j];
    //             }
    //         }
    //     }
    // }

    // for (int c=0; c<2; c++){
    //     for (int i=0; i<32; i++){
    //         for (int j=0; j<48; j++){
    //             for (int k=0; k<32; k++){
    //                 res[c][i][j] += qkT[c][i][k] * qkv[3*c][k][j];
    //             }
    //         }
    //     }
    // }

    int32_t a, b, c, temp;
    // int8_t tempchar;
    // int32_t data[6912];

    // for (int i=0; i<6912;i++) {
    //     data[i] = a ;
    // }
    // acc_LoadWeight(ACC_CFG, data);

    // acc_ConfigMode(ACC_CFG, 2, 1); // read from row
    // acc_CfgRWAddr(ACC_CFG, 0, 0);
    // for (int i=0; i<8; i++) {
    //     temp = acc_ReadSRAM(ACC_CFG, i);
    //     for (int j=0;j<4;j++){
    //         printf("%d\t", temp%256);
    //         temp = temp / 256;        
    //     }
    //     printf("\n");
    // }
    // acc_CfgRWAddr(ACC_CFG, 0, 6904);
    // for (int i=0; i<8; i++) {
    //     temp = acc_ReadSRAM(ACC_CFG, i);
    //     for (int j=0;j<4;j++){
    //         printf("%d\t", temp%256);
    //         temp = temp / 256;        
    //     }
    //     printf("\n");
    // }
    a = 0x01020304;
    b = 0x04030201;
    c = 0x01000101;
    acc_ConfigMode(ACC_CFG, 1, 0); // write to row
    for (int i=0; i<128; i++) {
        acc_WriteSRAM(ACC_CFG, i, a);
    }
    acc_CfgRWAddr(ACC_CFG, 128, 0);
    for (int i=0; i<128; i++) {
        acc_WriteSRAM(ACC_CFG, i, a);
    }
    acc_ConfigMode(ACC_CFG, 1, 1); // write to col
    for (int i=0; i<128; i++) {
        acc_WriteSRAM(ACC_CFG, i, b);
    }
    acc_CfgRWAddr(ACC_CFG, 0, 128);
    for (int i=0; i<128; i++) {
        acc_WriteSRAM(ACC_CFG, i, b);
    }
    int rs = 2, cs = 2;
    acc_ConfigCalc(ACC_CFG, 0, 0, 8, rs, cs); // row out to row SRAM, 32x64 64x32
    acc_CfgCalcAddr(ACC_CFG, 0, 0, 256);

    acc_StartCalc(ACC_CFG);
    acc_WaitCalc(ACC_CFG);

    acc_ConfigMode(ACC_CFG, 2, 0); // read from row
    acc_CfgRWAddr(ACC_CFG, 256, 0);
    for (int i=0; i<32; i++) {
        temp = acc_ReadSRAM(ACC_CFG, i);
        for (int j=0;j<4;j++){
            printf("%d\t", temp%256);
            temp = temp / 256;        
        }
        printf("\n");
    }
    // acc_CfgRWAddr(ACC_CFG, 384, 0);
    // for (int i=0; i<128; i++) {
    //     temp = acc_ReadSRAM(ACC_CFG, i);
    //     for (int j=0;j<4;j++){
    //         //printf("%d\t", temp%256);
    //         temp = temp / 256;        
    //     }
    //     //printf("\n");
    // }


    // a = 0x01010101;
    // acc_CfgRWAddr(ACC_CFG, 0, 0);
    // acc_ConfigMode(ACC_CFG, 1, 0);
    // for (int i=0; i<32; i++) {
    //     acc_WriteSRAM(ACC_CFG, i, i);
    // }
    // a = 0x02020202;
    // acc_CfgRWAddr(ACC_CFG, 32, 0);
    // for (int i=0; i<32; i++) {
    //     acc_WriteSRAM(ACC_CFG, i, i*2);
    // }

    // acc_CfgRWAddr(ACC_CFG, 32, 0);
    // acc_ConfigMode(ACC_CFG, 2, 0);
    // for (int i=0; i<32; i++) {
    //     printf("%d\n", acc_ReadSRAM(ACC_CFG, i));
    // }

    // acc_CfgRWAddr(ACC_CFG, 0, 0);
    // for (int i=0; i<32; i++) {
    //     printf("%d\n", acc_ReadSRAM(ACC_CFG, i));
    // }

    // acc_WriteSRAM(ACC_CFG, 12, 12);
    // acc_WriteSRAM(ACC_CFG, 24, 36);
    // acc_ConfigMode(ACC_CFG, 1, 1);
    // acc_WriteSRAM(ACC_CFG, 24, 24);

    // acc_ConfigMode(ACC_CFG, 2, 0);
    // a = acc_ReadSRAM(ACC_CFG, 12);
    // printf("%d\n", a);
    // a = acc_ReadSRAM(ACC_CFG, 24);
    // printf("%d\n", a);
    // acc_ConfigMode(ACC_CFG, 2, 1);
    // b = acc_ReadSRAM(ACC_CFG, 24);
    // printf("%d\n", b);

    printf("###########Finish!!!###########\n");

    return 0;

}
