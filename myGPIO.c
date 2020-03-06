/*
 * GPIO.c
 *
 *  Created on: 3/5
 *      Author: Pedro Do Nascimento
 */

// For the code you place here, you may use your code that uses register references.
// However, I encourage you to start using the Driver Library as soon as possible.
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "myGPIO.h"

#define B1 BIT1
#define B2 BIT4

#define S1 BIT5 //pin 3 bit 5
#define S2 BIT1 //pin 5 bit 1

#define LED1 BIT0

//right multicolored LED
#define LED2_R BIT0 //pin 2 bit 0
#define LED2_G BIT1 //pin 2 bit 1
#define LED2_B BIT2 //pin 2 bit 2

//booster pack LEDS
#define BLED_R BIT6 //pin 2 bit 6
#define BLED_G BIT4 //pin 2 bit 4
#define BLED_B BIT6 //pin 5 bit 6

// When a button is pressed, it is grounded (logic 0)
#define PRESSED 0

// TODO: Create a function to initialize the GPIO.
// Even though this assignment does not use all of the pushbuttons, you should write one function that does a complete GPIO init.
void initGPIO()
{
    P1DIR |= LED1;  // Same as P1DIR = P1DIR | LED1;
    P2DIR |= (LED2_R | LED2_G | LED2_B | BLED_R | BLED_G );
    P5DIR |= BLED_B;

    P1DIR &= ~B1;
    P1REN |= B1;
    P1OUT |= B1;
    P1DIR &= ~B2;
    P1REN |= B2;
    P1OUT |= B2;
    P1DIR &= ~S1;
    P1REN |= S1;
    P1OUT |= S1;
    P1DIR &= ~S2;
    P1REN |= S2;
    P1OUT |= S2;
    // Turn off all LEDs at the start.
    P1OUT = P1OUT & ~LED1;
    P2OUT = P2OUT & ~LED2_R;

    P2OUT = P2OUT & ~LED2_G;

    P2OUT = P2OUT & ~LED2_B;

    P2OUT = P2OUT & ~BLED_R;

    P2OUT = P2OUT & ~BLED_G;

    P5OUT = P5OUT & ~BLED_B;

}

void TurnOn_Launchpad_LED1()
{
    P1OUT = P1OUT | LED1;
}

void TurnOn_Launchpad_LED2_R()
{
    P2OUT = P2OUT | LED2_R;
}

void TurnOn_Launchpad_LED2_G()
{
    P2OUT = P2OUT | LED2_G;
}

void TurnOn_Launchpad_LED2_B()
{
    P2OUT = P2OUT | LED2_B;
}

void TurnOn_Boosterpack_BLED_R()
{
    P2OUT = P2OUT | BLED_R;
}

void TurnOn_Boosterpack_BLED_G()
{
    P2OUT = P2OUT | BLED_G;

}

void TurnOn_Boosterpack_BLED_B()
{
    P5OUT = P5OUT | BLED_B;

}

void TurnOff_Launchpad_LED1()
{
    P1OUT = P1OUT & ~LED1;
}

void TurnOff_Launchpad_LED2_R()
{
    P2OUT = P2OUT & ~LED2_R;
}

void TurnOff_Launchpad_LED2_G()
{
    P2OUT = P2OUT & ~LED2_G;
}

void TurnOff_Launchpad_LED2_B()
{
    P2OUT = P2OUT & ~LED2_B;
}

void TurnOff_Boosterpack_BLED_R()
{
    P2OUT = P2OUT & ~BLED_R;
}

void TurnOff_Boosterpack_BLED_G()
{
    P2OUT = P2OUT & ~BLED_G;
}

void TurnOff_Boosterpack_BLED_B()
{
    P5OUT = P5OUT & ~BLED_B;
}

char SwitchStatus_Launchpad_Button1()
{
    return (P1IN & B1 );
}

char SwitchStatus_Launchpad_Button2()
{
    return (P1IN & B2 );
}

char SwitchStatus_Boosterpack_Switch1()
{
    return (P3IN & S1 );
}

char SwitchStatus_Boosterpack_Switch2()
{
    return (P5IN & S2 );
}

bool Button1_IsPressed()
{
    return (SwitchStatus_Launchpad_Button1() == PRESSED);
}

bool Button2_IsPressed()
{
    return (SwitchStatus_Launchpad_Button2() == PRESSED);
}

bool Switch1_IsPressed()
{
    return (SwitchStatus_Boosterpack_Switch1() == PRESSED);

}

bool Switch2_IsPressed()
{
    return (SwitchStatus_Boosterpack_Switch2() == PRESSED);

}
