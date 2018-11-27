/** UART.h
 * UART driver. Mainly for communication with PuTTY.
 * @authors Sijin Woo
 * @lastRevised 10/2/2018
 */

#ifndef UART_H__
#define UART_H__

#include <stdint.h>
#include "stm32f4xx.h"
#include "FIFO.h"
#include "Definition.h"

/***** Unlike SPI, UART cannot have multiple modules connected to the same tx/rx line *****/
// ONLY USE UART3 FOR DEBUGGING ON NUCLEO!!!!

/** Pins:
 * UART1:
 *		tx : PA9
 *		rx : PA10
 * UART3:		*** NOTE: Nucleo Board uses these pins for USB ***
 *		tx : PD8
 *		rx : PD9
 */

/** UART1_Init
 * Initializes UART1 Module.
 * Pins: 
 *		tx : PA9
 *		rx : PA10
 * @param baud rate: 9600, 115200, 500000, etc.
 */
void UART1_Init(uint32_t baud);

/** UART1_Write
 * Sends data through tx pin (PA9) for UART1.
 * @param txBuf buffer to send on tx pin.
 * @param txSize size of message to send.
 */
void UART1_Write(char *txBuf, uint32_t txSize);

/** UART1_Read
 * Reads data from rx pin (PA10) for UART1.
 * This is a nonblocking statement. Uses interrupt and software FIFO.
 * Whenever there is nothing more to pop from the FIFO buffer,
 *		remaining elements of rxBuf will contain 0.
 * @param rxBuf buffer that will hold data recevied.
 * @param rxSize size of message to read.
 */
void UART1_Read(char *rxBuf, uint32_t rxSize);

/** UART3_Init
 * Initializes UART3 Module.
 * This UART3 module is connected to the micro-USB port on the 144-Nucleo.
 * Pins: 
 *		tx : PD8
 *		rx : PD9
 * @param baud rate: 9600, 115200, 500000
 */
void UART3_Init(uint32_t baud);

/** UART1_Write
 * Sends data through tx pin (PD8) for UART3.
 * @param txBuf buffer to send on tx pin.
 * @param txSize size of message to send.
 */
void UART3_Write(char *txBuf, uint32_t txSize);

/** UART1_Read
 * Reads data from rx pin (PD9) for UART3.
 * This is a blocking statement. Use UART1 for nonblocking statment.
 * If nothing is ever received, this function will spin indefinitely.
 * @param rxBuf buffer that will hold data recevied.
 * @param rxSize size of message to read.
 */
void UART3_Read(char *rxBuf, uint32_t rxSize);

#endif
