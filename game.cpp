#include "DxLib.h"
#include "game.h"
#include "player.h"
//ゲーム関連の情報
int score = 0;//点数
bool gameOverFlag = false;//ゲームオーバー判定
GameScene scene;
//ゲームの初期化
void initGame()
{

}
//ゲーム内容の更新
void updateGame()
{
	if (player.hp <= 0)
	{
		gameOverFlag = true;
		scene = Gameover;
		PlayMusic("tomoshibi.mp3", DX_PLAYTYPE_LOOP);
	}
}
//ゲーム情報の描画
void drawGame()
{
	DrawFormatString(0, 40, GetColor(255, 255, 0), "スコア %d 点", score);//スコアの増加量の変更はenemy.cppの敵死亡のとこで変えれます

	if (gameOverFlag == true) {
		DrawFormatString(300, 300, GetColor(255, 0, 0), "ゲームオーバー");

	}
}