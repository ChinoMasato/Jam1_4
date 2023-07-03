#pragma once
enum GameScene
{
	Title,
	Game,
	Gameover
};

extern int score;//点数
extern bool gameOverFlag;//ゲームオーバー判定
extern GameScene scene;
void initGame();//ゲーム内容の更新
void updateGame();//ゲーム内容の更新
void drawGame();//ゲーム関連の描画