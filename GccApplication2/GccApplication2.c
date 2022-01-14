#include <avr/io.h>
#include <avr/interrupt.h> 
//#define F_CPU 1000000
//#include <util/delay.h>

void config(void);
int up_down(void);
uint8_t choose_higher(void);
uint8_t choose_lower(void);
void go_to(uint8_t elevator, uint8_t level);
uint8_t binary2segment(uint8_t binary);
void levels(void);
void omg(void);

volatile uint8_t direction;
volatile uint8_t level2go;
volatile uint8_t usedelvator;
volatile uint8_t E[2] = {1, 1};


 
int main(void)
{
	
	config();
    while(1)
    {
		if(up_down())
		{
			levels();
		}
	}
}


void config(void)
{
	//set portD as input
	DDRD = 0;
	//PORTD = 0Xff;
	//set portB and portD as output
	DDRB = 0Xff;
	DDRA = 0Xff;
	DDRC = 0xff;
	
	//elevator 1 and 2 start at level 1
	PORTB = 0b00000110;
	PORTA = 0b00000110;
	PORTC = 0b00000000;

	GICR =  (1 << INT0);
	MCUCR = (1<< ISC01) | (1<< ISC00); 
	sei();
	//timer interrupt
//	TIMS//= 0b00000100;
//	sei();
//	TCNT//= 0x85EE;
//	TIFR// 0;
	
}

int up_down(void)
{
	direction = (PIND & 0b00000011); 
	switch(direction)
	{
		case 1: 
			go_to(usedelvator = choose_lower(), 1);
			return 1;
		case 2:	
			go_to(usedelvator = choose_higher(),5);
			return 1;
		default:
			return 0;	
	} 
}

uint8_t choose_higher(void)
{
	if(E[0] >= E[1])
		return 0;
	else
		return 1;
}

uint8_t choose_lower(void)
{
	if(E[0] <= E[1])
		return 0;
	else
		return 1;
}

void go_to(uint8_t elevator, uint8_t level)
{
	while(E[elevator] != level)
	{
		if(E[elevator] == 7)
		{
			return; 
		}
		
		if(E[elevator] > level)
		{
			E[elevator] --;
			if (elevator == 0)
				PORTB = binary2segment(E[elevator]); 
			else
				PORTA = binary2segment(E[elevator]); 
		}
		else if (E[elevator] < level)
		{
			E[elevator]++;
			if (elevator == 0) 
				PORTB = binary2segment(E[elevator]); 
			else 
				PORTA = binary2segment(E[elevator]);  
		}
	}
}

uint8_t binary2segment(uint8_t binary)
{
	switch(binary)
	{
		case 1:
			binary = 0b00000110;
			break;
		case 2:
			binary = 0b01011011;
			break;
		case 3:
			binary = 0b01001111;
			break; 
		case 4:
			binary = 0b01100110;
			break;
		case 5:
			binary = 0b01101101;
			break;
		default:
			binary = 0b01111001;
			break;	
	}
	return binary;
}

void levels(void)
{
	while(1)
	{
		if((PIND & 0b11111000) != 0)
		{
			level2go = ((PIND & 0b00001000) >> 3) + ((PIND & 0b00010000) >> 3) + ((PIND & 0b00100000) >> 5) * 3 + ((PIND & 0b01000000) >> 6) * 4 + ((PIND & 0b10000000) >> 7) * 5;
			go_to(usedelvator, level2go);
			return;
		}
	}	
	
}

ISR(INT0_vect)
{
	omg();
}

void omg(void)
{
	if(usedelvator)
		PORTC |= 0b11110000; 
	else
		PORTC |= 0b00001111; 
	E[usedelvator] = 7;
	return;
}