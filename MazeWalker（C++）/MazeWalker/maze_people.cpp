#include<iostream>
#include"maze_people.h"
#include"maze_map.h"
#include"windows.h"


// 构造函数
MazePeople::MazePeople():mazePeople('o') {
	nowX = 1, nowY = 1;
	preX = 10000, preY = 10000;
	outOrNot = false;
	forward = UP;
}
MazePeople::MazePeople(int currentX, int currentY):mazePeople('o') {
	nowX = currentX, nowY = currentY;
	preX = 10000, preY = 10000;
	outOrNot = false;
	forward = UP;
}
MazePeople::MazePeople(int currentX, int currentY, objectiveDirections myForward) :mazePeople('o') {
	nowX = currentX, nowY = currentY;
	preX = 10000, preY = 10000;
	outOrNot = false;
	forward = myForward;
}


MazePeople &MazePeople::setPersonPosition(int coordX, int coordY) {
	nowX = coordX, nowY = coordY;
	return *this;
}

void MazePeople::gotoxy(int x, int y) {
	COORD cd;
	cd.X = x; 
	cd.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cd);
}

void MazePeople::goAhead() {
	preX = nowX, preY = nowY;  // 存当前点
	// 朝当前点前方（可能是上下左右任意方向）走一步
	switch (forward) {
	case UP:
		nowX = nowX, nowY = nowY - 1;  // 更新当前点
		break;
	case DOWN:
		nowX = nowX, nowY = nowY + 1;  // 更新当前点
		break;
	case LEFT:
		nowX = nowX - 1, nowY = nowY;  // 更新当前点
		break;
	case RIGHT:
		nowX = nowX + 1, nowY = nowY;  // 更新当前点
		break;
	default:
		std::cout << "方向不明，不能前进" << std::endl;
	}

	// 动画效果
	gotoxy(preX, preY);
	std::cout << ' ';
	gotoxy(nowX, nowY);
	std::cout << mazePeople;
	Sleep(500);

	// 检查是否到达出口
	if (MazeMap::checkMazeOut(nowX, nowY)) {
		gotoxy(0, 22);
		std::cout << "恭喜你，成功" << std::endl;
		outOrNot = true;
	}
}

bool MazePeople::moveForward() {
	// 检查当前位置是否合法
	if (MazeMap::checkWallOrNot(nowX, nowY)) {
		gotoxy(0, 23);
		std::cout << "检测到当前的起始位置是墙壁，请重新设定"<<std::endl;
		outOrNot = true;
		return false;
	}

	// 判断；如果前一个位置是10000,则在当前位置绘制人
	if (preX == 10000 && preY == 10000) {
		gotoxy(nowX, nowY);
		std::cout << mazePeople;
		Sleep(3000);
	}

	// 行走运行核心
	// > 检查右侧是否是墙？
	//	> 是墙  >> 检查前方是否是墙？
	//					>> 不是墙 -》前进，检查是否是出口
	//  > 不是墙 -》进行方向旋转
	int rightX, rightY;  // x:width-；y:height|
	int forwardX, forwardY;
	switch (forward) {
	case UP:
		rightX = nowX + 1, rightY = nowY;  // 当前点的右边
		forwardX = nowX, forwardY = nowY - 1;
		break;
	case DOWN:
		rightX = nowX - 1, rightY = nowY;
		forwardX = nowX, forwardY = nowY + 1;
		break;
	case LEFT:
		rightX = nowX, rightY = nowY - 1;  // 当前点的右边
		forwardX = nowX - 1, forwardY = nowY;
		break;
	case RIGHT:
		rightX = nowX, rightY = nowY + 1;
		forwardX = nowX + 1, forwardY = nowY;
		break;
	}

	// 如果右侧是墙
	if (MazeMap::checkWallOrNot(rightX, rightY)) {  // 当前点的右边，如果是墙
		if (MazeMap::checkWallOrNot(forwardX, forwardY)) {  // 当前点的前方，如果是墙
			//向左旋转
			switch (forward) {
			case UP:
				forward = LEFT;
				break;
			case LEFT:
				forward = DOWN;
				break;
			case DOWN:
				forward = RIGHT;
				break;
			case RIGHT:
				forward = UP;
				break;
			default:
				std::cout << "方向错误" << std::endl;
			}
			return 0;
		}
		else {
			goAhead();  // 前进一步
			return 1;
		}
	}
	else {  // 如果右侧不是墙;方向右边旋转，再继续前进
		Sleep(3000);
		// 向右旋转
		switch (forward) {
		case UP:
			forward = RIGHT;
			break;
		case RIGHT:
			forward = DOWN;
			break;
		case DOWN:
			forward = LEFT;
			break;
		case LEFT:
			forward = UP;
			break;
		default:
			std::cout << "方向错误" << std::endl;
		}
		goAhead();
		return 1;
	}
}

void MazePeople::start() {
	int i = 0;
	while (!outOrNot) {
		i += moveForward();
		gotoxy(0, 15);
		std::cout << i;
	}
}