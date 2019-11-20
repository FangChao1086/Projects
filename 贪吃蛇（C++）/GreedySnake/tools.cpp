#include"tools.h"
#include <windows.h>
#include<stdio.h>

// 设置窗口大小
void SetWindowSize(int cols, int lines) {
	system("title 方同学的贪吃蛇");  // 设置窗口标题
	char cmd[30];
	sprintf(cmd, "mode con cols=%d lines=%d", cols * 2, lines);   // 一个图形■占两个字符，故宽度乘以2
	system(cmd);  // system(mode con cols=88 lines=88)设置窗口宽度和高度
}

// 设置光标位置
void SetCursorPosition(const int x, const int y) {
	COORD position;
	position.X = x * 2;
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

// 设置文本颜色
void SetColor(int colorID) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);
}

// 设置背景色
void SetBackColor() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
							FOREGROUND_BLUE |
							BACKGROUND_BLUE |
							BACKGROUND_GREEN |
							BACKGROUND_RED);
}