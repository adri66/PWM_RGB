/*
 * pwn_rgb.cpp
 *
 * Created: 5/11/2014 20:34:15
 *  Author: Adrien
 */ 

#define  RED 3
#define	 GREEN 5
#define  BLUE 11
#define delay 10
#define  F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
bool pwm(int duty_cicle, int arduino_pin)
{
	switch(arduino_pin)
	{
		case 3:
			OCR2B = (duty_cicle*255)/100;
			DDRD |= _BV(PIND3);
			TCCR2A |= (_BV(COM2B1)|_BV(COM2B0));
			TCCR2A |= (_BV(WGM00)|_BV(WGM01)); //Fast PWM mode
			TCCR2B &= ~_BV(WGM02);
			TCCR2B = (TCCR2B&~(_BV(CS21)|_BV(CS22)))|_BV(CS20); //Fpwm = 62.5Khz
		break;
		case 5:
			OCR0B = (duty_cicle*255)/100;
			DDRD |= _BV(PIND5);
			TCCR0A |= (_BV(COM0B1)|_BV(COM0B0));
			TCCR0A |= (_BV(WGM00)|_BV(WGM01)); //Fast PWM mode
			TCCR0B &= ~_BV(WGM02);
			TCCR0B = (TCCR0B&~(_BV(CS01)|_BV(CS02)))|_BV(CS00); //Fpwm = 62.5Khz
		break;
		case 6:
			OCR0A = (duty_cicle*255)/100;
			DDRD |= _BV(PIND6);
			TCCR0A |= (_BV(COM0A1|_BV(COM0A0)));
			TCCR0A |= (_BV(WGM00)|_BV(WGM01)); //Fast PWM mode
			TCCR0B &= ~_BV(WGM02);
			TCCR0B = (TCCR0B&~(_BV(CS01)|_BV(CS02)))|_BV(CS00); //Fpwm = 62.5Khz
			break;
		case 11:
			OCR2A = (duty_cicle*255)/100;
			DDRB |= _BV(PINB3);
			TCCR2A |= (_BV(COM2A1)|_BV(COM2A0));
			TCCR2A |= (_BV(WGM20)|_BV(WGM21)); //Fast PWM mode
			TCCR2B &= ~_BV(WGM22);
			TCCR2B = (TCCR2B&~(_BV(CS21)|_BV(CS22)))|_BV(CS20); //Fpwm = 62.5Khz
			break;
		default:
			return false;
	}
	
}
int main(void)
{
	int r = 0, g = 0, b = 0;
    while(1)
    {
		if(r==0)
		{
			for (r=0; r<= 100 ; r++)
			{
				pwm(100-r, RED);
				pwm(100-g, GREEN);
				pwm(100-b, BLUE);
				_delay_ms(delay);
			}
		}
		r=100;
		for (b=0; b<= 100 ; b++)
		{
			pwm(100-r, RED);
			pwm(100-g, GREEN);
			pwm(100-b, BLUE);
			_delay_ms(delay);
		}
		b=100;
		for (r=100; r >= 0 ; r--)
		{
			pwm(100-r, RED);
			pwm(100-g, GREEN);
			pwm(100-b, BLUE);
			_delay_ms(delay);
		}
		r=0;
		for (g=0; g<= 100 ; g++)
		{
			pwm(100-r, RED);
			pwm(100-g, GREEN);
			pwm(100-b, BLUE);
			_delay_ms(delay);
		}
		g=100;
		for (b=100; b>= 0 ; b--)
		{
			pwm(100-r, RED);
			pwm(100-g, GREEN);
			pwm(100-b, BLUE);
			_delay_ms(delay);
		}
		b=0;
		for (r=0; r<= 100 ; r++)
		{
			pwm(100-r, RED);
			pwm(100-g, GREEN);
			pwm(100-b, BLUE);
			_delay_ms(delay);
		}
		r=100;
		for (g=100; g >= 0 ; g--)
		{
			pwm(100-r, RED);
			pwm(100-g, GREEN);
			pwm(100-b, BLUE);
			_delay_ms(delay);
		}
		g=0;
    }
}