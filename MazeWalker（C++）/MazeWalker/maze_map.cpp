#include<iostream>
#include"maze_map.h"

// 初始化静态变量
char MazeMap::mazeRoad = ' ';
int MazeMap::mazeWidth = 0;
int MazeMap::mazeHeight = 0;
int MazeMap::mazeMapArray[screenHeight][screenWidth];

// 构造函数
// 默认初始化迷宫
MazeMap::MazeMap() :mazeWall('*') {
	mazeWidth = 60;
	mazeHeight = 20;
}

// 重新设置迷宫
void MazeMap::setMazeMap(int *mazeMap, int row,int column) {
	// 设置迷宫宽高
	mazeHeight = row;
	mazeWidth = column;
	// 设置内部路线
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			mazeMapArray[i][j] = *mazeMap;
			mazeMap++;
		}
	}
}

// 绘制地图
void MazeMap::drawMap() const {
	for (int i = 0; i < mazeHeight; i++) {
		for (int j = 0; j < mazeWidth; j++) {
			if (mazeMapArray[i][j] == 1) {
				std::cout << mazeWall;
			}
			else {
				std::cout << mazeRoad;
			}
		}
		std::cout << std::endl;
	}
}

// 检查是否撞墙
bool MazeMap::checkWallOrNot(int mazeX, int mazeY){
	if (mazeMapArray[mazeY][mazeX] == 1) return true;
	else return false;
}

// 检查是否是出口
bool MazeMap::checkMazeOut(int mazeX, int mazeY) {
	if (mazeX == 0 || mazeX == (mazeWidth - 1)) {  // 检查迷宫左右侧
		if (mazeMapArray[mazeY][mazeX] == 0) return true;
	}
	if (mazeY == 0 || mazeY == (mazeHeight - 1)) {  // 检查迷宫上下侧
		if (mazeMapArray[mazeY][mazeX] == 0) return true;
	}
	return false;
}