//敵を操作する関数を書いたファイル
#include "en.h"
#include "DxLib.h"
#include "math.h"
#include "shot.h"
#include "enemyshot.h"
#include "enemy.h"
#include "player.h"
#include "effect.h"
#include "game.h"
#include "UI.h"

extern bool gameOverFlag;//ゲームオーバー判定
En enemy[EnemyNum];//敵

int explodese;//爆発SE
int explode1se;//爆発SE

int enemytenshotse;//敵ショットSE
int bossse;//ボス出現SE
int gameOverse;//ゲームオーバーSE
int gameclearse;//ゲームクリアSE

int enemyimg;
int enemyimg2;
int bossimg;
//敵の初期化
void initEnemy()
{
	explodese = LoadSoundMem("爆発2 (1).mp3");
	explode1se = LoadSoundMem("爆発4.mp3");
	gameOverse = LoadSoundMem("tomoshibi.mp3");
	gameclearse = LoadSoundMem("victory.mp3");
	enemytenshotse = LoadSoundMem("火炎魔法1.mp3");
	bossse = LoadSoundMem("警報2.mp3");

	enemyimg = LoadGraph("mob.png");
	enemyimg2 = LoadGraph("mob2.png");
	bossimg = LoadGraph("boss.png");

	//1体目の敵
	enemy[0].x = 100;
	enemy[0].y = -1100;
	enemy[0].r = 30;
	enemy[0].color = GetColor(255, 0, 0);
	enemy[0].fill = true;
	enemy[0].enable = true;
	enemy[0].vx = 0.0;
	enemy[0].vy = 1.0;
	enemy[0].type = ENEMY1;
	enemy[0].hp = 1;


	//2体目の敵
	enemy[1].x = 400;
	enemy[1].y = -1100;
	enemy[1].r = 30;
	enemy[1].color = GetColor(255, 0, 0);
	enemy[1].fill = true;
	enemy[1].enable = true;
	enemy[1].vx = 0.0;
	enemy[1].vy = 1.0;
	enemy[1].type = ENEMY1;
	enemy[1].hp = 1;

	//3体目の敵
	enemy[2].x = 300;
	enemy[2].y = -2000;
	enemy[2].r = 30;
	enemy[2].color = GetColor(255, 0, 0);
	enemy[2].fill = true;
	enemy[2].enable = true;
	enemy[2].vx = 0.0;
	enemy[2].vy = 1.0;
	enemy[2].type = ENEMY2;
	enemy[2].hp = 1;

	//4体目の敵
	enemy[3].x = 200;
	enemy[3].y = -2400;
	enemy[3].r = 30;
	enemy[3].color = GetColor(255, 0, 0);
	enemy[3].fill = true;
	enemy[3].enable = true;
	enemy[3].vx = 0.0;
	enemy[3].vy = 1.0;
	enemy[3].type = ENEMY4;
	enemy[3].hp = 1;

	//5体目の敵
	enemy[4].x = 500;
	enemy[4].y = -2400;
	enemy[4].r = 30;
	enemy[4].color = GetColor(255, 0, 0);
	enemy[4].fill = true;
	enemy[4].enable = true;
	enemy[4].vx = 0.0;
	enemy[4].vy = 1.0;
	enemy[4].type = ENEMY3;
	enemy[4].hp = 1;

	//6体目の敵
	enemy[5].x = 300;
	enemy[5].y = -3400;
	enemy[5].r = 30;
	enemy[5].color = GetColor(255, 0, 0);
	enemy[5].fill = true;
	enemy[5].enable = true;
	enemy[5].vx = 0.0;
	enemy[5].vy = 1.0;
	enemy[5].type = ENEMY3;
	enemy[5].hp = 1;

	//7体目の敵
	enemy[6].x = 300;
	enemy[6].y = -4000;
	enemy[6].r = 30;
	enemy[6].color = GetColor(255, 0, 0);
	enemy[6].fill = true;
	enemy[6].enable = true;
	enemy[6].vx = 0.0;
	enemy[6].vy = 1.0;
	enemy[6].type = ENEMY4;
	enemy[6].hp = 1;

	//8体目の敵
	enemy[7].x = 200;
	enemy[7].y = -4200;
	enemy[7].r = 30;
	enemy[7].color = GetColor(255, 0, 0);
	enemy[7].fill = true;
	enemy[7].enable = true;
	enemy[7].vx = 0.0;
	enemy[7].vy = 1.0;
	enemy[7].type = ENEMY4;
	enemy[7].hp = 1;

	//9体目の敵
	enemy[8].x = 500;
	enemy[8].y = -4200;
	enemy[8].r = 30;
	enemy[8].color = GetColor(255, 0, 0);
	enemy[8].fill = true;
	enemy[8].enable = true;
	enemy[8].vx = 0.0;
	enemy[8].vy = 1.0;
	enemy[8].type = ENEMY4;
	enemy[8].hp = 1;

	//10体目の敵
	enemy[9].x = 300;
	enemy[9].y = -5000;
	enemy[9].r = 30;
	enemy[9].color = GetColor(255, 0, 0);
	enemy[9].fill = true;
	enemy[9].enable = true;
	enemy[9].vx = 0.0;
	enemy[9].vy = 1.0;
	enemy[9].type = ENEMY5;
	enemy[9].hp = 1;

	//11体目の敵
	enemy[10].x = 450;
	enemy[10].y = -9000;
	enemy[10].r = 30;
	enemy[10].color = GetColor(255, 0, 0);
	enemy[10].fill = true;
	enemy[10].enable = true;
	enemy[10].vx = 0.0;
	enemy[10].vy = 1.0;
	enemy[10].type = ENEMY3;
	enemy[10].hp = 1;

	enemy[11].x = 100;
	enemy[11].y = -5500;
	enemy[11].r = 30;
	enemy[11].color = GetColor(255, 0, 0);
	enemy[11].fill = true;
	enemy[11].enable = true;
	enemy[11].vx = 0.0;
	enemy[11].vy = 1.0;
	enemy[11].type = ENEMY4;
	enemy[11].hp = 1;

	enemy[12].x = 500;
	enemy[12].y = -5500;
	enemy[12].r = 30;
	enemy[12].color = GetColor(255, 0, 0);
	enemy[12].fill = true;
	enemy[12].enable = true;
	enemy[12].vx = 0.0;
	enemy[12].vy = 1.0;
	enemy[12].type = ENEMY4;
	enemy[12].hp = 1;

	enemy[13].x = 300;
	enemy[13].y = -6200;
	enemy[13].r = 30;
	enemy[13].color = GetColor(255, 0, 0);
	enemy[13].fill = true;
	enemy[13].enable = true;
	enemy[13].vx = 0.0;
	enemy[13].vy = 1.0;
	enemy[13].type = ENEMY5;
	enemy[13].hp = 1;

	enemy[14].x = 300;
	enemy[14].y = -6700;
	enemy[14].r = 30;
	enemy[14].color = GetColor(255, 0, 0);
	enemy[14].fill = true;
	enemy[14].enable = true;
	enemy[14].vx = 0.0;
	enemy[14].vy = 1.0;
	enemy[14].type = ENEMY3;
	enemy[14].hp = 1;

	enemy[15].x = 200;
	enemy[15].y = -7000;
	enemy[15].r = 30;
	enemy[15].color = GetColor(255, 0, 0);
	enemy[15].fill = true;
	enemy[15].enable = true;
	enemy[15].vx = 0.0;
	enemy[15].vy = 1.0;
	enemy[15].type = ENEMY2;
	enemy[15].hp = 1;

	enemy[16].x = 400;
	enemy[16].y = -7000;
	enemy[16].r = 30;
	enemy[16].color = GetColor(255, 0, 0);
	enemy[16].fill = true;
	enemy[16].enable = true;
	enemy[16].vx = 0.0;
	enemy[16].vy = 1.0;
	enemy[16].type = ENEMY2;
	enemy[16].hp = 1;

	enemy[17].x = 100;
	enemy[17].y = -7500;
	enemy[17].r = 30;
	enemy[17].color = GetColor(255, 0, 0);
	enemy[17].fill = true;
	enemy[17].enable = true;
	enemy[17].vx = 0.0;
	enemy[17].vy = 1.0;
	enemy[17].type = ENEMY5;
	enemy[17].hp = 1;

	enemy[18].x = 500;
	enemy[18].y = -7500;
	enemy[18].r = 30;
	enemy[18].color = GetColor(255, 0, 0);
	enemy[18].fill = true;
	enemy[18].enable = true;
	enemy[18].vx = 0.0;
	enemy[18].vy = 1.0;
	enemy[18].type = ENEMY5;
	enemy[18].hp = 1;

	enemy[19].x = 300;
	enemy[19].y = -8000;
	enemy[19].r = 30;
	enemy[19].color = GetColor(255, 0, 0);
	enemy[19].fill = true;
	enemy[19].enable = true;
	enemy[19].vx = 0.0;
	enemy[19].vy = 1.0;
	enemy[19].type = ENEMY6;
	enemy[19].hp = 1;

	enemy[20].x = 200;
	enemy[20].y = -8300;
	enemy[20].r = 30;
	enemy[20].color = GetColor(255, 0, 0);
	enemy[20].fill = true;
	enemy[20].enable = true;
	enemy[20].vx = 0.0;
	enemy[20].vy = 1.0;
	enemy[20].type = ENEMY5;
	enemy[20].hp = 1;

	enemy[21].x = 400;
	enemy[21].y = -8300;
	enemy[21].r = 30;
	enemy[21].color = GetColor(255, 0, 0);
	enemy[21].fill = true;
	enemy[21].enable = true;
	enemy[21].vx = 0.0;
	enemy[21].vy = 1.0;
	enemy[21].type = ENEMY5;
	enemy[21].hp = 1;

	enemy[22].x = 300;
	enemy[22].y = -8600;
	enemy[22].r = 30;
	enemy[22].color = GetColor(255, 0, 0);
	enemy[22].fill = true;
	enemy[22].enable = true;
	enemy[22].vx = 0.0;
	enemy[22].vy = 1.0;
	enemy[22].type = ENEMY2;
	enemy[22].hp = 1;

	enemy[23].x = 150;
	enemy[23].y = -9000;
	enemy[23].r = 30;
	enemy[23].color = GetColor(255, 0, 0);
	enemy[23].fill = true;
	enemy[23].enable = true;
	enemy[23].vx = 0.0;
	enemy[23].vy = 1.0;
	enemy[23].type = ENEMY3;
	enemy[23].hp = 1;
	
	enemy[24].x = 300;
	enemy[24].y = -10000;
	enemy[24].r = 100;
	enemy[24].color = GetColor(255, 255, 0);
	enemy[24].fill = true;
	enemy[24].enable = true;
	enemy[24].vx = 0.0;
	enemy[24].vy = 1.0;
	enemy[24].type = ENEMY6;
	enemy[24].hp = 5;

	for (int i = 0; i < EnemyNum; i++)
	{
		enemy[i].shp = enemy[i].hp;
	}//最大HPの初期化
}
//真っすぐ弾を撃つ
void straightShot(int rad, En ene, int shifty)
{
	//弾が無効なときのみ初期値をセットし有効にする
	for (int j = 0; j < EnemyShotNum; j++)
	{
		//撃てる弾をみつける
		if (enemyshot[j].enable == false) {
			//弾を撃つ
			enemyshot[j].x = ene.x;
			enemyshot[j].y = ene.y + shifty;
			double PI = 3.14159265358979323846264338;
			double minrad = PI / 180.0;//1度のラジアン
			double speed = 3.0;//速度
			enemyshot[j].vx = speed * cos(minrad * rad);
			enemyshot[j].vy = speed * sin(minrad * rad);
			enemyshot[j].enable = true;
			enemyshot[j].type = ene.type;
			enemyshot[j].vvx = -enemyshot[j].vx * 0.002;
			enemyshot[j].vvy = -enemyshot[j].vy * 0.002;
			break;
		}
	}
}

