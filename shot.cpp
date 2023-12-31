//プレイヤーの弾を操作する関数を書いたファイル
#include "en.h"
#include "DxLib.h"
#include "shot.h"

En shot[ShotNum];//弾
En bomb;
int shotimg;
int bombimg;
//弾の初期化
void initShot()
{
	for (int i = 0; i < ShotNum; i++) {
		shot[i].r = 5;
		shot[i].color = GetColor(255, 255, 0);
		shot[i].fill = true;
		shot[i].vx = 0.0;
		shot[i].vy = -5.0;
		shot[i].enable = false;
		shotimg = LoadGraph("shotimg.png");
	}
	bomb.r = 10;
	bomb.color = GetColor(255, 255, 0);
	bomb.fill = true;
	bomb.vx = 0.0;
	bomb.vy = -1.0;
	bomb.z = 0;
	bomb.enable = false;
	bombimg = LoadGraph("ex.png");
}
//弾の更新
void updateShot()
{
	//弾が有効なときに弾を動かす
	for (int i = 0; i < ShotNum; i++)
	{
		if (shot[i].enable == true) {
			shot[i].x = shot[i].x + shot[i].vx;
			shot[i].y = shot[i].y + shot[i].vy;
			if (shot[i].x >= 600) {
				shot[i].enable = false;
			}
			if (shot[i].y < 0)
			{
				shot[i].enable = false;
			}
		}
		if (bomb.enable == true) {
			bomb.x = bomb.x + bomb.vx;
			bomb.y = bomb.y + bomb.vy;
			if (bomb.x >= 600) {
				bomb.enable = false;
			}
			if (bomb.y < 0)
			{
				bomb.enable = false;
			}
		}
		
	}
}
//弾の描画
void drawShot()
{
	for (int i = 0; i < ShotNum; i++) {
		if (shot[i].enable == true)
		{
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);//不透明
			DrawGraph(shot[i].x -100, shot[i].y -100, shotimg, true);
			
			//DrawCircle(shot[i].x, shot[i].y, shot[i].r * 0.5, shot[i].color, shot[i].fill);

		}
	}
	if (bomb.enable == true)
	{
		DrawGraph(bomb.x - 50, bomb.y - 50, bombimg, true);
	}
}