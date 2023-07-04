#pragma once
#include "en.h"

const int ShotNum = 100;
extern En shot[ShotNum];//’e
extern int shotimg;
extern En bomb;
extern int bombimg;
 

void initShot();//’e‚Ì‰Šú‰»
void updateShot();//’e‚ÌXV
void drawShot();