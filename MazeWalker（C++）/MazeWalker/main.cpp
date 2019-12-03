#include<iostream>
#include"maze_map.h"
#include"maze_people.h"
#include"public.h"

int main() {
	int map[8][9] = { { wall,wall,wall,wall,wall,wall,wall,wall,wall },
					  { wall,wall,wall,wall,road,wall,wall,road,wall },
					  { wall,wall,wall,wall,road,wall,wall,road,road },
					  { wall,wall,wall,wall,road,wall,wall,road,wall },
					  { wall,wall,road,road,road,road,wall,road,wall },
					  { wall,wall,road,wall,wall,road,road,road,wall },
					  { wall,road,road,wall,wall,wall,wall,wall,wall },
					  { wall,road,wall,wall,wall,wall,wall,wall,wall } };
	MazeMap maze_map;
	maze_map.setMazeMap(&map[0][0], 8, 9);
	maze_map.drawMap();
	MazePeople maze_people;
	maze_people.setPersonPosition(1, 7);
	maze_people.start();
	system("pause");
	return road;
}