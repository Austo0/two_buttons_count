/*
 *  two_buttons_count.c
 *
 * Resets the count when the first switch is pressed,
 * and increses the count by one when the second button
 * is pressed.
 *
 *  Author: M. J. Cree
 *	Edited: Austen Fogarty
 */

#include <avr/io.h>
#include <util/delay.h>

int switch1;
int switch2;
/*
 * delay_ms(delay_in_ms)
 *
 * Delay the specified number of milliseconds.
 *
 * _delay_ms uses a floating point datatype if you call
 * that function in many places in your code then it becomes
 * very fat. An integer is enough for us.
 *
 */
void delay_ms(unsigned int xms)
{
	while (xms) {
		_delay_ms(0.96);
		xms--;
	}
}


/*
 * init_ports()
 *
 * Initialise the ports we will use --- in this case the lowest
 * six bits of PORTB are set to be outputs.
 */
void init_ports(void)
{
	/* Make bits 0 to 6 of PORTB outputs */
	DDRB = 0x03C;
	/* Set outputs to low voltage. */
	PORTB = 0;
}


/*
 * illuminate_leds(leds)
 *
 * Illuminate the LEDs connected to the bits
 * of Port B according to input leds.
 */
void illuminate_leds(int leds)
{
	PORTB = leds & 0x03f;
}


void main(void)
{
	int count = 0;
	int LED = 0x00;
	/* Initialise I/O Ports for use. */
	init_ports();
	/* Do forever... */
	while (1) {

		if ((PINB & 0x01)== 0x1) {			/* If switch 1 is pressed then */
			count = 0;						/* Reset the count */
			LED = count << 2;				/* Shift the count to align the LEDS */
		}

		if ((PINB & 0x02)== 0x2) {			/* If switch 2 is pressed then */


			while((PINB & 0x02) == 0x2)		/* Loop until the button is released*/
			{
				delay_ms(10);
			}

			if (count > 32){  				/* If the maximum count has been reached */
				count = 0;					/* Reset the count */
			}

			else {
				count++;					/* Increase the count by 1 */
			}
			LED = count << 2;				/* Shift the count to align the LEDS */
		}

		illuminate_leds(LED);  /* Turn on the the LEDS according to the counted number */
	}
}




