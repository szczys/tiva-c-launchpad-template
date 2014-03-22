/****************
Demo code which can be included in open source packages, more details:
https://github.com/szczys/tiva-c-launchpad-template

This is a placeholder example
included with a gcc tiva C template

It illuminates each color of the
Tiva C Launchpad board LED in order,
pausing about 1 second on each
color.
****************/

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/debug.h"
#include "driverlib/fpu.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "utils/uartstdio.h"

void initClock(void) {
	//Start the system clock
    ROM_SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);
}

void initIO(void) {
    //Enable PortF
    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

    //LED Pins as outputs
    ROM_GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3);
}

int main(void)
{

    //Initialization
    initClock();
	initIO();

    while(1) {

		//Red
		GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, GPIO_PIN_1);		//Turn on LED
		ROM_SysCtlDelay( (ROM_SysCtlClockGet()/(3*1000))*1000) ; 	//delay ~1s
		GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0);				//Turn off LED

		//Blue
		GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, GPIO_PIN_2);		//Turn on LED
		ROM_SysCtlDelay( (ROM_SysCtlClockGet()/(3*1000))*1000) ; 	//delay ~1s
		GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0);				//Turn off LED

		//Green
		GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, GPIO_PIN_3);		//Turn on LED
		ROM_SysCtlDelay( (ROM_SysCtlClockGet()/(3*1000))*1000) ; 	//delay ~1s
		GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0);				//Turn off LED
		
    }
}
