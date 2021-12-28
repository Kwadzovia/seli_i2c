/*
 * spi.h
 *
 *  Created on: Dec. 13, 2021
 *      Author: seli
 */

#ifndef SPI_H_
#define SPI_H_

#include <msp430.h>
#include <stdint.h>

uint8_t spi_init(void);
void spi_write(uint8_t * message,uint8_t num_bytes);
uint8_t spi_read(uint8_t message, uint8_t num_bytes);

#endif /* SPI_H_ */
