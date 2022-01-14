/*
 * Elevator Assignment.c
 *
 * Created: 1/27/2021 10:15:16 PM
 * Author : Khaled
 */ 
#include <avr/io.h>
#include <util/delay.h>


void delayms (void)
{
	unsigned int i;
	for (i=0; i<42150; i++);
}
int main(void)
{
	PORTD = 0x4F;
	PORTB = 0x06;
	while(1)
	{
		if(PINA == 0b10000000)
		{
			PORTB = 0x79;
			delayms();
			
		}
		if(PINA == 0b10000000)
		{
			PORTD = 0x79;
			delayms();
			
		}
		while (PORTB == 0x06)//1
		{
			if(PINA == 0b10000000)
			{
				PORTB = 0x79;
				delayms();
				
			}
			if(PINA == 0b10000000)
			{
				PORTD = 0x79;
				delayms();
				
			}
			
			if(PINA == 0b00000001)
			{
				PORTB = 0x06;
				delayms();
				
			}
			if(PINA == 0b00000010)
			{
				
				PORTB = 0x5B;
				delayms();
				
			}
			if (PINA == 0b00000100)
			{
				
				PORTB = 0x5B;
				delayms();
				PORTB = 0x4F;
				delayms();
				
				
			}
			if(PINA == 0b00001000)
			{
				
				PORTB = 0x5B;
				delayms();
				PORTB = 0x4F;
				delayms();
				PORTB = 0x66;
				delayms();
				
			}
			if(PINA == 0b00010000)
			{
				
				PORTB = 0x5B;
				delayms();
				PORTB = 0x4F;
				delayms();
				PORTB = 0x66;
				delayms();
				PORTB = 0x6D;
				delayms();
				
				
			}
			
			if(PINA == 0b01000000)
			{
				
				
				PORTD = 0x4F;
				delayms();
				PORTD = 0x66;
				delayms();
				PORTD = 0x6D;
				delayms();
				
			}
		}
		
		
		
		
		while (PORTB == 0x5B)  //2
		{
			if(PINA == 0b10000000)
			{
				PORTB = 0x79;
				delayms();
				
			}
			if(PINA == 0b10000000)
			{
				PORTD = 0x79;
				delayms();
				
			}
			if(PINA == 0b00000001)
			{
				
				PORTB = 0x06;
				delayms();
				
			}
			else if(PINA == 0b00000010)
			{
				
				PORTB = 0x5B;
				delayms();
				
			}
			else if(PINA ==  0b00000100)
			{
				
				
				PORTB = 0x4F;
				delayms();
				
				
			}
			else if(PINA ==  0b00001000)
			{
				
				
				PORTB = 0x4F;
				delayms();
				PORTB = 0x66;
				delayms();
				
			}
			else if(PINA == 0b00010000)
			{
				
				
				PORTB = 0x4F;
				delayms();
				PORTB = 0x66;
				delayms();
				PORTB = 0x6D;
				delayms();
				
				
			}
			else if(PINA == 0b00100000)
			{
				
				
				PORTB = 0x5B;
				delayms();
				PORTB = 0x06;
				delayms();
				
				
			}
			else if(PINA == 0b01000000)
			{
				
				
				
				PORTD = 0x66;
				delayms();
				PORTD = 0x6D;
				delayms();
				
				
			}
		}
		
		
		
		
		
		
		
		while (PORTB == 0x4F)  //3
		{
			if(PINA == 0b10000000)
			{
				PORTB = 0x79;
				delayms();
				
			}
			if(PINA == 0b10000000)
			{
				PORTD = 0x79;
				delayms();
				
			}
			
			if(PINA == 0b00000001)
			{
				
				PORTB = 0x5B;
				delayms();
				PORTB = 0x06;
				delayms();
				
			}
			else if(PINA == 0b00000010)
			{
				
				PORTB = 0x5B;
				delayms();
				
			}
			else if(PINA ==  0b00000100)
			{
				
				PORTB = 0x4F;
				delayms();
				
				
			}
			else if(PINA ==  0b00001000)
			{
				
				
				
				PORTB = 0x66;
				delayms();
				
			}
			else if(PINA == 0b00010000)
			{
				
				
				
				PORTB = 0x66;
				delayms();
				PORTB = 0x6D;
				delayms();
				
				
			}
		}
		
		
		
		
		
		while(PORTB == 0x66)  //4
		{
			if(PINA == 0b10000000)
			{
				PORTB = 0x79;
				delayms();
				
			}
			if(PINA == 0b10000000)
			{
				PORTD = 0x79;
				delayms();
				
			}
			
			if(PINA == 0b00000001)
			{
				
				PORTB = 0x4F;
				delayms();
				PORTB = 0x5B;
				delayms();
				PORTB = 0x06;
				delayms();
				
			}
			else if(PINA == 0b00000010)
			{
				
				PORTB = 0x4F;
				delayms();
				PORTB = 0x5B;
				delayms();
				
			}
			else if(PINA ==  0b00000100)
			{
				
				PORTB = 0x4F;
				delayms();
				
				
				
			}
			else if(PINA ==  0b00001000)
			{
				
				PORTB = 0x66;
				delayms();
				
			}
			else if(PINA == 0b00010000)
			{
				
				PORTB = 0x66;
				delayms();
				PORTB = 0x6D;
				delayms();
				
				
			}
			else if(PINA == 0b00100000)
			{
				
				
				PORTD = 0x5B;
				delayms();
				PORTD = 0x06;
				delayms();
				
				
				
			}
			else if(PINA == 0b01000000)
			{
				
				
				
				PORTB = 0x6D;
				delayms();
				
				
			}
		}
		while(PORTB == 0x6D)//5
		{
			if(PINA == 0b10000000)
			{
				PORTB = 0x79;
				delayms();
				
			}
			if(PINA == 0b10000000)
			{
				PORTD = 0x79;
				delayms();
				
			}
			if(PINA == 0b00000001)
			{
				PORTB = 0x66;
				delayms();
				PORTB = 0x4F;
				delayms();
				PORTB = 0x5B;
				delayms();
				PORTB = 0x06;
				delayms();
				
			}
			else if(PINA == 0b00000010)
			{
				PORTB = 0x66;
				delayms();
				PORTB = 0x4F;
				delayms();
				PORTB = 0x5B;
				delayms();
				
			}
			else if(PINA ==  0b00000100)
			{
				PORTB = 0x66;
				delayms();
				PORTB = 0x4F;
				delayms();
				
				
				
			}
			else if(PINA ==  0b00001000)
			{
				
				PORTB = 0x66;
				delayms();
				
			}
			else if(PINA == 0b00010000)
			{
				
				
				PORTB = 0x6D;
				delayms();
				
				
			}
			else if(PINA == 0b00100000)
			{
				
				
				
				
				PORTD = 0x5B;
				delayms();
				PORTD = 0x06;
				delayms();
				
			}
		}
	}
	
	
}


