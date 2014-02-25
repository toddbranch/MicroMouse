/*
 * motor.h
 *
 * Simple library to drive DC motors using the msp430g2553.
 *
 * The positive terminal of the right motor should be connected to P1.2.  The
 * negative terminal of the right motor should be connected to P1.1.
 *
 * The positive terminal of the left motor should be connected to P2.1.  The
 * negative terminal of the left motor should be connected to P2.0.
 *
 * This code can move the motors forward at any speed (currently configured for
 * 60% duty cycle), but can only move them backward  at 50% speed.  This is due
 * to using TA0.0, which is limited by hardware to 50%.  This limitation could
 * be overcome by rewriting the code to generate PWM using GPIO and timers.
 */


// Individual Motor Commands
void initLeftMotor();
void moveLeftMotorForward();
void moveLeftMotorBackward();

void initRightMotor();
void moveRightMotorForward();
void moveRightMotorBackward();

// Combination Motor Commands
void initMotors();
void moveForward();
void moveBackward();
void turnLeft();
void turnRight();
