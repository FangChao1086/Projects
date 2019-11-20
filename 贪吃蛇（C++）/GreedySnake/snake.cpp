#include"snake.h"
#include<conio.h>
#include"tools.h"
#include<iostream>

// 初始化蛇
void Snake::InitSnake() {
	for (auto& point : snake) {
		point.PrintCircular();
	}
}

// 蛇增长，吃到食物
void Snake::Move() {
	switch (direction) {
	case Direction::UP:
		snake.emplace_back(Point(snake.back().GetX(), snake.back().GetY() - 1));
		break;
	case Direction::DOWN:
		snake.emplace_back(Point(snake.back().GetX(), snake.back().GetY() + 1));
		break;
	case Direction::LEFT:
		snake.emplace_back(Point(snake.back().GetX() - 1, snake.back().GetY()));
		break;
	case Direction::RIGHT:
		snake.emplace_back(Point(snake.back().GetX() + 1, snake.back().GetY()));
		break;
	default:
		break;
	}
	SetColor(14);
	snake.back().PrintCircular();
}

// 蛇移动;	头增长，尾缩短
void Snake::NormalMove() {
	Move();
	snake.front().Clear();
	snake.pop_front();
}

bool Snake::NotOverEdge() {
	return snake.back().GetX() < 30 &&
			snake.back().GetY() < 30 &&
			snake.back().GetX() > 1 &&
			snake.back().GetY() > 1;
}

bool Snake::NotHitItself() {
	std::deque<Point>::size_type cnt = 1;
	Point *head = new Point(snake.back().GetX(), snake.back().GetY());  // 获得头部坐标
	for (auto& point : snake) {
		if (!(point == *head)) ++cnt;
		else break;
	}
	delete head;
	if (cnt == snake.size()) return true;
	else return false;
}

bool Snake::ChangeDirection() {
	char ch;
	if (_kbhit()) {  // kbhit函数返回值有2个
		ch = _getch();
		switch (ch) {
		case -32:
			ch = _getch();
			switch (ch) {
			case 72:  // up
				if (direction != Direction::DOWN)  // 如果方向与当前运动方向相反，无效
					direction = Direction::UP;
				break;
			case 80:  // down
				if (direction != Direction::UP)  // 如果方向与当前运动方向相反，无效
					direction = Direction::DOWN;
				break;
			case 75:  // left
				if (direction != Direction::RIGHT)  // 如果方向与当前运动方向相反，无效
					direction = Direction::LEFT;
				break;
			case 77:  // right
				if (direction != Direction::LEFT)  // 如果方向与当前运动方向相反，无效
					direction = Direction::RIGHT;
				break;
			default:
				break;
			}
			return true;
		case 27:  // ESC
			return false;
		default:
			return true;
		}
	}
	return true;
}

bool Snake::GetFood(const Food& cfood) {
	if (snake.back().GetX() == cfood.x && snake.back().GetY() == cfood.y) {
		return true;
	}
	else 
		return false;
}

bool Snake::GetBigFood(Food& cfood) {
	if (snake.back().GetX() == cfood.big_x && snake.back().GetY() == cfood.big_y) {
		cfood.big_flag = false;
		cfood.big_x = 0;
		cfood.big_y = 0;
		SetCursorPosition(1, 0);
		std::cout << "                                                            ";
		return true;
	}
	else
		return false;
}