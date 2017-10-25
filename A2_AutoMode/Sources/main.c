/* ###################################################################
**     Filename    : main.c
**     Project     : A2_AutoMode
**     Processor   : MK20DX128VLH5
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2017-10-25, 09:46, # CodeGen: 0
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
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* User includes (#include below this line is not maintained by Processor Expert) */
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

  /* Write your code here */
  commandWindow();
  inputWindow();
  instructions();
  userInput();

  int command;
  for(;;){
	  if(flag == 1){
		  if(sscanf(buffer, "go up %i", &command) == 1){
			  Term1_MoveTo(67,9);
			  Term1_SendStr("going up ");
			  Term1_SendNum(command);
			  Term1_MoveTo(67,6);
			  Term1_EraseLine();
			  userInput();
		  }
		  else if(sscanf(buffer, "go down %i", &command) == 1){
			  Term1_MoveTo(67,10);
			  Term1_SendStr("going down ");
			  Term1_SendNum(command);
			  Term1_MoveTo(67,6);
			  Term1_EraseLine();
			  userInput();
		 }
		  else{
			  Term1_MoveTo(67, 11);
			  Term1_SendStr("That does not match any valid input");
			  Term1_SendStr("please try again");
			  Term1_MoveTo(67,6);
			  Term1_EraseLine();
			  userInput();
		  }
		  flag = 0;
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
