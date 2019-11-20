#ifndef _START_INTERFACE_H
#define _START_INTERFACE_H

#include<deque>
#include<vector>
#include"point.h"

class StartInterface {
public:
	StartInterface() : speed(50) {
		startsnake.emplace_back(Point(0, 14));
		startsnake.emplace_back(Point(1, 14));
		startsnake.emplace_back(Point(2, 15));
		startsnake.emplace_back(Point(3, 16));
		startsnake.emplace_back(Point(4, 17));
		startsnake.emplace_back(Point(5, 18));
		startsnake.emplace_back(Point(6, 17));
		startsnake.emplace_back(Point(7, 16));
		startsnake.emplace_back(Point(8, 15));
		startsnake.emplace_back(Point(9, 14));

		textsnake.emplace_back(Point(-26, 14));  // S
		textsnake.emplace_back(Point(-25, 14));
		textsnake.emplace_back(Point(-27, 15));
		textsnake.emplace_back(Point(-26, 16));
		textsnake.emplace_back(Point(-25, 17));
		textsnake.emplace_back(Point(-27, 18));
		textsnake.emplace_back(Point(-26, 18));

		textsnake.emplace_back(Point(-11, 20));
		textsnake.emplace_back(Point(-12, 20));
		textsnake.emplace_back(Point(-13, 20));
		textsnake.emplace_back(Point(-14, 20));
		textsnake.emplace_back(Point(-15, 20));
		textsnake.emplace_back(Point(-16, 20));

		textsnake.emplace_back(Point(-1, 14));  // S
		textsnake.emplace_back(Point(0, 14));
		textsnake.emplace_back(Point(-2, 15));
		textsnake.emplace_back(Point(-1, 16));
		textsnake.emplace_back(Point(0, 17));
		textsnake.emplace_back(Point(-2, 18));
		textsnake.emplace_back(Point(-1, 18));

		//textsnake.emplace_back(Point(-2, 14));  // E
		//textsnake.emplace_back(Point(-2, 15));
		//textsnake.emplace_back(Point(-2, 16));
		//textsnake.emplace_back(Point(-2, 17));
		//textsnake.emplace_back(Point(-2, 18));
		//textsnake.emplace_back(Point(-1, 14));
		//textsnake.emplace_back(Point(-1, 16));
		//textsnake.emplace_back(Point(-1, 18));
		//textsnake.emplace_back(Point(0, 14));
		//textsnake.emplace_back(Point(0, 16));
		//textsnake.emplace_back(Point(0, 18));
	}
	void PrintFirst();
	void PrintSecond();
	void PrintThird();
	void PrintText();  // 打印文字
	void ClearText();  // 清除文字并右移一格
	void Action();
private:
	std::deque<Point> startsnake;  // 开始动画中的蛇
	std::vector<Point> textsnake;  // 开始动画中的文字
	int speed;  // 动画的速度
};
#endif