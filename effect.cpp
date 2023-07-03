#include "effect.h"
#include "DxLib.h"
#include "Graph.h"
#include "en.h"
Effect effe[EffectNum];//エフェクト用の変数
int img[10];//最大１０コマ　画像

void initEffect()
{
	//画像の読み込み
	LoadDivGraph("effect.png", 5, 5, 1, 120, 120, img);
}
void updateEffect()
{
	for (int i = 0; i < EffectNum; i++) {
		if (effe[i].enable == true)
		{
			//アニメーションを進める
			effe[i].animeNo = effe[i].animeNo + 0.1;
			//６コマ目になったら終了
			if ((int)(effe[i].animeNo) > 5) {
				effe[i].enable = false;
			}
		}
	}
}
void drawEffect()
{
	for (int i = 0; i < EffectNum; i++) {
		if (effe[i].enable == true)
		{
			int no = effe[i].animeNo;
			SetDrawBlendMode(DX_BLENDMODE_ADD, 180);
			DrawGraph(effe[i].x, effe[i].y,lightpht, true);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 122);
		}
	}
}
void A_light(En en1)
{
	for (int i = 0; i < EffectNum; i++)
	{
		if (effe[i].enable == false)
		{
			effe[i].enable = true;
			effe[i].x = en1.x - 200;
			effe[i].y = en1.y - 200;
			effe[i].animeNo = 0;
			effe[i].No = 0;
			break;
		}
	}
	
}