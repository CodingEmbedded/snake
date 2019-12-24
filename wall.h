#ifndef _WALL_HEAD
#define _WALL_HEAD
#include <iostream>
using namespace std;
class Wall
{
public:
	enum 
	{
		ROW = 26,
		COL = 26,
	};
	Wall();
	~Wall();

	void initWall();

	void draw();

	void setWall(int x, int y, char key);

	char getWall(int x, int y);

private:
	char gameArray[ROW][COL];

};

#endif // !_WALL_HEAD

