/*
 * OurMethods.c
 *
 *  Created on: 19 Oct 2017
 *      Author: jc240979
 */
#include "PE_Types.h"
#include "Term1.h"
#include "stdbool.h"

void DisplaySetUp (void) {
	Term1_MoveTo(1, 1);
	Term1_Cls();
	Term1_SendStr("RHor    - \r\n");
	Term1_SendStr("RVert   - \r\n");
	Term1_SendStr("RSwitch - \r\n\r\n");
	Term1_SendStr("LHor    - \r\n");
	Term1_SendStr("LVert   - \r\n");
	Term1_SendStr("LSwitch - \r\n");
}

void UpdateRH (byte *val) {
	Term1_MoveTo(10, 1);
	Term1_SendNum(val);
	Term1_SendStr("   ");
}

void UpdateRV (byte *val) {
	Term1_MoveTo(10, 2);
	Term1_SendNum(val);
	Term1_SendStr("   ");
}

void UpdateRS (bool *onoff) {
	Term1_MoveTo(10, 3);
	onoff == true ? Term1_SendStr("Pressed") : Term1_SendStr("Off");
}

void UpdateLH (byte *val) {
	Term1_MoveTo(10, 5);
	Term1_SendNum(val);
	Term1_SendStr("   ");
}

void UpdateLV (byte *val) {
	Term1_MoveTo(10, 6);
	Term1_SendNum(val);
	Term1_SendStr("   ");
}

void UpdateLS (bool *onoff) {
	Term1_MoveTo(10, 3);
	onoff == true ? Term1_SendStr("Pressed") : Term1_SendStr("Off");
}
