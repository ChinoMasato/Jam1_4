#pragma once
#include "en.h"

const int ShotNum = 100;
extern En shot[ShotNum];//�e
extern int shotimg;
extern En bomb;
extern int bombimg;
 

void initShot();//�e�̏�����
void updateShot();//�e�̍X�V
void drawShot();