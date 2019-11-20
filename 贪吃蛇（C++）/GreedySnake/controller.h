#ifndef _CONTROLLER_H
#define _CONTROLLER_H

class Controller {
public:
	Controller() :speed(200), key(1), score(0) {}
	void Start();
	void Select();
	void DrawGame();
	int PlayGame();
	void UpdateScore(const int&);
	void ReWriteScore();
	int Menu();
	void Game();
	int GameOver();
private:
	int speed;
	int key;
	int score;
};
#endif