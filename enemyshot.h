#pragma once
#include "en.h"
#include "enemy.h"

const int EnemyShotNum = 100;
extern En enemyshot[EnemyShotNum];//�e
extern int enemyshotimg;
extern int enemyshotimg2;

void initEnemyShot();//�e�̏�����
void updateEnemyShot();//�e�̍X�V
void drawEnemyShot();