//狙って撃つ
void aimShot(En ene)
{
	//弾を撃てる状態
//弾が無効なときのみ初期値をセットし有効にする
	for (int j = 0; j < EnemyShotNum; j++)
	{
		//撃てる弾をみつける
		if (enemyshot[j].enable == false) {
			//弾を撃つ
			enemyshot[j].x = ene.x;
			enemyshot[j].y = ene.y;

			double speed = 2.0;//速度
			double dx = player.x - ene.x;//プレイヤーと敵のx方向の距離
			double dy = player.y - ene.y;//プレイヤーと敵のy方向の距離
			double d = sqrt(dx * dx + dy * dy);//敵とプレイヤーとの距離
			enemyshot[j].vx = speed * (dx / d);//xの移動量
			enemyshot[j].vy = speed * (dy / d);//yの移動量
			enemyshot[j].enable = true;
			enemyshot[j].type = ene.type;
			enemyshot[j].vvx = enemyshot[j].vx * 0.05;
			enemyshot[j].vvy = enemyshot[j].vy * 0.05;
			break;
		}
	}
}
//爆発発生関数
void explosion(En ene)
{
	for (int i = 0; i < EffectNum; i++)
	{
		if (effe[i].enable == false)
		{
			effe[i].enable = true;
			effe[i].x = ene.x - 60;
			effe[i].y = ene.y - 60;
			effe[i].animeNo = 0;
			break;
		}
	}
}
//敵の更新
void updateEnemy()
{
	for (int i = 0; i < EnemyNum; i++) {
		if (enemy[i].enable == true) {
			//敵を自動で動かす
			if (enemy[i].pattern.find(enemy[i].counter) != enemy[i].pattern.end())
			{
				enemy[i].vx = enemy[i].pattern[enemy[i].counter].vx;
				enemy[i].vy = enemy[i].pattern[enemy[i].counter].vy;
			}
			enemy[i].counter++;
			enemy[i].x = enemy[i].x + enemy[i].vx;
			enemy[i].y = enemy[i].y + enemy[i].vy;

			//弾を発射する
			if (canEnemyShot(enemy[i]))
			{
				//三本ショット
				if (enemy[i].type == ENEMY1) {
					straightShot(90, enemy[i], 0);
					straightShot(85, enemy[i], 0);
					straightShot(95, enemy[i], 0);
				}
				if (enemy[i].type == ENEMY2) {
					straightShot(90, enemy[i], -10);
					straightShot(90, enemy[i], 10);
				}
				if (enemy[i].type == ENEMY3) {
					aimShot(enemy[i]);
				}
				if (enemy[i].type == ENEMY4) {
					straightShot(90, enemy[i], 0);
				}
				if (enemy[i].type == ENEMY5) {
					straightShot(90, enemy[i], -10);
					straightShot(90, enemy[i], 10);
				}
				if (enemy[i].type == ENEMY6) {
					straightShot(90, enemy[i], 0);
					straightShot(85, enemy[i], 0);
					straightShot(95, enemy[i], 0);
					straightShot(80, enemy[i], 0);
					straightShot(100, enemy[i], 0);
				}

				enemy[i].cooltime = 30;
			}

			//ボス出現SE
			if (enemy[24].y == 0)
			{
				PlaySoundMem(bossse, DX_PLAYTYPE_BACK);
			}

			if (player.star < 0)
			{
				if (isHit(player, enemy[i]))
				{
					//当たっている
					player.color = enemy[i].color;
					player.hp--;
					player.star = 300;
					PlaySoundMem(gameOverse, DX_PLAYTYPE_BACK);
				}
				
			}

			for (int j = 0; j < ShotNum; j++) {
				//敵と弾との当たり判定
				if (shot[j].enable == true) {
					if (isHit(shot[j], enemy[i]))
					{
						//当たっている
						shot[j].enable = false;//弾を無効
						enemy[i].hp--;
					}
				}

			}
			if (bomb.enable == true) {
				if (isHit(bomb, enemy[i]))
				{
					//当たっている
					if (bomb.z == 0) {
						bomb.z = 1;
					}
					enemy[i].hp--;
				}
			}
			//敵死亡
			if (enemy[i].hp <= 0)
			{


				//スコアの増加量を変えるならここ
				score += 1;
				enemy[i].enable = false;//敵を無効
				PlaySoundMem(explodese, DX_PLAYTYPE_BACK);
				PlaySoundMem(explode1se, DX_PLAYTYPE_BACK);
				explosion(enemy[i]);//爆発
				A_light(enemy[i]);
			}
			//銃を冷やす処理
			if (enemy[i].cooltime > 0) {
				enemy[i].cooltime--;
			}
		}
	}
}
void updateBoss()
{
	if (enemy[24].y == 100)
	{
		enemy[24].y = 101;
		enemy[24].vy = 0;
		enemy[24].vx = 2;
	}
	if (enemy[24].x < 30)
	{
		enemy[24].x = 40;
		enemy[24].vx = -enemy[24].vx;
	}
	if(enemy[24].x > 570)
	{
		enemy[24].x = 560;
		enemy[24].vx = -enemy[24].vx;
	}
}


