#pragma once
#include "en.h"

const int ShotNum = 100;
extern En shot[ShotNum];//�e
extern En shot2[ShotNum];//�e
extern int shotimg;
extern int shotimg2;

void initShot();//�e�̏�����
void updateShot();//�e�̍X�V
void drawShot();
void initShot2();//�e�̏�����
void updateShot2();//�e�̍X�V
void drawShot2();