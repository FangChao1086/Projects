#include"point.h"
#include"tools.h"
#include<iostream>

// 输出方块
void Point::Print() {
	SetCursorPosition(x, y);
	std::cout << "■";
}

// 输出圆形
void Point::PrintCircular() {
	SetCursorPosition(x, y);
	std::cout << "●";
}

// 清除输出
void Point::Clear() {
	SetCursorPosition(x, y);
	std::cout << "  ";
}

// 改变坐标
void Point::ChangePosition(const int x, const int y)
{
	this->x = x;
	this->y = y;
}
