#include "bots.h"
#include "stdlib.h"
#include "iostream"

void cDijkstra::Build(cBotBase &bot)
{
	for (int i = 0; i < GRIDWIDTH; i++)
	{
		for (int j = 0; j < GRIDHEIGHT; j++)
		{
			closed[i][j] = false;
			cost[i][j] = 1000000.0f;
			linkX[i][j] = -1;
			linkY[i][j] = -1;
			inPath[i][j] = false;
		}
	}
	cost[bot.PositionX()][bot.PositionY()] = 0;
	while (!closed[gTarget.PositionX()][gTarget.PositionY()])
	{
		int minIndX = 0;
		int minIndY = 0;
		float minCost = 1000000.0f;
		for (int i = 0; i < GRIDWIDTH; i++)
		{
			for (int j = 0; j < GRIDHEIGHT; j++)
			{
				if((cost[i][j] <= minCost) && gLevel.isValid(i, j) && !closed[i][j])
				{
					minCost = cost[i][j];
					minIndX = i;
					minIndY = j;
				}
			}
		}
		closed[minIndX][minIndY] = true;
		if (gLevel.isValid(minIndX - 1, minIndY - 1) && !closed[minIndX - 1][minIndY - 1])
			if ((cost[minIndX][minIndY] + 1.4f) < cost[minIndX - 1][minIndY - 1])
			{
				cost[minIndX - 1][minIndY - 1] = cost[minIndX][minIndY] + 1.4f;
				linkX[minIndX - 1][minIndY - 1] = minIndX;
				linkY[minIndX - 1][minIndY - 1] = minIndY;
			}

		if (gLevel.isValid(minIndX - 1, minIndY) && !closed[minIndX - 1][minIndY])
			if ((cost[minIndX][minIndY] + 1.0f) < cost[minIndX - 1][minIndY])
			{
				cost[minIndX - 1][minIndY] = cost[minIndX][minIndY] + 1.0f;
				linkX[minIndX - 1][minIndY] = minIndX;
				linkY[minIndX - 1][minIndY] = minIndY;
			}

		if (gLevel.isValid(minIndX - 1, minIndY + 1) && !closed[minIndX - 1][minIndY + 1])
			if ((cost[minIndX][minIndY] + 1.4f) < cost[minIndX - 1][minIndY + 1])
			{
				cost[minIndX - 1][minIndY + 1] = cost[minIndX][minIndY] + 1.4f;
				linkX[minIndX - 1][minIndY + 1] = minIndX;
				linkY[minIndX - 1][minIndY + 1] = minIndY;
			}

		if (gLevel.isValid(minIndX, minIndY - 1) && !closed[minIndX][minIndY - 1])
			if ((cost[minIndX][minIndY] + 1.0f) < cost[minIndX][minIndY - 1])
			{
				cost[minIndX][minIndY - 1] = cost[minIndX][minIndY] + 1.0f;
				linkX[minIndX][minIndY - 1] = minIndX;
				linkY[minIndX][minIndY - 1] = minIndY;
			}

		if (gLevel.isValid(minIndX, minIndY + 1) && !closed[minIndX][minIndY + 1])
			if ((cost[minIndX][minIndY] + 1.0f) < cost[minIndX][minIndY + 1])
			{
				cost[minIndX][minIndY + 1] = cost[minIndX][minIndY] + 1.0f;
				linkX[minIndX][minIndY + 1] = minIndX;
				linkY[minIndX][minIndY + 1] = minIndY;
			}

		if (gLevel.isValid(minIndX + 1, minIndY - 1) && !closed[minIndX + 1][minIndY - 1])
			if ((cost[minIndX][minIndY] + 1.4f) < cost[minIndX + 1][minIndY - 1])
			{
				cost[minIndX + 1][minIndY - 1] = cost[minIndX][minIndY] + 1.4f;
				linkX[minIndX + 1][minIndY - 1] = minIndX;
				linkY[minIndX + 1][minIndY - 1] = minIndY;
			}

		if (gLevel.isValid(minIndX + 1, minIndY) && !closed[minIndX + 1][minIndY])
			if ((cost[minIndX][minIndY] + 1.0f) < cost[minIndX + 1][minIndY])
			{
				cost[minIndX + 1][minIndY] = cost[minIndX][minIndY] + 1.0f;
				linkX[minIndX + 1][minIndY] = minIndX;
				linkY[minIndX + 1][minIndY] = minIndY;
			}

		if (gLevel.isValid(minIndX + 1, minIndY + 1) && !closed[minIndX + 1][minIndY + 1])
			if ((cost[minIndX][minIndY] + 1.4f) < cost[minIndX + 1][minIndY + 1])
			{
				cost[minIndX + 1][minIndY + 1] = cost[minIndX][minIndY] + 1.4f;
				linkX[minIndX + 1][minIndY + 1] = minIndX;
				linkY[minIndX + 1][minIndY + 1] = minIndY;
			}
	}
	int nextClosedX = gTarget.PositionX();
	int nextClosedY = gTarget.PositionY();
	while (true)
	{
		if ((nextClosedX == bot.PositionX()) && (nextClosedY == bot.PositionY()))
			break;
		inPath[nextClosedX][nextClosedY] = true;
		int tmpX = nextClosedX;
		int tmpY = nextClosedY;
		nextClosedX = linkX[tmpX][tmpY];
		nextClosedY = linkY[tmpX][tmpY];
	}
	completed = true;
}

