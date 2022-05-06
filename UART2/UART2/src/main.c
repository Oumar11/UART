#include <avr/io.h>
#include <util/delay.h>
#include "LCD4.h"
#include "UART.h"
#include <stdlib.h>

int main(void)
{
	lcd_intit();
	UART_INIT();
	
	while (1)
	{	
		char arr[16];
		unsigned char i = 0 ;
		while (i<16)
		{
			arr[i++]=uart_r();
			
		}
		lcd_goto(1,1);
		lcd_prnt(arr);
		
		
	}
}
