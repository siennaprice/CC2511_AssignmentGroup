/* ###################################################################
**     Filename    : main.c
**     Project     : A2
**     Processor   : MK20DX128VLH5
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2017-10-16, 09:56, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "Term1.h"
#include "Inhr1.h"
#include "ASerialLdd1.h"
#include "AD1.h"
#include "AdcLdd1.h"
#include "leftSwitch.h"
#include "BitIoLdd1.h"
#include "rightSwitch.h"
#include "BitIoLdd2.h"
#include "stringThingy.h"
#include "PwmLdd1.h"
#include "TU1.h"
#include "magnet.h"
#include "BitIoLdd3.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* User includes (#include below this line is not maintained by Processor Expert) */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "OurMethods.h"

volatile bool flag = 0;
volatile char buffer[100];
volatile unsigned int index;
/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */
  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  //WRITE CODE HERE

  commandWindow();
  inputWindow();
  instructions();
  userInput();
  Term1_MoveTo(5,90);

//  int16 joysticks1[4], joysticks2[4];
//  	 word boomVertDS = 1000;
//  	 word string = 1500;
//  	 AD1_Calibrate(true);
//  	 AD1_Measure(true);
//  	 AD1_GetValue16(joysticks1);
  	 //set boom vertical to not moving
  	 //boomVert_SetDutyUS(boomVertDS);
  	 //set stringThingy vertical to not moving
  	 //stringThingy_SetDutyUS(string);



  //__asm ("wfi");

  //something is stuffed, it will detect the new string however, it will only ever print the first thing it detects, i.e if u enter a second command this wont be detected. As if the buffer isnt being reset properly, but i think it is to my best guess
  int command;
  for(;;){
//	  AD1_Measure(true);
//	  AD1_GetValue16(joysticks2);
//	// If the values change, update the display
//	  for (int i = 0; i <= 4; i++){
//		if (joysticks1[i] != joysticks2[i])
//			UpdateDisplay(joysticks2, i);
//	  }
//	// Save the latest set of values
//	  for (int i = 0; i <= 4; i++){
//		  joysticks1[i] = joysticks2[i];
//	  }
	  while(flag){
		  if(sscanf(buffer, "go up %i", &command) == 1){
			  Term1_MoveTo(67,9);
			  Term1_SendStr("going up ");
			  Term1_SendNum(command);
			  //string += command;
			  //stringThingy_SetDutyUS(string);
			  Term1_MoveTo(67,6);
			  Term1_EraseLine();
			  userInput();
		  }
		  else if(sscanf(buffer, "go down %i", &command) == 1){
			  Term1_MoveTo(67,9);
			  Term1_SendStr("going down ");
			  Term1_SendNum(command);
			  Term1_MoveTo(67,6);
			  Term1_EraseLine();
			  userInput();
		 }
		  flag = false;
	 }
  }


  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
