#pragma once
#include "en.h"
const int EffectNum = 100;
extern int img[10];//最大１０コマ　画像

struct Effect
{
	double x;
	double y;
	double animeNo = 0;//何コマ目？
	int maxAnimeNo;//最大コマ数
	bool enable = false;//有効フラグ
	double No;
};
extern Effect effe[EffectNum];//エフェクト用の変数

void initEffect();
void updateEffect();
void drawEffect();
void A_light(En en1);