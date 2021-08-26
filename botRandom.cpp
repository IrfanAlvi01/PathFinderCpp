//======================================================================================
//Source code for a bot that randomly moves around, plus other bots as required
//
//(c) Patrick Dickinson, University of Lincoln, School of Computer Science, 2020
//======================================================================================

#include "bots.h"
#include "stdlib.h"

void cBotRandom::ChooseNextGridPosition() 
{
	SetNext(PositionX(), PositionY(), gLevel);
}