void cAStar::Build(cBotBase& bot)
{
	for (int i = 0; i < GRIDWIDTH; i++)
	{
		for (int j = 0; j < GRIDHEIGHT; j++)
		{
			closed[i][j] = false;
			cost[i][j] = 1000000.0f;
			linkX[i][j] = -1;
			linkY[i][j] = -1;
			inPath[i][j] = false;
		}
	}
	cost[bot.PositionX()][bot.PositionY()] = 0;
	while (!closed[gTarget.PositionX()][gTarget.PositionY()])
	{
		int minIndX = 0;
		int minIndY = 0;
		float minCost = 1000000.0f;
		for (int i = 0; i < GRIDWIDTH; i++)
		{
			for (int j = 0; j < GRIDHEIGHT; j++)
			{
				float heuristic = (float)fabs(gTarget.PositionX() - i) + (float)fabs(gTarget.PositionY() - j);
				if (((cost[i][j] + heuristic) <= minCost) && gLevel.isValid(i, j) && !closed[i][j])
				{
					minCost = cost[i][j] + heuristic;
					minIndX = i;
					minIndY = j;
				}
			}
		}
		closed[minIndX][minIndY] = true;
		if (gLevel.isValid(minIndX - 1, minIndY - 1) && !closed[minIndX - 1][minIndY - 1])
			if ((cost[minIndX][minIndY] + 1.4f) < cost[minIndX - 1][minIndY - 1])
			{
				cost[minIndX - 1][minIndY - 1] = cost[minIndX][minIndY] + 1.4f;
				linkX[minIndX - 1][minIndY - 1] = minIndX;
				linkY[minIndX - 1][minIndY - 1] = minIndY;
			}

		if (gLevel.isValid(minIndX - 1, minIndY) && !closed[minIndX - 1][minIndY])
			if ((cost[minIndX][minIndY] + 1.0f) < cost[minIndX - 1][minIndY])
			{
				cost[minIndX - 1][minIndY] = cost[minIndX][minIndY] + 1.0f;
				linkX[minIndX - 1][minIndY] = minIndX;
				linkY[minIndX - 1][minIndY] = minIndY;
			}

		if (gLevel.isValid(minIndX - 1, minIndY + 1) && !closed[minIndX - 1][minIndY + 1])
			if ((cost[minIndX][minIndY] + 1.4f) < cost[minIndX - 1][minIndY + 1])
			{
				cost[minIndX - 1][minIndY + 1] = cost[minIndX][minIndY] + 1.4f;
				linkX[minIndX - 1][minIndY + 1] = minIndX;
				linkY[minIndX - 1][minIndY + 1] = minIndY;
			}

		if (gLevel.isValid(minIndX, minIndY - 1) && !closed[minIndX][minIndY - 1])
			if ((cost[minIndX][minIndY] + 1.0f) < cost[minIndX][minIndY - 1])
			{
				cost[minIndX][minIndY - 1] = cost[minIndX][minIndY] + 1.0f;
				linkX[minIndX][minIndY - 1] = minIndX;
				linkY[minIndX][minIndY - 1] = minIndY;
			}

		if (gLevel.isValid(minIndX, minIndY + 1) && !closed[minIndX][minIndY + 1])
			if ((cost[minIndX][minIndY] + 1.0f) < cost[minIndX][minIndY + 1])
			{
				cost[minIndX][minIndY + 1] = cost[minIndX][minIndY] + 1.0f;
				linkX[minIndX][minIndY + 1] = minIndX;
				linkY[minIndX][minIndY + 1] = minIndY;
			}

		if (gLevel.isValid(minIndX + 1, minIndY - 1) && !closed[minIndX + 1][minIndY - 1])
			if ((cost[minIndX][minIndY] + 1.4f) < cost[minIndX + 1][minIndY - 1])
			{
				cost[minIndX + 1][minIndY - 1] = cost[minIndX][minIndY] + 1.4f;
				linkX[minIndX + 1][minIndY - 1] = minIndX;
				linkY[minIndX + 1][minIndY - 1] = minIndY;
			}

		if (gLevel.isValid(minIndX + 1, minIndY) && !closed[minIndX + 1][minIndY])
			if ((cost[minIndX][minIndY] + 1.0f) < cost[minIndX + 1][minIndY])
			{
				cost[minIndX + 1][minIndY] = cost[minIndX][minIndY] + 1.0f;
				linkX[minIndX + 1][minIndY] = minIndX;
				linkY[minIndX + 1][minIndY] = minIndY;
			}

		if (gLevel.isValid(minIndX + 1, minIndY + 1) && !closed[minIndX + 1][minIndY + 1])
			if ((cost[minIndX][minIndY] + 1.4f) < cost[minIndX + 1][minIndY + 1])
			{
				cost[minIndX + 1][minIndY + 1] = cost[minIndX][minIndY] + 1.4f;
				linkX[minIndX + 1][minIndY + 1] = minIndX;
				linkY[minIndX + 1][minIndY + 1] = minIndY;
			}
	}
	int nextClosedX = gTarget.PositionX();
	int nextClosedY = gTarget.PositionY();
	int pathTempX = 0;
	while (true)
	{
		if ((nextClosedX == bot.PositionX()) && (nextClosedY == bot.PositionY()))
			break;
		inPath[nextClosedX][nextClosedY] = true;
		followedPath[pathTempX][0] = nextClosedX;
		followedPath[pathTempX][1] = nextClosedY;
		pathTempX += 1;
		int tmpX = nextClosedX;
		int tmpY = nextClosedY;
		nextClosedX = linkX[tmpX][tmpY];
		nextClosedY = linkY[tmpX][tmpY];
	}
	completed = true;
	maxPathLen = pathTempX;
}

cDijkstra gDijkstra;
cAStar gAStar;