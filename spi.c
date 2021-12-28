/*
 * spi.c
 *
 *  Created on: Dec. 13, 2021
 *      Author: seli
 */

#include "spi.h"

uint8_t spi_init(void){

    //The recommended eUSCI initialization or reconfiguration process is:
    //1. Set UCSWRST.
        UCA0CTLW0 = UCSWRST;
    //2. Initialize all eUSCI registers while UCSWRST = 1 (including UCxCTL1).
        UCA0CTLW0 |= UCSSEL__SMCLK + UCSYNC + UCMST + UCCKPL + UCCKPH;
    //3. Configure ports.
        P1SEL0 |= 0xE0;
        P1SEL1 &= ~(0xE0);
    //4. Clear UCSWRST in software.
        UCA0CTLW0 &= ~(UCSWRST);

    //BIC.B #UCSWRST,&UCxCTL1
    //5. Enable interrupts (optional) by setting UCRXIE or UCTXIE.
        //UCA0IE = UCTXIE + UCRXIE;

        return 1;
}

void spi_write(uint8_t * message, uint8_t num_bytes){
    int i = 0;
    for(i = 0; i < num_bytes; i++)
    {

        UCA0TXBUF = *message;
        while(!(UCA0IFG & UCTXIFG));
        message++;
    }

}

uint8_t spi_read(uint8_t address, uint8_t num_bytes){
    int i = 0;
    uint8_t spi_byte;

        UCA0TXBUF = address;
        while(!(UCA0IFG & UCTXIFG));
        UCA0TXBUF = 0x00;
        while(!(UCA0IFG & UCTXIFG));
        spi_byte = UCA0RXBUF_L;


    return spi_byte;
}
