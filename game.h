#pragma once
enum GameScene
{
	Title,
	Game,
	Gameover
};

extern int score;//�_��
extern bool gameOverFlag;//�Q�[���I�[�o�[����
extern GameScene scene;
void initGame();//�Q�[�����e�̍X�V
void updateGame();//�Q�[�����e�̍X�V
void drawGame();//�Q�[���֘A�̕`��