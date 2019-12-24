#ifndef _FOOD_HEAD
#define _FOOD_HEAD

#include <iostream>
#include "wall.h"
using namespace std;

class Food
{
public:
	Food(Wall &tmpWall);
	~Food();
	void setFood();//…Ë÷√ ≥ŒÔ


private:
	int foodX;
	int foodY;
	Wall& wall;
};


#endif// !_FOOD_HEAD