//敵の描画
void drawEnemy()
{
	for (int i = 0; i < EnemyNum; i++) {
		if (enemy[i].enable == true) {
			DrawGraph(enemy[i].x - 25, enemy[i].y - 27, enemyimg, true);
			//DrawCircle(enemy[i].x, enemy[i].y, enemy[i].r, enemy[i].color, enemy[i].fill);
			drawEHp(enemy[i]);
		}
	
		if (enemy[i].enable == true && enemy[i].type == ENEMY3) {
			DrawGraph(enemy[i].x - 50, enemy[i].y - 44, enemyimg2, true);
			//DrawCircle(enemy[i].x, enemy[i].y, enemy[i].r, enemy[i].color, enemy[i].fill);
			drawEHp(enemy[i]);
		}
	}
	if (enemy[24].enable == true) {

		DrawGraph(enemy[24].x - 100, enemy[24].y - 88, bossimg, true);	
		//DrawCircle(enemy[i].x, enemy[i].y, enemy[i].r, enemy[i].color, enemy[i].fill);
		drawEHp(enemy[24]);
	}
	
}
//弾が撃てるか確認する関数
bool canEnemyShot(En enemy)
{
	//銃が冷えている
	if (enemy.cooltime <= 0) {
		if (enemy.x >= 0 &&
			enemy.x < 600 &&
			enemy.y>0 &&
			enemy.y < 1000)
		{
			//画面の中にいる
			return true;
		}
	}

	return false;
}