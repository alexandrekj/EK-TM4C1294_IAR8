#include <stdint.h>
#include <stdbool.h>
// includes da biblioteca driverlib
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"


void main(void){        
  
  SysCtlClockFreqSet(SYSCTL_OSC_INT | SYSCTL_USE_PLL | SYSCTL_CFG_VCO_320 , 24000000); // 24MHz
  
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF); // Habilita GPIO F ( LED D4 = PF0)
  while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF)); // Aguarda final da habilitação
    
  GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_0); // LEDs D4 como saída
  GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, 0); // LED D4 apagado
  GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_0, GPIO_STRENGTH_12MA, GPIO_PIN_TYPE_STD);

  int estadoLED = 0;
  
  while(1){
  
  for(int cont = 0; cont < 3000000; cont++); // 1 segundo p/ f=24MHz
  
  if(estadoLED == 0){
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, 1); //garante a alteração do estado
    estadoLED = 1;
  } else{
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, 0);
    estadoLED = 0;
  }
  } // while
  
  
} // main