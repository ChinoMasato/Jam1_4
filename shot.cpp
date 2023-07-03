//�v���C���[�̒e�𑀍삷��֐����������t�@�C��
#include "en.h"
#include "DxLib.h"
#include "shot.h"
#include "player.h"

En shot[ShotNum];//�e
En shot2[ShotNum];//�e
int shotimg;
int shotimg2;
int shottype;
//�e�̏�����
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


}
void initShot2() {
	for (int i = 0; i < ShotNum; i++) {
		shot2[i].r = 5;
		shot2[i].color = GetColor(255, 255, 0);
		shot2[i].fill = true;
		shot2[i].vx = 0.0;
		shot2[i].vy = -5.0;
		shot2[i].enable = false;
		shotimg2 = LoadGraph("ex.png");
		shottype = Shot;

	}
}
//�e�̍X�V
void updateShot()
{
	//�e���L���ȂƂ��ɒe�𓮂���
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

	}
}
void updateShot2()
	{
	for (int i = 0; i < ShotNum; i++)
	{
		if (shot2[i].enable == true) {
			shot2[i].x = shot2[i].x + shot2[i].vx;
			shot2[i].y = shot2[i].y + shot2[i].vy;
			if (shot2[i].x >= 600) {
				shot2[i].enable = false;
			}
			if (shot2[i].y < 0)
			{
				shot2[i].enable = false;
			}
		}

	}
}
//�e�̕`��
void drawShot()
{
	for (int i = 0; i < ShotNum; i++) {
		if (shot[i].enable == true)
		{
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);//�s����
			DrawGraph(shot[i].x - 100, shot[i].y - 100, shotimg, true);

			//DrawCircle(shot[i].x, shot[i].y, shot[i].r * 0.5, shot[i].color, shot[i].fill);

		}
	}
}
void drawShot2()
{
	for (int i = 0; i < ShotNum; i++) {
		if (shottype == Shot )
		{
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);//�s����
			DrawGraph(shot2[i].x - 50, shot2[i].y - 50, shotimg2, true);

			//DrawCircle(shot[i].x, shot[i].y, shot[i].r * 0.5, shot[i].color, shot[i].fill);


		}
	}
}