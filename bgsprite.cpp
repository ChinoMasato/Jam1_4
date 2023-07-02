#include "DxLib.h"
#include "bgsprite.h"
int bgimg0;//”wŒiŽè‘O‰æ‘œ
int bgimg1;//”wŒi‰æ‘œ
int bgimg2;//”wŒi‰æ‘œ2
double scrollY1 = -1000.0;
double scrollY2 = -1000.0;
double scrollY3 = -1000.0;
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
	scrollY1 = scroll(scrollY1, 50);
	scrollY2 = scroll(scrollY2, 50);

	scrollY3 = scroll(scrollY3, 50);
	scrollY4 = scroll(scrollY4, 50);
}
void drawBg()
{
	DrawGraph(300, scrollY1, bgimg1, true);
	DrawGraph(300, scrollY2, bgimg2, true);

	DrawGraph(300, scrollY3, bgimg0, true);
	DrawGraph(300, scrollY4, bgimg0, true);
}