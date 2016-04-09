#include <project.h>
#include "cyapicallbacks.h"

int main()
{
    CyGlobalIntEnable;

    isr_Tx_Start();
    SPI_Start();

    CyDelay(2500);
    
    for(;;)
    {
        
        CyDelayUs(50);
        SPI_WriteTxData(0xDEUL);
        SPI_WriteTxData(0xADUL);
        SPI_WriteTxData(0xC0UL);
        SPI_WriteTxData(0xDEUL);
        SPI_ClearRxBuffer();

    }
}

void isr_Tx_Interrupt_InterruptCallback(void){
    SPI_TX_STATUS_REG;
}

/* [] END OF FILE */
