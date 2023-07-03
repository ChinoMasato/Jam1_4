#pragma once
#include "en.h"

const int ShotNum = 100;
extern En shot[ShotNum];//’e
extern En shot2[ShotNum];//’e
extern int shotimg;
extern int shotimg2;

void initShot();//’e‚Ì‰Šú‰»
void updateShot();//’e‚ÌXV
void drawShot();
void initShot2();//’e‚Ì‰Šú‰»
void updateShot2();//’e‚ÌXV
void drawShot2();