#include "snake.h"
#include "food.h"
#include "wall.h"

Snake::Snake(Wall& tmpWall, Food& tmpFood) : wall(tmpWall), food(tmpFood)
{
	phead = NULL;
	isRool = false;
}

Snake::~Snake()
{
}

void Snake::initSnake()
{
	destoryPoint();

	addPoint(5, 3);
	addPoint(5, 4);
	addPoint(5, 5);
}
void Snake::destoryPoint()
{
	Point* pcur = phead;
	while (phead != NULL)
	{
		pcur = phead->next;
		delete phead;
		phead = pcur;
	}
}

void Snake::addPoint(int x, int y)
{
	Point* newp = new Point;
	if (newp == NULL)
	{
		return;
	}
	newp->x = x;
	newp->y = y;
	newp->next = NULL;

	if (phead != NULL)
	{
		wall.setWall(phead->x, phead->y, '=');
	}
	newp->next = phead;
	phead = newp;
	wall.setWall(phead->x, phead->y, '@');

}

void Snake::delPoint()
{
	if (phead == NULL || phead->next == NULL)
		return;

	Point* pre = phead;
	Point* cur = phead->next;

	while (cur->next != NULL)
	{
		pre = pre->next;
		cur = pre->next;
	}

	wall.setWall(cur->x, cur->y, ' ');
	delete cur;
	cur = NULL;
	pre->next = NULL;

}
bool Snake::move(char key)
{
	int x = phead->x;
	int y = phead->y;

	switch (key)
	{
	case UP:
		x--;
		break;
	case DOWN:
		x++;
		break;
	case LEFT:
		y--;
		break;
	case RIGHT:
		y++;
		break;

	default:
		return true;
	}
	Point* pre = phead;
	Point* cur = phead->next;

	while (cur->next != NULL)
	{
		pre = pre->next;
		cur = pre->next;
	}

	if (cur->x == x && cur->y == y)
	{
		isRool = true;
	}
	if (wall.getWall(x, y) == '=' || wall.getWall(x, y) == '*')
	{
		addPoint(x, y);
		delPoint();
		system("cls");
		wall.draw();
		cout << "gameOver!" << endl;
		return false;
	}
	if (wall.getWall(x, y) == '#')
	{
		addPoint(x, y);
		food.setFood();
	}
	else
	{
		if(isRool)
		{
			addPoint(x, y);
			delPoint();
			wall.setWall(x, y, '@');
		}
		else
		{
			addPoint(x, y);
			delPoint();
		}

	}
	return true;
}

int Snake::getSleepTime()
{
	int sTime = 0;
	int size = countList();
	if (size < 5)
	{
		sTime = 300;
	}
	else if (size >= 5 && size <= 10)
	{
		sTime = 200;
	}
	else if (size > 20)
	{
		sTime = 50;
	}

	return sTime;

}

int Snake::countList()
{
	int size = 0;
	Point* curP = phead;
	while (curP != NULL)
	{
		size++;
		curP = curP->next;
	}

	return size;
}
