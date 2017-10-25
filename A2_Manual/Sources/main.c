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
  int16 joysticks1[4], joysticks2[4];
  word boomVertDS = 1000;
  word string = 1500;
  DisplaySetUp();
  AD1_Calibrate(true);
  AD1_Measure(true);
  AD1_GetValue16(joysticks1);
  //set boom vertical to not moving
  boomVert_SetDutyUS(boomVertDS);
  //set stringThingy vertical to not moving
  // stringThingy_SetDutyUS(magnet);
 Motor_SetRatio8(120);
for(;;) {
	  AD1_Measure(true);
	  AD1_GetValue16(joysticks2);

	  // If the values change, update the display
	  for (int i = 0; i <= 4; i++){
		if (joysticks1[i] != joysticks2[i])
			UpdateDisplay(joysticks2, i);
	  }

	  // Save the latest set of values
	  for (int i = 0; i <= 4; i++){
		  joysticks1[i] = joysticks2[i];
	  }

	  // if right vertical is detected; boom up/down
	  // note: condense this later
//	  if (joysticks1[1] > 40 && joystick1[1] < 100) { // up
//		  boomVert_SetDutyUS(2000);
//	  }
//	  else if (joysticks1[1] < -30) { // down
//		  boomVert_SetDutyUS(1000);
//	  }
//	  else{
//	  	boomVert_SetDutyUS(1500);
//	  }

	//   If left vertical is detected; magnet up/down
//	  if (joysticks1[2] > 0 && joysticks1[2] < 100) {
//		  stringThingy_SetDutyUS(1000); // down
//	  } else if (joysticks1[2] < 0) {
//		  stringThingy_SetDutyUS(2000); // up
//	  } else {
//		  stringThingy_SetDutyUS(1600); // not moving
//	  }
//
//	  if(joysticks1[3] > 0 && joysticks1[3] < 100){
//		  direction_PutVal(1);
//		  Motor_Enable();
//	  }
//	  else if(joysticks1[3] < 0){
//		  direction_PutVal(0);
//		  Motor_Enable();
//	  }
//	  else{
//		  Motor_Disable();
//	  }

	  Motor_Enable();
	  //turns magnet on and off (have to hold switch to keep magnet on)
//	  if(leftSwitch_GetVal() == 1){
//		  //this is being reached, but it is not sending putVal to the magnet.
//		  magnet_PutVal(1);
//	  }
//	  else if(leftSwitch_GetVal() == 0){
//		 magnet_PutVal(0);
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
