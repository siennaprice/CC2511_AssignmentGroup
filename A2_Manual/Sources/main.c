/* ###################################################################
**     Filename    : main.c
**     Project     : crane
**     Processor   : MK20DX128VLH5
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2017-10-16, 10:25, # CodeGen: 0
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
#include "boomVert.h"
#include "PwmLdd1.h"
#include "TU1.h"
#include "stringThingy.h"
#include "PwmLdd2.h"
#include "Motor.h"
#include "PwmLdd3.h"
#include "TU2.h"
#include "direction.h"
#include "BitIoLdd4.h"
#include "magnet.h"
#include "BitIoLdd3.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* User includes (#include below this line is not maintained by Processor Expert) */
#include "stdbool.h"
#include "OurMethods.h"
/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  //-----------------------------------------------------------------------------------------------------
  int16 joysticks1[6], joysticks2[6]; // Includes hall sensors
//  word boomVertDS = 1500;
  DisplaySetUp();
  AD1_Calibrate(true);
  AD1_Measure(true);
  AD1_GetValue16(joysticks1);

 for(;;) {
	  AD1_Measure(true);
	  AD1_GetValue16(joysticks2);

	  // If the values change, update the display
	  for (int i = 0; i < 4; i++){
		if (joysticks1[i] != joysticks2[i])
			UpdateDisplay(joysticks2, i);
	  }

	  // Save the latest set of values
	  for (int i = 0; i < 4; i++){
		  joysticks1[i] = joysticks2[i];
	  }

//	  // if right vertical is detected; boom up/down :NEED ANOTHER CRANE TO TEST THIS
//	  if (joysticks1[1] > 0) { // up
//		  boomVertDS++
//		  boomVert_SetDutyUS(boomVertDS);
//	  }
//	  else if (joysticks1[1] < 0 && joysticks1[1] > -1000 ) { // down
//		  boomVertDS--
//		  boomVert_SetDutyUS(boomVertDS);
//	  }

      // If left vertical is detected; magnet up/down  :THIS WORKS NOW
	  if (joysticks1[2] < 0) {
		  stringThingy_SetDutyUS(2000); // down
	  } else if (joysticks1[2] > 0 && joysticks1[2] < 1000) {
		  stringThingy_SetDutyUS(1000); // up
	  } else {
		  stringThingy_SetDutyUS(1600); // stop
	  }

	// DC Motor :NOT WORKING
	  if (joysticks2[3] > 0) {
		  direction_SetVal(); // Left
		  Motor_SetRatio8(120);
	  } else if (joysticks2[3] < 0 && joysticks2[3] > -1000) {
		  direction_ClrVal(); // Right
		  Motor_SetRatio8(120);
	  } else {
		  Motor_SetRatio8(0);
	  }

//	  // Magnet on/off :NOT WORKING
//	  if (leftSwitch_GetVal() == 1) {
//		  magnet_NegVal();
//	  	  while (leftSwitch_GetVal() == 1){
//		  // Wait for button release
//	  	  }
//	  }

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
