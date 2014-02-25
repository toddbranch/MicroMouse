#include "sensors.h"

void initSensors()
{
  // turn system on and select longest sample interval
  ADC10CTL0 = ADC10SHT_3 + ADC10ON;

  // P1.3, P1.4, P1.5
  ADC10AE0 |= INCH3|INCH4|INCH5;

  // Select SMCLK
	ADC10CTL1 |= ADC10SSEL1|ADC10SSEL0;

  // Add largest clock divider
  ADC10CTL1 |= ADC10DIV2|ADC10DIV1|ADC10DIV0;
}

unsigned int getLeftSensorValue()
{
  //set INCH to proper bit
  ADC10CTL1 = INCH_5;

  //initiate conversion
  ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start

  //poll for result
  while (!(ADC10IFG & ADC10CTL0)) {}

  //clear flag
  ADC10CTL0 &= ~ADC10IFG;

  //return result
  return ADC10MEM;
}

unsigned int getRightSensorValue()
{
  //set INCH to proper bit
  ADC10CTL1 = INCH_3;

  //initiate conversion
  ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start

  //poll for result
  while (!(ADC10IFG & ADC10CTL0)) {}

  //clear flag
  ADC10CTL0 &= ~ADC10IFG;

  //return result
  return ADC10MEM;
}

unsigned int getCenterSensorValue()
{
  return 0;
}
