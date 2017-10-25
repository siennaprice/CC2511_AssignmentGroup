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


//--------------------------AUTOMATIC FUNCTION--------------------------

// ----- prints a rectangle window --------
void commandWindow(){
	Term1_SetColor(clBlack, clYellow);
	  for(int i = 10; i < 55; i++){
		  Term1_MoveTo(i,1);
		  Term1_SendStr("-");
		  Term1_MoveTo(i,15);
		  Term1_SendStr("-");
	  }
	  for(int i = 2 ; i<15 ; i++){
		  Term1_MoveTo(10,i);
		  Term1_SendStr("|");
		  Term1_MoveTo(54,i);
		  Term1_SendStr("|");
	   }
}

//-----Print input area----------------
void inputWindow(){
	Term1_SetColor(clBlack, clYellow);
	for(int i = 65; i < 105; i++){
		Term1_MoveTo(i,1);
		Term1_SendStr("-");
		Term1_MoveTo(i, 15);
		Term1_SendStr("-");
	}
	  for(int i = 2 ; i<15 ; i++){
		  Term1_MoveTo(65,i);
		  Term1_SendStr("|");
		  Term1_MoveTo(104,i);
		  Term1_SendStr("|");
	   }


}

void userInput(){
	Term1_SetColor(clWhite, clBlack);
	Term1_MoveTo(67, 3);
	Term1_SendStr("___Please enter your commands here__");
	Term1_MoveTo(67,6);
	Term1_SendStr("Input: ");
}

//----Prints user options in the window ---
void instructions(){
	Term1_SetColor(clWhite, clBlack);
	Term1_MoveTo(12,3);
	Term1_SendStr("_________________Options______________");
	Term1_MoveTo(12,5);
	Term1_SendStr("1). Type: go up/down value");
	Term1_MoveTo(12,7);
	Term1_SendStr("2). Type: move left/right value");
}



