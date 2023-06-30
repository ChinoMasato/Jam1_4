#include"UI.h"
#include "DxLib.h"
#include "en.h"
void drawUI()
{
	DrawBox(0, 0, player.hp, 30, (0, 0, 255), TRUE);
}
void drawEHp(En en1)
{

	DrawBox(en1.x - en1.r, en1.y + en1.r - 5, en1.x + en1.r, en1.y + en1.r, GetColor(0, 0, 0), 1);
	DrawBox(en1.x - en1.r, en1.y + en1.r - 5, en1.x - en1.r + (en1.r * (en1.hp / en1.shp)) * 2, en1.y + en1.r, GetColor(255, 0, 0), 1);
	DrawBox(en1.x - en1.r, en1.y + en1.r - 5, en1.x + en1.r, en1.y + en1.r, GetColor(255, 255, 255), 0);
}