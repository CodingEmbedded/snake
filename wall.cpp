#include "wall.h"

Wall::Wall()
{
	gameArray[0][0] = 0;
}

Wall::~Wall()
{
}
void Wall::initWall()
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			//墙的条件
			if (i == 0 || i == ROW - 1 || j == 0 || j == COL - 1)
			{
				gameArray[i][j] = '*';
			}
			else
			{
				gameArray[i][j] = ' ';
			}
		}
	}
}

void Wall::draw()
{
	for (int i = 0; i < ROW; i++)
	{
		for(int j = 0 ; j < COL; j++)
		{ 
			cout << gameArray[i][j] << ' ';
		}
		if (i == 5)
			cout << "Snake Game V1.0";
		if (i == 6)
			cout << "Creat by hackett 2019-12-19";
		if (i == 7)
			cout << "up		:w" << " ";
		if (i == 8)
			cout << "down	:s" << " ";
		if (i == 9)
			cout << "left	:a" << " ";
		if (i == 10)
			cout << "right	:d" << " ";
		cout << endl;//结束换行

	}
}
void Wall::setWall(int x, int y, char key)
{
	gameArray[x][y] = key;
}

char Wall::getWall(int x, int y)
{
	return gameArray[x][y];
}