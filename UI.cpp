#include"UI.h"
#include "DxLib.h"
#include "en.h"
#include "shot.h"
int count = 0;
int damege = 150;
void drawUI()
{
	count++;
	if (player.hp * 5 < damege && count % 5 == 0) {
		damege--;
	}
	if (count % 10 > 5) {
		DrawBox(0, 0, damege, 20, GetColor(200, 0, 0), TRUE);
	}
	DrawBox(0, 0, player.hp * 5, 20, GetColor(50, 50, 255), TRUE);
	DrawBox(0, 0, 150, 20, GetColor(255, 255, 255), FALSE);
	DrawFormatString(200, 0, GetColor(255, 255, 255), "wasd ñÓàÛÉLÅ[Ç≈ëÄçÏÅ@space z Ç≈éÀåÇ");

	DrawBox(0,980,120,999, GetColor(0, 0, 255), 1);
	DrawBox(1, 980, 120 * (bomb.cooltime / 1000), 999, GetColor(0, 0, 0), 1);
	DrawBox(0, 980, 120, 1000, GetColor(255, 255, 255), 0);
}
void drawEHp(En en1)
{

	DrawBox(en1.x - en1.r, en1.y + en1.r - 5, en1.x + en1.r, en1.y + en1.r, GetColor(0, 0, 0), 1);
	DrawBox(en1.x - en1.r, en1.y + en1.r - 5, en1.x - en1.r + (en1.r * (en1.hp / en1.shp)) * 2, en1.y + en1.r, GetColor(255, 0, 0), 1);
	DrawBox(en1.x - en1.r, en1.y + en1.r - 5, en1.x + en1.r, en1.y + en1.r, GetColor(255, 255, 255), 0);
}