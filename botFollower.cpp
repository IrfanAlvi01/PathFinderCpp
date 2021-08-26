//======================================================================================
//Source code for a bot that randomly moves around, plus other bots as required
//
//(c) Patrick Dickinson, University of Lincoln, School of Computer Science, 2020
//======================================================================================

#include "bots.h"
#include "stdlib.h"

void cBotFollower::ChooseNextGridPosition()
{
	if (gAStar.maxPathLen > 0)
	{
		SetNext(gAStar.followedPath[gAStar.maxPathLen-1][0], gAStar.followedPath[gAStar.maxPathLen-1][1], gLevel);
		gAStar.maxPathLen -= 1;
	}
}