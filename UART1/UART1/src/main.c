#include <avr/io.h>
#include <util/delay.h>
#include "LCD4.h"
#include "UART.h"




int main(void)
{
	UART_INIT();
	while (1)
	{
		
		char str []= {"UART Initialized"};
		
		uart_strtx(str);
		
	}
}