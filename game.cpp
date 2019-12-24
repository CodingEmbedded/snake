#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <time.h>
#include <string>
#include <ctime>
#include <Windows.h>
#include "wall.h"
#include "snake.h"
#include "food.h"
using namespace std;

int main() 
{
	bool isDead = false;
	char preKey = NULL;

	srand((unsigned int)time(NULL));
	Wall wall;	//墙对象
	wall.initWall();	//初始化

	Food food(wall);
	food.setFood();

	Snake snake(wall,food);
	snake.initSnake();

	//测试
	snake.move(snake.UP);
	snake.move(snake.UP);
	snake.move(snake.LEFT);

	wall.draw();

	while (!isDead)
	{
		char key = _getch();

		if (preKey == NULL && key == snake.LEFT)
		{
			continue;
		}
		
		do {


			if (key == snake.UP || key == snake.RIGHT || key == snake.LEFT || key == snake.DOWN)
			{
				if ((key == snake.LEFT && preKey == snake.RIGHT) ||
					(key == snake.RIGHT && preKey == snake.LEFT) ||
					(key == snake.DOWN && preKey == snake.UP) ||
					(key == snake.UP && preKey == snake.DOWN))
				{
					key = preKey;
				}
				else
				{
					preKey = key;
				}
				if (snake.move(key) == true)
				{
					system("cls");
					wall.draw();
					Sleep(300);  //睡眠
				}
				else
				{
					//死亡处理
					isDead = true;
					break;
				}
			}
		} while (!_kbhit());
		
	}

	system("pause");
	return EXIT_SUCCESS;
}