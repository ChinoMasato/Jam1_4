#pragma once
#include "en.h"

extern En player;//プレイヤー
extern int playerimg;
extern int shottype;


void initPlayer();//プレイヤーの初期化
void updatePlayer();//プレイヤーの更新
void drawPlayer();
void rey(En p, En e);

