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
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* User includes (#include below this line is not maintained by Processor Expert) */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


volatile bool flag = 0;
volatile char buffer[100];
volatile unsigned int index;
// ----- prints a rectangle window --------
void window(){
	Term1_SetColor(clBlack, clYellow);
	  for(int i = 10; i < 60; i++){
		  Term1_MoveTo(i,1);
		  Term1_SendStr("-");
	  }
	  for(int i = 10 ; i<60 ; i++){
		  Term1_MoveTo(i,20);
		  Term1_SendStr("-");
	  }
	  for(int i = 2 ; i<21 ; i++){
		  Term1_MoveTo(10,i);
		  Term1_SendStr("|");
	   }
	  for(int i = 2 ; i<21 ; i++){
		  Term1_MoveTo(59,i);
		  Term1_SendStr("|");
	  }
}

//----Prints user options in the window ---
void commands(){
	Term1_SetColor(clWhite, clBlack);
	Term1_MoveTo(12,3);
	Term1_SendStr("Use A and D to Go left and Right: ");
	Term1_MoveTo(12,5);
	Term1_SendStr("Use W and S To use the Boom: ");
	Term1_MoveTo(12,7);
	Term1_SendStr("Input: ");

}

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  //WRITE CODE HERE
  window();
  commands();

  for(;;){
	  if(flag){
		  if(0 == strcmp(buffer, "move to 10")){
			  Term1_MoveTo(12,10);
			  Term1_SendStr("i just got told to move to 10");
			  Term1_MoveTo(12,7);
			  Term1_EraseLine();
			  commands();
			  flag = false;
		  }
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
