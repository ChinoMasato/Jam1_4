﻿
#include "DxLib.h"
#include "player.h"
#include "shot.h"
#include "enemyshot.h"
#include "enemy.h"
#include "en.h"
#include "game.h"
#include "effect.h"
#include "UI.h"
#include "Graph.h"

void init();//初期化関数のプロトタイプ宣言
void titleUpdate();
void update();//更新関数のプロトタイプ宣言
void draw();//描画処理

int gamestartse;

enum GameScene
{
	Title,
	Game,
	Result
};
GameScene scene = Title;
// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//DXライブラリの初期化処理 ここから
	ChangeWindowMode(TRUE);	//ウィンドウモードにする
	SetGraphMode(600, 1000, 32);	//ウィンドウサイズを設定する
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}
	SetDrawScreen(DX_SCREEN_BACK);	//裏画面を描画対象へ
	//DXライブラリの初期化処理 ここまで

	init();//初期化処理の呼び出し　起動時一度だけ呼び出す

	//メインループ処理
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
		if (scene == Title)
		{
			titleUpdate();//更新処理の呼び出し
		}
		if (scene == Game)
		{
			update();//更新処理の呼び出し
		}
		ScreenFlip();		//裏画面と表画面の入替
		ClearDrawScreen();	//裏画面の描画を全て消去
	}
	//メインループ処理ここまで

	DxLib_End();			// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}
//初期化関数　引数、戻り値なし
void init()
{

	//ゲームの初期化
	initGame();
	//プレイヤーの初期化
	initPlayer();
	//弾の初期化
	initShot();
	initEnemyShot();
	//敵の初期化処理
	initEnemy();
	//画像関連の初期化処理
	initGraph();
	//エフェクトの初期化
	initEffect();
	//タイトルBGM再生
	PlayMusic("Short_SF_13.mp3", DX_PLAYTYPE_LOOP);
	gamestartse = LoadSoundMem("完了6。mp3");
}
//タイトルシーンの更新
void titleUpdate()
{
	if (CheckHitKey(KEY_INPUT_RETURN) == 1)
	{
		scene = Game;
		PlayMusic("Shooting_01.mp3", DX_PLAYTYPE_LOOP);
	}
	DrawGraph(0, 300, TitleLogo, true);
	DrawGraph(180, 380, PushEnterKey, true);
}

//更新関数
void update()
{
	//ゲーム(審判)の更新
	updateGame();
	//プレイヤーの更新
	updatePlayer();

	//弾の更新
	updateShot();
	updateEnemyShot();
	//敵の更新
	updateEnemy();
	//エフェクトの更新
	updateEffect(); 
	//画像関連の更新
	updateGraph();

	//描画処理
	draw();
}

//描画処理
void draw()
{
	//敵の描画
	drawEnemy();
	//プレイヤーの描画
	drawPlayer();
	//弾の描画
	drawShot();
	drawEnemyShot();
	//エフェクトの描画
	drawEffect();
	//ゲーム関連の描画
	drawGame();

	drawUI();
}
