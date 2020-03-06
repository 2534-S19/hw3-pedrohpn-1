/*
 * myTimer.c
 *
 *  Created on: 03/05/2020
 *      Author: Pedro Do Nascimento
 */

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "myTimer.h"

// TODO: Write a function that can intialize a Timer with particular values for pre-scale and count.
// Aliases for the Timers and the preScaler arguments are defined in myTimer.h
void initTimer(unsigned int timer, unsigned int preScaler, unsigned int count)
{
    // For the specified timer and pre-scale value, put the timer in 32-bit periodic mode.
    Timer32_initModule(timer, preScaler, MAX_VALUE, 1/(3000000));
    // For the specified timer, pass the count value.
    Timer32_setCount(timer, count);

    // For the specified timer, configure the timer to repeat once it elapses.
    if (timer == TIMER0){
        Timer32_startTimer(timer, timer1Expired());
    }
    else{
        Timer32_startTimer(timer, timer0Expired());
    }
}

// TODO: Write a function that indicates whether Timer0 has expired.
// You have been given a such a function in the lecture slides.
bool timer0Expired(void)
{
    static unsigned int previousSnap = 0;
    unsigned int currentSnap;
    bool returnValue;

    currentSnap = Timer32_getValue(TIMER0);
    returnValue = (currentSnap > previousSnap);
    previousSnap = currentSnap;
    return returnValue;
}

// TODO: Write a function that indicates whether Timer1 has expired.
// This is essentially a copy of the previous function, using a different timer.
// Since we only have two timers, later in the course we will create software timers that use a common time base.
bool timer1Expired(void)
{
    static unsigned int previousSnap = 0;
    unsigned int currentSnap;
    bool returnValue;

    currentSnap = Timer32_getValue(TIMER1);
    returnValue = (currentSnap > previousSnap);
    previousSnap = currentSnap;
    return returnValue;
}
