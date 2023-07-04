//プレイヤーを操作する関数を書いたファイル
#include "en.h"
#include "DxLib.h"
#include "shot.h"
#include "player.h"
#include "enemy.h"
#include "Graph.h"

En player;//プレイヤー
int shotse;//ショットSE
int lasershotse;//レーザー攻撃SE

int playerimg;
int countrey = 0;
//プレイヤーの初期化
void initPlayer()
{
	shotse = LoadSoundMem("ショット7.mp3");
	lasershotse = LoadSoundMem("エネルギーを発射2.mp3");

	playerimg = LoadGraph("jiki.png");
	player.x = 300;
	player.y = 1000;
	player.r = 10;
	player.color = GetColor(255, 255, 255);
	player.fill = true;
	player.cooltime = 0;
	player.hp = 30;
	
}


//プレイヤーの更新
void updatePlayer()
{
	//プレイヤーを動かす
	if (CheckHitKey(KEY_INPUT_RIGHT) == 1 || CheckHitKey(KEY_INPUT_D) == 1)
	{
		player.x = player.x + 3.0;
	}
	if (CheckHitKey(KEY_INPUT_LEFT) == 1 || CheckHitKey(KEY_INPUT_A) == 1)
	{
		player.x = player.x - 3.0;
	}
	if (CheckHitKey(KEY_INPUT_UP) == 1 || CheckHitKey(KEY_INPUT_W) == 1)
	{
		player.y = player.y - 3.0;
	}
	if (CheckHitKey(KEY_INPUT_DOWN) == 1 || CheckHitKey(KEY_INPUT_S) == 1)
	{
		player.y = player.y + 3.0;
	}
	if (player.x < 0) {
		//もし左端に出たら
		player.x = 0;
	}
	if (player.x >= 600) {
		//もし右端に出たら
		player.x = 600;
	}
	if (player.y < 0) {
		//もし左端に出たら
		player.y = 0;
	}
	if (player.y >= 1000) {
		//もし右端に出たら
		player.y = 1000;
	}

	//弾を撃つ処理
	if ((CheckHitKey(KEY_INPUT_Z) == 1 || CheckHitKey(KEY_INPUT_SPACE)) &&
		player.cooltime <= 0)
	{
		//弾が無効なときのみ初期値をセットし有効にする
		for (int i = 0; i < ShotNum; i++)
		{
			shot[i].vx = 0.0;
			shot[i].vy = -5.0;
			//撃てる弾をみつける
			if (shot[i].enable == false) {
				//弾を撃つ
				shot[i].x = player.x + 1;
				shot[i].y = player.y - 50;
				shot[i].enable = true;
				player.cooltime = 30;//連射速度　小さいほど連射できる
				PlaySoundMem(shotse, DX_PLAYTYPE_BACK);
				break;
			}
		}
	}
	if (CheckHitKey(KEY_INPUT_Q) == 1 &&
		player.cooltime <= 0)
	{
		for (int i = 0; i < ShotNum; i++)
		{
			if (shot[i].enable == false) {
				shot[i].x = player.x;
				shot[i].y = player.y;
				double speed = 4.0;//速度
				double dx = enemy[i].x - shot[i].x;//プレイヤーと敵のx方向の距離
				double dy = enemy[i].y - shot[i].y;//プレイヤーと敵のy方向の距離

				double d = sqrt(dx * dx + dy * dy);//敵とプレイヤーとの距離
				shot[i].vx = speed * (dx / d);//xの移動量
				shot[i].vy = speed * (dy / d);//yの移動量
				shot[i].enable = true;
				player.cooltime = 10;//連射速度　小さいほど連射できる
				PlaySoundMem(shotse, DX_PLAYTYPE_BACK);
				break;
			}
		}
	}
	if (CheckHitKey(KEY_INPUT_E) == 1) {
		for (int i = 0; i < EnemyNum; i++) {

			if (player.x - 200 < enemy[i].x + enemy[i].r && player.x + 200 > enemy[i].x - enemy[i].r && player.y-player.r-800 < enemy[i].y + enemy[i].r && player.y - player.r > enemy[i].y - enemy[i].r)
			{
				enemy[i].hp--;
			}
		}
		if (countrey < 0) 
		{
			PlaySoundMem(lasershotse, DX_PLAYTYPE_BACK);
			countrey = 70;
		}
	}

	if (CheckHitKey(KEY_INPUT_X) == 1 && bomb.cooltime == 0)
	{
		bomb.vx = 0.0;
		bomb.vy = -5.0;
		//撃てる弾をみつける
		if (bomb.enable == false) {
			//弾を撃つ
			bomb.x = player.x + 1;
			bomb.y = player.y - 50;
			bomb.enable = true;
			bomb.cooltime = 1000;//連射速度　小さいほど連射できる
			PlaySoundMem(shotse, DX_PLAYTYPE_BACK);
		}
	}

	//銃を冷やす処理
	if (player.cooltime > 0) {
		player.cooltime--;
	}
	if (bomb.cooltime > 0) {
		bomb.cooltime--;
	}
	player.star--;//無敵時間をカウントダウンさせる
	countrey--;
}

//プレイヤーの描画
void drawPlayer()
{
	if (player.star > 0) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 152);
	}
	DrawGraph(player.x - 50, player.y - 70, playerimg, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 152);

	if (CheckHitKey(KEY_INPUT_E) == 1)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
		DrawGraph(player.x - 400, player.y - player.r - 800, reypht, true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 155);
	}
}