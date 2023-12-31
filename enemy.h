#pragma once
#include "en.h"
const int EnemyNum = 30;//敵の数
extern En enemy[EnemyNum];//敵
extern int enemyimg;
extern int enemyimg2;
extern int bossimg;

void initEnemy();//敵の初期化
void updateEnemy();//敵の更新
void drawEnemy();//敵の描画
void updateBoss();

bool canEnemyShot(En enemy);//弾が撃てるか確認

void straightShot(int rad, En ene, int shifty);//真っすぐ撃つ
void aimShot(En ene);//狙って撃つ

void explosion(En ene);//爆発発生関数