/*
 * OurMethods.c
 *
 *  Created on: 19 Oct 2017
 *      Author: jc240979
 */
#include "OurMethods.h"
#include "PE_Types.h"
#include "Term1.h"
#include "stdbool.h"

void DisplaySetUp (void) {
	Term1_MoveTo(1, 1);
	Term1_Cls();
	Term1_SendStr("RH   - \r\n");
	Term1_SendStr("RV   - \r\n");
	Term1_SendStr("LV   - \r\n");
	Term1_SendStr("LH   - \r\n");
}

void UpdateDisplay (int16 *values, int index) {
	Term1_MoveTo(11, index + 1);
	Term1_SendNum(values[index]);
	Term1_SendStr("   ");
}



