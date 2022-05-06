#ifndef __UART_H_
#define __UART_H_

#include <avr/io.h>
#include <util/delay.h>


#define FOSC 1000000UL // Clock
#define BAUD 9600 //Baud rate


void UART_INIT ();
void uart_t (uint8_t );
uint8_t uart_r ();
void uart_strtx (char* );




#endif