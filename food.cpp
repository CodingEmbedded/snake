#include "food.h"

Food::Food(Wall& tmpWall) :wall(tmpWall)
{
}

Food::~Food()
{
}

void Food::setFood()
{
	while (1)
	{
		foodX = rand() % (wall.ROW - 2) + 1;
		foodY = rand() % (wall.ROW - 2) + 1;
		if (wall.getWall(foodX, foodY) == ' ')
		{
			wall.setWall(foodX, foodY, '#');
			break;
		}
	}

}