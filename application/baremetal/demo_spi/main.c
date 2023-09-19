#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "hbird_sdk_soc.h"

#define SPI_DIV 1
#define SPI_ID SPI1

int32_t spi_irq_base_handler(SPI_TypeDef *spi){
    if (__RARELY(spi == NULL)) {
        return -1;
    }
    printf("\r\nSPI IRQ TRIGGER!\r\n");
    spi_disable_interrupt(SPI_ID);
    printf("\r\nSPI IRQ CLEAR!\r\n");
    return 0;
}

int main(void)
{

    printf("\r\n###########Begin Test!!!###########\r\n");

    uint32_t data[2] = {0x12345678, 0x87654321};
    
    PLIC_Register_IRQ(PLIC_QSPI1_IRQn, 1, spi_irq_base_handler);  
    __enable_irq();

    spi_setup_clk(SPI_ID, SPI_DIV);
    spi_set_datalen(SPI_ID, 64);
    spi_set_tx_th(SPI_ID, 1);
    spi_set_rx_th(SPI_ID, 32);
    spi_write_fifo(SPI_ID, data, 64);
    spi_enable_interrupt(SPI_ID);
    spi_start_transaction(SPI_ID, SPI_CMD_WR, SPI_CSN1);
    return 0;

}
