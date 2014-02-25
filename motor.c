#include "motor.h"
#include <msp430g2553.h>

void initRightMotor()
{
	TA0CTL &= ~(MC1|MC0);				// stop timer
	TA0CTL |= TASSEL1;					// select SMCLK
	TA0CTL |= TACLR;

	P1DIR |= BIT1;
	P1SEL |= BIT1;

  P1DIR |= BIT2;
	P1SEL |= BIT2;

	TA0CCR0 = 100;						// period is 100
  TA0CCR1 = 0;

	TA0CCTL0 |= OUTMOD2|OUTMOD0;     // set both to reset mode
	TA0CCTL1 |= OUTMOD2|OUTMOD0;

	TA0CTL |= MC0;						// turn counter on
}

void initLeftMotor()
{
	TA1CTL &= ~(MC1|MC0);				// stop timer
	TA1CTL |= TASSEL1;					// select SMCLK
	TA1CTL |= TACLR;

	P2DIR |= BIT0;
	P2SEL |= BIT0;

  P2DIR |= BIT1;
	P2SEL |= BIT1;

	TA1CCR0 = 100;						// period is 100
  TA1CCR1 = 0;

	TA1CCTL0 |= OUTMOD2|OUTMOD0;     // set both to reset mode
	TA1CCTL1 |= OUTMOD2|OUTMOD0;

	TA1CTL |= MC0;						// turn counter on
}

void moveRightMotorForward()
{
	TA0CCTL0 |= OUTMOD2|OUTMOD0;
	__delay_cycles(10000);				// wait for it to be reset - huge margin here
	TA0CCR1 = 60;
	TA0CCTL1 |= OUTMOD2|OUTMOD1|OUTMOD0;	// reset / set mode
}

void moveRightMotorBackward()
{
	TA0CCR1 = 0;
	__delay_cycles(10000);				// wait for it to be reset - huge margin here
	TA0CCTL0 &= ~OUTMOD0;
}

void moveLeftMotorForward()
{
	TA1CCTL0 |= OUTMOD2|OUTMOD0;
	__delay_cycles(10000);				// wait for it to be reset - huge margin here
	TA1CCR1 = 60;
	TA1CCTL1 |= OUTMOD2|OUTMOD1|OUTMOD0;	// reset / set mode
}

void moveLeftMotorBackward()
{
	TA1CCR1 = 0;
	__delay_cycles(10000);				// wait for it to be reset - huge margin here
	TA1CCTL0 &= ~OUTMOD0;
}

void initMotors()
{
  initRightMotor();
  initLeftMotor();
}

void moveForward()
{
  moveRightMotorForward();
  moveLeftMotorForward();
}

void moveBackward()
{
  moveRightMotorBackward();
  moveLeftMotorBackward();
}

void turnLeft()
{
  moveLeftMotorBackward();
  moveRightMotorForward();
}

void turnRight()
{
  moveRightMotorBackward();
  moveLeftMotorForward();
}
