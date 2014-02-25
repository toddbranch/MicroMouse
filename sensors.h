/*
 * motor.h
 *
 * Simple library to retrieve readings from sensors via ADC.
 *
 * Call initSensors() to setup.  Calls to getXXXXSensorValue() are blocking -
 * they will poll for a result.  The Right/Center/Left sensors are connected to
 * INCH3/4/5 through P1.3/1.4/1.5.
 *
 */

void initSensors();

unsigned int getLeftSensorValue();
unsigned int getRightSensorValue();
unsigned int getCenterSensorValue();
