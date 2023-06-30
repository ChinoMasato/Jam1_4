#include "DxLib.h"
#include "bgsprite.h"
int bgimg0;//”wŒiŽè‘O‰æ‘œ
int bgimg1;//”wŒi‰æ‘œ
int bgimg2;//”wŒi‰æ‘œ2
double scrollY1 = 0.0;
double scrollY2 = 800.0;
double scrollY3 = 0.0;
double scrollY4 = 800.0;
void initBg()
{
	bgimg0 = LoadGraph("BG0.png");
	bgimg1 = LoadGraph("BG1.png");
	bgimg2 = LoadGraph("BG2.png");

}
double scroll(double y, double speed)
{
	y = y + speed;
	if (y <= 1000.0)//‰æ‘œ1–‡•ª‰º‚ÉƒYƒŒ‚½‚ç
	{
		//‰æ‘œ2–‡•ªã‚É–ß‚·
		y = y - 1000.0;
	}
	return y;
}
void updateBg()
{
	//ƒXƒNƒ[ƒ‹
	scrollY1 = scroll(scrollY1, 0.2);
	scrollY2 = scroll(scrollY2, 0.2);

	scrollY3 = scroll(scrollY3, 1.0);
	scrollY4 = scroll(scrollY4, 1.0);
}
void drawBg()
{
	DrawGraph(scrollY1, 0, bgimg1, true);
	DrawGraph(scrollY2, 0, bgimg2, true);

	DrawGraph(scrollY3, 0, bgimg0, true);
	DrawGraph(scrollY4, 0, bgimg0, true);
}