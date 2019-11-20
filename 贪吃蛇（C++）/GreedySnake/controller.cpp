#include<iostream>
#include<time.h>
#include<conio.h>
#include<windows.h>
#include"controller.h"
#include"tools.h"
#include"start_interface.h"
#include"map.h"
#include"snake.h"
#include"food.h"

void Controller::Start() {
	SetWindowSize(41, 32);  // 设置窗口大小
	SetColor(2);  // 设置动画颜色
	StartInterface *start = new StartInterface();
	start->Action();
	delete start;
	
	// 设置光标位置，输出提示
	SetCursorPosition(13, 26);
	std::cout << "Press any key to start... ";
	SetCursorPosition(13, 27);
	system("pause");
}

// 选择界面
void Controller::Select() {
	SetColor(3);
	SetCursorPosition(13, 26);
	std::cout << "                          ";
	SetCursorPosition(13, 27);
	std::cout << "                          ";
	SetCursorPosition(6, 21);
	std::cout << "请选择游戏难度：";
	SetCursorPosition(6, 22);
	std::cout << "(上下键选择，回车确认)";
	SetCursorPosition(27, 22);
	SetBackColor();  // 设置选项的背景色表示选中
	std::cout << "简单模式";
	SetCursorPosition(27, 24);
	SetColor(3);
	std::cout << "普通模式";
	SetCursorPosition(27, 26);
	std::cout << "困难模式";
	SetCursorPosition(27, 28);
	std::cout << "炼狱模式";
	SetCursorPosition(0, 31);
	score = 0;

	// 方向键选择模块
	int ch;  // 记录键入值
	key = 1;  // 记录选中项，初始选择第一个
	bool flag = false;  // 记录是否键入Enter,初始值为否
	while ((ch = _getch())) {
		switch (ch)  // 检测输入键
		{
		case 72:  // up上方向键
			if (key > 1)  // 当此时选中项为第一项时，up上方向键无效
			{
				switch (key)
				{
				case 2:
					SetCursorPosition(27, 22);  // 给待选中的模式设置背景色
					SetBackColor();
					std::cout << "简单模式";
					SetCursorPosition(27, 24);  // 取消已选种普通模式的背景色
					SetColor(3);
					std::cout << "普通模式";
					key--;
					break;
				case 3:
					SetCursorPosition(27, 24);
					SetBackColor();
					std::cout << "普通模式";
					SetCursorPosition(27, 26);
					SetColor(3);
					std::cout << "困难模式";
					key--;
					break;
				case 4:
					SetCursorPosition(27, 26);
					SetBackColor();
					std::cout << "困难模式";
					SetCursorPosition(27, 28);
					SetColor(3);
					std::cout << "炼狱模式";
					key--;
					break;
				}
			}
			break;
		case 80:  // down下方向键
			if (key < 4)
			{
				switch (key)
				{
				case 1:
					SetCursorPosition(27, 24);  
					SetBackColor();
					std::cout << "普通模式";
					SetCursorPosition(27, 22);
					SetColor(3);
					std::cout << "简单模式";
					key++;
					break;
				case 2:
					SetCursorPosition(27, 26);
					SetBackColor();
					std::cout << "困难模式";
					SetCursorPosition(27, 24);
					SetColor(3);
					std::cout << "普通模式";
					key++;
					break;
				case 3:
					SetCursorPosition(27, 28);
					SetBackColor();
					std::cout << "炼狱模式";
					SetCursorPosition(27, 26);
					SetColor(3);
					std::cout << "困难模式";
					key++;
					break;
				}
			}
			break;
		case 13:  // enter回车键
			flag = true;
			break;
		default:  // 无效按键
			break;
		}
		if (flag) break;  // 如果检测到Enter,退出检查输入循环
		SetCursorPosition(0, 31);  // 将光标置于左下角，避免游戏体验不好
	}

	// 根据key值(模式简易难度)设置蛇的移动速度
	switch (key) {
	case 1:
		speed = 135;
		break;
	case 2:
		speed = 120;
		break;
	case 3:
		speed = 60;
		break;
	case 4:
		speed = 30;
		break;
	default:
		break;
	}
}

