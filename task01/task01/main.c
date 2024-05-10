/*
 * 5-6.c
 *
 * Created: 4/27/2024 12:07:00 AM
 * Author : acer
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define segment PC0
#define switchSeg PD0

#define pushbutton1 PD2
#define pushbutton2 PD3

char num[]={0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00000111,0b11111111,0b11101111};


void setup(){
		
	
	
	EIMSK |=(1<<INT0)|(1<<INT1);
	
	EICRA |=(1<<ISC01)|(1<<ISC11);//Isc11 -Int1 pin faling edge trigger
	
	sei();
	
	
	
}
ISR(INT0_vect){



}	

int main(void)
{	
	DDRC = 0xff;
	DDRD &=~(1<<pushbutton1)&(1<<pushbutton2);
	
	
	
	DDRD |=(1<<PD4);
	
	DDRB = 0xff;
	setup();
	float b=18.56;
	
    /* Replace with your application code */
    while (1) 
    {
		if (b<10)
		{
			int givenNumber =b*1000;
			int decimalPart = givenNumber % 1000;
			
			PORTB = 0b00000001;
			PORTC = num[givenNumber/1000 %10];
			_delay_ms(66.67);
			PORTD =0b00010000;
			_delay_ms(66.67);
			PORTB = 0b00000000;
			_delay_ms(66.67);
			
			PORTB = 0b00000010;
			PORTC = num[decimalPart/100 %10];
			_delay_ms(200);
			PORTB = 0b00000100;
			PORTC = num[decimalPart/10 %10];
			_delay_ms(200);
			PORTB = 0b00001000;
			PORTC = num[decimalPart/1 %10];
			_delay_ms(200);
			
			
			
			
		}
		else if (b<100 )
		{
			int givenNumber =b*100;
			int decimalPart = givenNumber % 100;
			
			PORTB = 0b00000001;
			PORTC = num[givenNumber/1000 %10];
			_delay_ms(200);
			
			PORTB = 0b00000010;
			PORTC = num[givenNumber/100 %10];
			_delay_ms(66.67);
			PORTD =0b00010000;
			_delay_ms(66.67);
			PORTD = 0b00000000;
			_delay_ms(66.67);
			
			PORTB = 0b00000100;
			PORTC = num[decimalPart/10 %10];
			_delay_ms(200);
			PORTB = 0b00001000;
			PORTC = num[decimalPart/1 %10];
			_delay_ms(200);
			
		}
		
		else if (b<1000)
		{
			int givenNumber =b*10;
			int decimalPart = givenNumber % 10;
			
			PORTB = 0b00000001;
			PORTC = num[givenNumber/1000 %10];
			_delay_ms(200);
			
			PORTB = 0b00000010;
			PORTC = num[givenNumber/100 %10];
			_delay_ms(200);
			
			PORTB = 0b00000100;
			PORTC = num[givenNumber/10 %10];
			_delay_ms(66.67);
			PORTB =0b00010000;
			_delay_ms(66.67);
			//PORTB = 0b00000000;
			_delay_ms(66.67);
			
			PORTB = 0b00001000;
			PORTC = num[decimalPart/1 %10];
			_delay_ms(200);
			
			
			
			
		}
		
		
		else {
			int givenNumber =b;
			PORTB = 0b00000001;
			PORTC = num[givenNumber/1000 %10];
			_delay_ms(200);
			PORTB = 0b00000010;
			PORTC = num[givenNumber/100 %10];
			_delay_ms(200);
			PORTB = 0b00000100;
			PORTC = num[givenNumber/10 %10];
			_delay_ms(200);
			PORTB = 0b00001000;
			PORTC = num[givenNumber/1 %10];
			_delay_ms(200);
		}
		
    }
}

