#include "DxLib.h"
#include "bgsprite.h"
int bgimg0;//�w�i��O�摜
int bgimg1;//�w�i�摜
int bgimg2;//�w�i�摜2
double scrollY1 = 0.0;
double scrollY2 = -1000.0;
double scrollY3 = 0.0;
double scrollY4 = -1000.0;
void initBg()
{
	bgimg0 = LoadGraph("haikei.jpg");
	bgimg1 = LoadGraph("haikei.jpg");
	bgimg2 = LoadGraph("haikei.jpg");

}
double scroll(double y, double speed)
{
	
	y = y + speed;
	if (y >= 1000.0)//�摜1�������ɃY������
	{
		//�摜2������ɖ߂�
		y =- 1000.0;
	}
	return y;
}
void updateBg()
{
	//�X�N���[��
	scrollY1 = scroll(scrollY1, 7);
	scrollY2 = scroll(scrollY2, 7);

	scrollY3 = scroll(scrollY3, 7);
	scrollY4 = scroll(scrollY4, 7);
}
void drawBg()
{
	DrawGraph(-200, scrollY1, bgimg1, true);
	DrawGraph(-200, scrollY2, bgimg2, true);

	DrawGraph(-200, scrollY3, bgimg0, true);
	DrawGraph(-200, scrollY4, bgimg0, true);
}