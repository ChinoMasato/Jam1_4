#include "DxLib.h"
#include "game.h"
#include "player.h"
//�Q�[���֘A�̏��
int score = 0;//�_��
bool gameOverFlag = false;//�Q�[���I�[�o�[����
GameScene scene;
//�Q�[���̏�����
void initGame()
{

}
//�Q�[�����e�̍X�V
void updateGame()
{
	if (player.hp <= 0)
	{
		gameOverFlag = true;
		scene = Gameover;
		PlayMusic("tomoshibi.mp3", DX_PLAYTYPE_LOOP);
	}
}
//�Q�[�����̕`��
void drawGame()
{
	DrawFormatString(0, 40, GetColor(255, 255, 0), "�X�R�A %d �_", score);//�X�R�A�̑����ʂ̕ύX��enemy.cpp�̓G���S�̂Ƃ��ŕς���܂�

	if (gameOverFlag == true) {
		DrawFormatString(300, 300, GetColor(255, 0, 0), "�Q�[���I�[�o�[");

	}
}