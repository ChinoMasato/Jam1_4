//�v���C���[�𑀍삷��֐����������t�@�C��
#include "en.h"
#include "DxLib.h"
#include "shot.h"
#include "player.h"
#include "enemy.h"
#include "Graph.h"

En player;//�v���C���[
int shotse;//�V���b�gSE
int lasershotse;//���[�U�[�U��SE

int playerimg;
int countrey = 0;
//�v���C���[�̏�����
void initPlayer()
{
	shotse = LoadSoundMem("�V���b�g7.mp3");
	lasershotse = LoadSoundMem("�G�l���M�[�𔭎�2.mp3");

	playerimg = LoadGraph("jiki.png");
	player.x = 300;
	player.y = 1000;
	player.r = 10;
	player.color = GetColor(255, 255, 255);
	player.fill = true;
	player.cooltime = 0;
	player.hp = 30;
	
}


//�v���C���[�̍X�V
void updatePlayer()
{
	//�v���C���[�𓮂���
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
		//�������[�ɏo����
		player.x = 0;
	}
	if (player.x >= 600) {
		//�����E�[�ɏo����
		player.x = 600;
	}
	if (player.y < 0) {
		//�������[�ɏo����
		player.y = 0;
	}
	if (player.y >= 1000) {
		//�����E�[�ɏo����
		player.y = 1000;
	}

	//�e��������
	if ((CheckHitKey(KEY_INPUT_Z) == 1 || CheckHitKey(KEY_INPUT_SPACE)) &&
		player.cooltime <= 0)
	{
		//�e�������ȂƂ��̂ݏ����l���Z�b�g���L���ɂ���
		for (int i = 0; i < ShotNum; i++)
		{
			shot[i].vx = 0.0;
			shot[i].vy = -5.0;
			//���Ă�e���݂���
			if (shot[i].enable == false) {
				//�e������
				shot[i].x = player.x + 1;
				shot[i].y = player.y - 50;
				shot[i].enable = true;
				player.cooltime = 30;//�A�ˑ��x�@�������قǘA�˂ł���
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
				double speed = 4.0;//���x
				double dx = enemy[i].x - shot[i].x;//�v���C���[�ƓG��x�����̋���
				double dy = enemy[i].y - shot[i].y;//�v���C���[�ƓG��y�����̋���

				double d = sqrt(dx * dx + dy * dy);//�G�ƃv���C���[�Ƃ̋���
				shot[i].vx = speed * (dx / d);//x�̈ړ���
				shot[i].vy = speed * (dy / d);//y�̈ړ���
				shot[i].enable = true;
				player.cooltime = 10;//�A�ˑ��x�@�������قǘA�˂ł���
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
		//���Ă�e���݂���
		if (bomb.enable == false) {
			//�e������
			bomb.x = player.x + 1;
			bomb.y = player.y - 50;
			bomb.enable = true;
			bomb.cooltime = 1000;//�A�ˑ��x�@�������قǘA�˂ł���
			PlaySoundMem(shotse, DX_PLAYTYPE_BACK);
		}
	}

	//�e���₷����
	if (player.cooltime > 0) {
		player.cooltime--;
	}
	if (bomb.cooltime > 0) {
		bomb.cooltime--;
	}
	player.star--;//���G���Ԃ��J�E���g�_�E��������
	countrey--;
}

//�v���C���[�̕`��
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