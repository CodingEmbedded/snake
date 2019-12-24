#ifndef _SNAKE_HEAD
#define	_SNAKE_HEAD
#include <iostream>
#include "wall.h"
#include "food.h"

using namespace std;


class Snake
{
public:
	enum 
	{
		UP = 'w',
		DOWN = 's',
		LEFT = 'a',
		RIGHT = 'd'
	};
	struct Point
	{
		int x;
		int y;
		struct Point* next;
	};

	Snake(Wall& tmpWall, Food& tempFood);
	~Snake();

	bool move(char key);

	void delPoint();

	void initSnake();

	void destoryPoint();

	void addPoint(int x, int y);

	int getSleepTime();

	int countList();

private:
	Point* phead;
	Wall& wall;
	Food& food;
	bool isRool;

};


#endif // !_SNAKE_HEAD


