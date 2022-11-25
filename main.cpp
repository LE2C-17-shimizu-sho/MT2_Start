#include "DxLib.h"
#include "Vector2.h"
#include <cmath>

bool CollisionLineCircle(Vector2& startLine, Vector2& endLine, Vector2& circle, int radius);

// ウィンドウのタイトルに表示する文字列
const char TITLE[] = "LE2C_17_シミズショウ: タイトル";

// ウィンドウ横幅
const int WIN_WIDTH = 600;

// ウィンドウ縦幅
const int WIN_HEIGHT = 400;

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine,
                   _In_ int nCmdShow) {
	// ウィンドウモードに設定
	ChangeWindowMode(TRUE);

	// ウィンドウサイズを手動では変更させず、
	// かつウィンドウサイズに合わせて拡大できないようにする
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	// タイトルを変更
	SetMainWindowText(TITLE);

	// 画面サイズの最大サイズ、カラービット数を設定(モニターの解像度に合わせる)
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);

	// 画面サイズを設定(解像度との比率で設定)
	SetWindowSizeExtendRate(1.0);

	// 画面の背景色を設定する
	SetBackgroundColor(0x00, 0x00, 0x00);

	// DXlibの初期化
	if (DxLib_Init() == -1) { return -1; }

	// (ダブルバッファ)描画先グラフィック領域は裏面を指定
	SetDrawScreen(DX_SCREEN_BACK);

	// Ｚバッファを有効にする
	SetUseZBuffer3D(TRUE);

	// Ｚバッファへの書き込みを有効にする
	SetWriteZBuffer3D(TRUE);


	// 画像などのリソースデータの変数宣言と読み込み


	// ゲームループで使う変数の宣言
	int radius = 30;
	int speed = 5;

	int VecPosAX = 0;
	int VecPosBX = 0;
	int VecPosAY = 0;
	int VecPosBY = 0;

	bool hitFlag = false;

	Vector2 circle = { 250,250 };
	Vector2 startLine = { 50,50 };
	Vector2 goalLine = { 200,50 };

	// 最新のキーボード情報用
	char keys[256] = {0};

	// 1ループ(フレーム)前のキーボード情報
	char oldkeys[256] = {0};

	// ゲームループ
	while (true) {
		// 最新のキーボード情報だったものは1フレーム前のキーボード情報として保存
		// 最新のキーボード情報を取得
		GetHitKeyStateAll(keys);

		// 画面クリア
		ClearDrawScreen();
		//---------  ここからプログラムを記述  ----------//

		// 更新処理
		if (keys[KEY_INPUT_W] == 1)
		{
			startLine.y -= speed;
			goalLine.y -= speed;
		}
		if(keys[KEY_INPUT_S] == 1)
		{
			startLine.y += speed;
			goalLine.y += speed;
		}
		if (keys[KEY_INPUT_A] == 1)
		{
			startLine.x -= speed;
			goalLine.x -= speed;
		}
		if (keys[KEY_INPUT_D] == 1)
		{
			startLine.x += speed;
			goalLine.x += speed;
		}

		hitFlag = CollisionLineCircle(startLine, goalLine, circle, radius);
		


		// 描画処理
		if (hitFlag == true)
		{
			DrawCircle((int)circle.x, (int)circle.y, radius, GetColor(255, 0, 0), true);
		}
		else
		{
			DrawCircle((int)circle.x, (int)circle.y, radius, GetColor(255, 255, 255), true);
		}
		
		DrawLine((int)startLine.x, (int)startLine.y, (int)goalLine.x, (int)goalLine.y, GetColor(0, 255, 0), true);

		DrawFormatString(0, 0, GetColor(255, 255, 255), "circleX: %d", hitFlag);
		DrawFormatString(0, 20, GetColor(255, 255, 255), "circleY: %d", circle.y);

		//---------  ここまでにプログラムを記述  ---------//
		// (ダブルバッファ)裏面
		ScreenFlip();

		// 20ミリ秒待機(疑似60FPS)
		WaitTimer(20);

		// Windowsシステムからくる情報を処理する
		if (ProcessMessage() == -1) {
			break;
		}

		// ESCキーが押されたらループから抜ける
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
			break;
		}
	}
	// Dxライブラリ終了処理
	DxLib_End();

	// 正常終了
	return 0;
}

bool CollisionLineCircle(Vector2& startLine, Vector2& endLine, Vector2& circle, int radius)
{
	Vector2 vecLine = endLine - startLine;

	Vector2 endLineCircle = circle - endLine;

	Vector2 startLineCircle = circle - startLine;

	Vector2 normLineVec = vecLine.normalize();

	float distance = startLineCircle.cross(normLineVec);

	// 二乗する
	float fab = distance * distance;

	if (fab < radius)
	{
		float circlVecLineStartVecDot = startLineCircle.dot(vecLine);
		float circlVecLineEndVecDot = endLineCircle.dot(vecLine);
		float fabcircleLineDot = circlVecLineStartVecDot * circlVecLineEndVecDot;

		if (fabcircleLineDot < 0)
		{
			return true;
		}

		if (endLineCircle.length() < radius || startLineCircle.length() < radius)
		{
			return true;
		}
	}
	return false;
}