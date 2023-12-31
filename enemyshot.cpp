//敵の弾を操作する関数を書いたファイル
#include "en.h"
#include "DxLib.h"
#include "enemyshot.h"
#include "player.h"
#include "game.h"
#include "enemy.h"

En enemyshot[EnemyShotNum];//弾
int enemyshotimg;
int enemyshotimg2;
//弾の初期化
void initEnemyShot()
{
	enemyshotimg = LoadGraph("enemyshot.png");
	enemyshotimg2 = LoadGraph("火球5.png");
	for (int i = 0; i < EnemyShotNum; i++) {
		enemyshot[i].r = 5;
		enemyshot[i].color = GetColor(0, 255, 0);
		enemyshot[i].fill = true;
		enemyshot[i].enable = false;
	}
}
//弾の更新
void updateEnemyShot()
{
	//弾が有効なときに弾を動かす
	for (int i = 0; i < EnemyShotNum; i++)
	{
		if (enemyshot[i].enable == true) {
			//弾の種類に応じて動き方を変える
			if (enemyshot[i].type == ENEMY4) {
				enemyshot[i].vx = enemyshot[i].vx + enemyshot[i].vvx;
				enemyshot[i].vy = enemyshot[i].vy + enemyshot[i].vvy;
			}
			//誘導弾
			if (enemyshot[i].type == ENEMY5) {
				if (isRight(enemyshot[i], player))
				{
					RotVec(enemyshot[i], 1);//右に1度回転
				}
				else {
					RotVec(enemyshot[i], -1);//左に1度回転
				}
			}
			enemyshot[i].x = enemyshot[i].x + enemyshot[i].vx;
			enemyshot[i].y = enemyshot[i].y + enemyshot[i].vy;
			if (enemyshot[i].type == ENEMY6) {
				if (isRight(enemyshot[i], player))
				{
					RotVec(enemyshot[i], 0.8);//右に1度回転
				}
				else {
					RotVec(enemyshot[i], -0.8);//左に1度回転
				}
			}
			enemyshot[i].x = enemyshot[i].x + enemyshot[i].vx;
			enemyshot[i].y = enemyshot[i].y + enemyshot[i].vy;
			if (enemyshot[i].x >= 600 ||
				enemyshot[i].x < 0 ||
				enemyshot[i].y >= 1000 ||
				enemyshot[i].y < 0)
			{
				enemyshot[i].enable = false;
			}
			if (player.star < 0) {
				if (isHit(player, enemyshot[i]))
				{
					//当たっている
					player.color = enemyshot[i].color;
					player.hp--;
					player.star = 300;
					enemyshot[i].enable = false;
				}
			}
			
		}
	}
}
//弾の描画
void drawEnemyShot()
{
	for (int i = 0; i < EnemyShotNum; i++) {
		if (enemyshot[i].enable == true  && enemyshot[i].type != ENEMY3)
		{
			DrawGraph(enemyshot[i].x -50, enemyshot[i].y - 60, enemyshotimg,true);
		}
	}
	for (int i = 0; i < EnemyShotNum; i++) {
		if (enemyshot[i].type == ENEMY3 && enemyshot[i].enable == true)
		{
			DrawGraph(enemyshot[i].x - 50, enemyshot[i].y - 60, enemyshotimg2, true);
		}
	}
}