// 绘制游戏界面
void Controller::DrawGame() {
	system("cls");  // 清屏

	// 绘制地图
	SetColor(3);
	Map *init_map = new Map();
	init_map->PrintInitmap();
	delete init_map;

	// 绘制侧边栏
	SetColor(3);
	SetCursorPosition(33, 1);
	std::cout << "Greedy Snake";
	SetCursorPosition(34, 2);
	std::cout << "贪吃蛇";
	SetCursorPosition(31, 4);
	std::cout << "难度：";
	SetCursorPosition(36, 5);
	switch (key) {
	case 1:
		std::cout << "简单模式";
		break;
	case 2:
		std::cout << "普通模式";
		break;
	case 3:
		std::cout << "困难模式";
		break;
	case 4:
		std::cout << "炼狱模式";
		break;
	default:
		break;
	}
	SetCursorPosition(31, 7);
	std::cout << "得分：";
	SetCursorPosition(37, 8);
	std::cout << "    0";
	SetCursorPosition(33, 13);
	std::cout << "方向键移动";
	SetCursorPosition(33, 15);
	std::cout << "ESC键暂停";
}

int Controller::PlayGame() {
	// 初始化蛇与食物
	Snake *csnake = new Snake();
	Food *cfood = new Food();
	SetColor(6);
	csnake->InitSnake();
	srand((unsigned)time(NULL));  //随机化食物出现的位置
	cfood->DrawFood(*csnake);

	// 游戏循环
	while (csnake->NotOverEdge() && csnake->NotHitItself()) {  // 没有撞墙也没有撞到自身
		// 调出选择菜单
		if (!csnake->ChangeDirection()) {  // 按ESC键时
			int tmp = Menu();  // 绘制菜单，并得到返回值
			switch (tmp) {
			case 1:  // 继续游戏
				break;
			case 2:  // 重新开始
				delete csnake;
				delete cfood;
				return 1;
			case 3:  // 退出游戏
				delete csnake;
				delete cfood;
				return 2;
			default:
				break;
			}
		}
		if (csnake->GetFood(*cfood)) {
			csnake->Move();  //Move 蛇增长 
			UpdateScore(1);
			ReWriteScore();
			cfood->DrawFood(*csnake);  // 
		}
		else {
			csnake->NormalMove();
		}
		if (csnake->GetBigFood(*cfood)) {  // 吃到限时食物
			csnake->Move();
			UpdateScore(cfood->GetProgressBar() / 5);  // 分数根据时间进度条确定
			ReWriteScore();
		}
		if (cfood->GetBigFlag()) {  // 如果存在限时食物，则让食物闪烁
			cfood->FlashBigFood();
		}
		Sleep(speed);  // 制造蛇的移动效果
	}

	// 蛇死亡
	delete csnake;
	delete cfood;
	int tmp = GameOver();  // 绘制游戏结束界面
	switch (tmp) {
	case 1:
		return 1;  // 重新开始
	case 2:
		return 2;  // 退出游戏
	default:
		return 2;
	}
}

// 更新得分
void Controller::UpdateScore(const int& tmp) {
	score += key * 10 * tmp;
}

// 重绘得分
void Controller::ReWriteScore() {
	// 为保持分数尾部对齐，将最大分数设置为6位
	SetCursorPosition(37, 8);
	SetColor(1);
	int bit = 0;
	int tmp = score;
	while (tmp != 0) {
		++bit;
		tmp /= 10;
	}
	for (int i = 0; i < (6 - bit); ++i) {
		std::cout << " ";
	}
	std::cout << score;
}

// 选择菜单（按下ESC键）
int Controller::Menu() {
	// 绘制菜单
	SetColor(11);
	SetCursorPosition(32, 19);
	std::cout << "菜单：";
	Sleep(100);
	SetCursorPosition(34, 21);
	SetBackColor();
	std::cout << "继续游戏";
	Sleep(100);
	SetCursorPosition(34, 23);
	SetColor(11);
	std::cout << "重新开始";
	Sleep(100);
	SetCursorPosition(34, 25);
	std::cout << "退出游戏";
	SetCursorPosition(0, 31);

	//选择部分
	int ch;  // 输入值
	int tmp_key = 1;  // 选中项
	bool flag = false;
	while ((ch = _getch())) {
		switch (ch) {
		case 72:  // up
			if (tmp_key > 1) {
				switch (tmp_key) {
				case 2:
					SetCursorPosition(34, 21);
					SetBackColor();
					std::cout << "继续游戏";
					SetCursorPosition(34, 23);
					SetColor(11);
					std::cout << "重新开始";
					tmp_key--;
					break;
				case 3:
					SetCursorPosition(34, 23);
					SetBackColor();
					std::cout << "重新开始";
					SetCursorPosition(34, 25);
					SetColor(11);
					std::cout << "退出游戏";
					tmp_key--;
					break;
				}
			}
			break;
		case 80:  // down
			if (tmp_key < 3) {
				switch (tmp_key) {
				case 1:
					SetCursorPosition(34, 23);
					SetBackColor();
					std::cout << "重新开始";
					SetCursorPosition(34, 21);
					SetColor(11);
					std::cout << "继续游戏";
					tmp_key++;
					break;
				case 2:
					SetCursorPosition(34, 25);
					SetBackColor();
					std::cout << "退出游戏";
					SetCursorPosition(34, 23);
					SetColor(11);
					std::cout << "重新开始";
					tmp_key++;
					break;
				}
			}
			break;
		case 13:  // Enter
			flag = true;
			break;
		default:
			break;
		}
		if (flag) {
			break;
		}
		SetCursorPosition(0, 31);
	}
	if (tmp_key == 1) {  // 选择继续游戏，则去除菜单
		SetCursorPosition(32, 19);
		std::cout << "      ";
		SetCursorPosition(34, 21);
		std::cout << "        ";
		SetCursorPosition(34, 23);
		std::cout << "        ";
		SetCursorPosition(34, 25);
		std::cout << "        ";
	}
	return tmp_key;
}

