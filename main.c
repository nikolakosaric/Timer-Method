#include <msp430.h> 

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	P1OUT &= ~BIT0;                         // Clear P1.0 output latch for a defined power-on state
	P1DIR |= BIT0;                          // Set P1.0 to output direction

	TA0CTL = TASSEL_1 | ID_2 | MC_2;
	TA0CCR0 = 16000;

	while(1) {
	    if(TA0R > TA0CCR0){
	        P1OUT |= BIT0;
	    } else{
	        P1OUT &= ~BIT0;
	    }
	}
}
