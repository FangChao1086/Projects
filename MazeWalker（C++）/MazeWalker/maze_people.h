#ifndef __MAZE_PEOPLE_H__
#define __MAZE_PEOPLE_H__

class MazePeople {
public:
	enum objectiveDirections { UP, DOWN, LEFT, RIGHT };
	MazePeople();  // 构造函数，默认初始化人的位置
	MazePeople(int currentX, int currentY);  // 构造函数，设置人的初始化位置
	MazePeople(int currentX, int currentY, objectiveDirections myForward);  // 构造函数，设置人的初始化位置和方向
	MazePeople &setPersonPosition(int coordX, int coordY);
	void  gotoxy(int x, int y);
	void goAhead();
	bool moveForward();  // 前进方法
	void start();

private:
	char mazePeople;
	int preX, preY;
	int nowX, nowY;
	bool outOrNot;
	objectiveDirections forward;
};
#endif