void Controller::Game() {
	Start();
	while (true) {  // 游戏可以视为一个死循环，游戏结束则循环结束
		Select();  // 选择界面
		DrawGame();  // 绘制游戏界面
		int tmp = PlayGame();
		if (tmp == 1) {  // 返回值为1时重新开始游戏
			system("cls");
			continue;
		}
		else if (tmp == 2) {  // 返回值为2时退出游戏
			break;
		}
		else {
			break;
		}
	}
}

int Controller::GameOver() {
	// 绘制游戏结束界面
	Sleep(500);
	SetColor(11);
	SetCursorPosition(10, 8);
	std::cout << " --------------------------------------------- ";
	Sleep(30);
	SetCursorPosition(9, 9);
	std::cout << "  |                Game Over !!!                |";
	Sleep(30);
	SetCursorPosition(9, 10);
	std::cout << "  |                                             |";
	Sleep(30);
	SetCursorPosition(9, 11);
	std::cout << "  |                抱歉，你挂了                 |";
	Sleep(30);
	SetCursorPosition(9, 12);
	std::cout << "  |                                             |";
	Sleep(30);
	SetCursorPosition(9, 13);
	std::cout << "  |              你的分数为：                   |";
	SetCursorPosition(24, 13);
	std::cout << score;
	Sleep(30);
	SetCursorPosition(9, 14);
	std::cout << "  |                                             |";
	Sleep(30);
	SetCursorPosition(9, 15);
	std::cout << "  |   是否还想再来一局？                        |";
	Sleep(30);
	SetCursorPosition(9, 16);
	std::cout << "  |                                             |";
	Sleep(30);
	SetCursorPosition(9, 17);
	std::cout << "  |                                             |";
	Sleep(30);
	SetCursorPosition(9, 18);
	std::cout << "  |   嗯，好的        不了，还是学习有意思      |";
	Sleep(30);
	SetCursorPosition(9, 19);
	std::cout << "  |                                             |";
	Sleep(30);
	SetCursorPosition(9, 20);
	std::cout << "  |                                             |";
	Sleep(30);
	SetCursorPosition(10, 21);
	std::cout << " --------------------------------------------- ";

	Sleep(100);
	SetCursorPosition(12, 18);
	SetBackColor();
	std::cout << "嗯，好的";
	SetCursorPosition(0, 31);

	//选择部分
	int ch;  // 是否存在输入
	int tmp_key = 1;  // 检测输入的值
	bool flag = false;
	while ((ch = _getch())) {
		switch (ch) {
		case 75:  // LEFT
			if (tmp_key > 1) {
				SetCursorPosition(12, 18);
				SetBackColor();
				std::cout << "嗯，好的";
				SetCursorPosition(20, 18);
				SetColor(11);
				std::cout << "不了，还是学习有意思";
				tmp_key--;
			}
			break;
		case 77:  // RIGHT
			if (tmp_key < 2) {
				SetCursorPosition(20, 18);
				SetBackColor();
				std::cout << "不了，还是学习有意思";
				SetCursorPosition(12, 18);
				SetColor(11);
				std::cout << "嗯，好的";
				tmp_key++;
			}
			break;
		case 13:  // ENTER
			flag = true;
			break;
		default:
			break;
		}
		SetCursorPosition(0, 31);
		if (flag) break;
	}

	SetColor(11);
	switch (tmp_key) {
	case 1:
		return 1;  // 重新开始
	case 2:
		return 2;  // 退出游戏
	default:
		return 1;
	}
}