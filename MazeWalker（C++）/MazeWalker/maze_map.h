#ifndef __MAZE_MAP_H__
#define __MAZE_MAP_H__

#define screenWidth 80
#define screenHeight 25

class MazeMap {
public:
	MazeMap();  // 默认构造函数
	void setMazeMap(int *mazeMap, int row, int column);  // 重新设置迷宫地图
	void drawMap() const;  // 绘制地图
	static bool checkWallOrNot(int mazeX, int mazeY);  // 检测是否遇到迷宫墙壁
	static bool checkMazeOut(int mazeX, int mazeY);
private:
	char mazeWall;
	static char mazeRoad;
	static int mazeWidth;
	static int mazeHeight;
	static int mazeMapArray[screenHeight][screenWidth];

};
#endif