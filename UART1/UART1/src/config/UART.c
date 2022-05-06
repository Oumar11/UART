#ifndef __UART_C_
#define __UART_C_

#include <avr/io.h>
#include <util/delay.h>



void UART_INIT ()
{
	UBRRL = (uint8_t)(userUBRR); // first byte in LOW
	UBRRH = (uint8_t)(userUBRR >> 8); // shifting higher bits to lower bits..and setting them in HIGH

	UCSRB |= (1<<4)|(1<<3); // Enables Tx & Rx
	UCSRC |= (1<<2)|(1<<1); // 8-bit , 1 stop bit , no parity , Asynch mode.
	
}
void uart_t (uint8_t data)
{
	while (!(UCSRA & (1<<5) ) ) ;
	UDR = data;
}
uint8_t uart_r ()
{
	while (!(UCSRA & (1<<7) ) ) ;
	return UDR ;

}
void uart_strtx (char* str)
{	
	unsigned char i = 0;

	uart_t(sizeof (str)/sizeof (char));
	while (str[i]!=0)
		{
		uart_t(str[i]);
		i++;
	}
}
#endif
