/*
 * PIT.c
 *
 *  Created on: 13 sep 2023
 *      Author: jose.gonzalezv
 */


#include "PIT.h"

static void (*PIT0_callback)(void) = 0;
static void (*PIT1_callback)(void) = 0;
static void (*PIT2_callback)(void) = 0;
static void (*PIT3_callback)(void) = 0;

//Callback function direction is passed to the corresponding PIT channel function pointer
void PIT_callback_init(pit_chnl_t pit_channel, void (*handler)(void))
{
	switch (pit_channel)
	{
	    case kPIT_Chnl_0:
	    	PIT0_callback = handler;
	    	break;
	    case kPIT_Chnl_1:
	    	PIT1_callback = handler;
	    	break;
	    case kPIT_Chnl_2:
	    	PIT2_callback = handler;
	    	break;
	    case kPIT_Chnl_3:
	    	PIT3_callback = handler;
	    	break;
	    default:
	    	break;

	}
}

//PIT Interrupt Service Routines:

void PIT0_IRQHandler(void)
{
	PIT_ClearStatusFlags(PIT, kPIT_Chnl_0, kPIT_TimerFlag);
	if (PIT0_callback)
	    PIT0_callback();
}

void PIT1_IRQHandler(void)
{
	PIT_ClearStatusFlags(PIT, kPIT_Chnl_1, kPIT_TimerFlag);
	if (PIT1_callback)
	    PIT1_callback();
}

void PIT2_IRQHandler(void)
{
	PIT_ClearStatusFlags(PIT, kPIT_Chnl_2, kPIT_TimerFlag);
	if (PIT2_callback)
		PIT2_callback();
}

void PIT3_IRQHandler(void)
{
	PIT_ClearStatusFlags(PIT, kPIT_Chnl_3, kPIT_TimerFlag);
	if (PIT3_callback)
	    PIT3_callback();
}
