#include <msp430.h>

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer

    P1OUT &= ~BIT0;                         // Clear P1.0 output latch for a defined power-on state
    P1DIR |= BIT0;                          // Set P1.0 to output direction

    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings

    TB0CTL = TBSSEL_1 | ID_2 | MC_2;
    TB0CCR0 = 16000;

    while(1) {
        if(TB0R > TB0CCR0){
            P1OUT |= BIT0;
        } else{
            P1OUT &= ~BIT0;
        }
    }
}
