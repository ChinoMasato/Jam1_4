#include "DxLib.h"
#include "game.h"
//�Q�[���֘A�̏��
int score = 0;//�_��
bool gameOverFlag = false;//�Q�[���I�[�o�[����

//�Q�[���̏�����
void initGame()
{

}
//�Q�[�����e�̍X�V
void updateGame()
{
	
}
//�Q�[�����̕`��
void drawGame()
{
	DrawFormatString(0, 40, GetColor(255, 255, 0), "�X�R�A %d �_", score);//�X�R�A�̑����ʂ̕ύX��enemy.cpp�̓G���S�̂Ƃ��ŕς���܂�

	if (gameOverFlag == true) {
		DrawFormatString(350, 300, GetColor(255, 0, 0), "�Q�[���I�[�o�[");
	}
}