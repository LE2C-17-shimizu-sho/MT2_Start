#include "DxLib.h"
#include "Vector3.h"
#include "Vector2.h"
#include"Matrix4.h"
#include<cstring>
// 関数プロトタイプ宣言
int DrawCircle(Vector2 vec, int r, unsigned int color);

//Vector3型を利用しやすくするための オーバーロード関数群
//球の描画
//DxLib = > int DrawSphere3D(VECTOR Centerpos, float r, int DivNum, unsigned int DifColor, unsigned int Spccolor, int FillFlag);
int DrawSphere3D(const Vector3& CenterPos, const float r, const int DivNum, const unsigned int Difcolor, const unsigned int Spccolor, const int FillFlag);

//線分の描画
// DxLib => int DrawLine3D(VECTOR Pos1, VECTOR Pos2, unsigned int Color);
int DrawLine3D(const Vector3& Pos1, const Vector3& Pos2, const unsigned int Color);

//円錐(cone)の描画
// DxLib => int DrawCone3D( VECTOR TopPos, VECTOR Bottompos, float r, int DivNum, unsigned int Difcolor, unsigned int Spccolor,int FillFlag);
int DrawCone3D(const Vector3& Toppos, const Vector3& BottomPos, const float r,
	const int DivNum, const unsigned int Difcolor, const unsigned int Spccolor, const int FillFlag);

// カメラの位置と姿勢の設定
// DxLib => int SetCamerapositionAndTargetAndUpVec(VECTOR Position, VECTOR Target, VECTOR Up);
int SetCameraPositionAndTargetAndUpVec(
	const Vector3& cameraPosition,//カメラの位置 
	const Vector3& cameraTarget,//カメラの注視点
	const Vector3& cameraUp //カメラの上の向き
);

//関数プロトタイプ宣言
void DrawAxis3D(const float length); // ×,y,z 軸の描画
void DrawKeyOperation(); //キー操作の描画

// ウィンドウのタイトルに表示する文字列
const char TITLE[] = "LE2C_17_シミズ_ショウ: タイトル";

// ウィンドウ横幅
const int WIN_WIDTH = 1600;

// ウィンドウ縦幅
const int WIN_HEIGHT = 900;

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine,
	_In_ int nCmdShow)
{
	// ウィンドウモードに設定
	ChangeWindowMode(TRUE);

	// タイトルを変更
	SetMainWindowText(TITLE);

	// 画面サイズの最大サイズ、カラービット数を設定(モニターの解像度に合わせる)
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);

	// 画面サイズを設定(解像度との比率で設定)
	SetWindowSizeExtendRate(1.0);

	// 画面の背景色を設定する
	SetBackgroundColor(0x00, 0x00, 0x40);

	// DXlibの初期化
	if (DxLib_Init() == -1)
	{
		return -1;
	}

	// (ダブルバッファ)描画先グラフィック領域は裏面を指定
	SetDrawScreen(DX_SCREEN_BACK);

	// 画像などのリソースデータの変数宣言と読み込み


	// ゲームループで使う変数の宣言

	// 最新のキーボード情報用
	char keys[256] = { 0 };

	// 1ループ(フレーム)前のキーボード情報
	char oldkeys[256] = { 0 };

	// Ｚバッファを有効にする
	SetUseZBuffer3D(TRUE);
	// Ｚバッファへの書き込みを有効にする
	SetWriteZBuffer3D(TRUE);

	//カメラ初期化
	Vector3 cameraPosition(50.0f, 50.0f, -400.0f);
	Vector3 cameraTarget(0.0f, 0.0f, 0.0f);
	Vector3 cameraup(0.0f, 1.0f, 0.0f);

	//クリップ面近遠
	SetCameraNearFar(1.0f, 10000.0f);//カメラの有効範囲を設定
	SetCameraScreenCenter(WIN_WIDTH / 2.0f, WIN_HEIGHT / 2.0f); //画面の中心をカメラの中心に合わせる
	SetCameraPositionAndTargetAndUpVec(
		Vector3(0.0f,0.0f,-120.0f),
		Vector3(0.0f, 0.0f, 0.0f),
		Vector3(0.0f, -1.0f, 0.0f));

	// 時間計測に必要なデータ
	long long startCount = 0;
	long long nowCount = 0;
	long long elapsedCount = 0;

	// 補間で使うデータ
	// start → end を 5 [s] で完了させる
	Vector3 start(-100.0f, 0, 0);
	Vector3 end(+100.0f, 0, 0);
	float maxTime = 5.0f;
	float timeRate;

	// 球の位置
	Vector3 position;

	// 実行前に カウンタ値を取得
	startCount = GetNowHiPerformanceCount(); // long long int型  64bit int

	// ゲームループ
	while (true)
	{
		// 最新のキーボード情報だったものは1フレーム前のキーボード情報として保存
		for (int i = 0; i < 256; ++i)
		{
			oldkeys[i] = keys[i];
		}
		// 最新のキーボード情報を取得
		GetHitKeyStateAll(keys);

		//---------  ここからプログラムを記述  ----------//

		//更新

		// [R]キーで、リスタート
		if (CheckHitKey(KEY_INPUT_R))
		{
			startCount = GetNowHiPerformanceCount();
		}
		
		// 経過時間(elapsedTime [s]) の計算
		nowCount = GetNowHiPerformanceCount();
		elapsedCount = nowCount - startCount;
		float elapsedTime = static_cast<float> (elapsedCount) / 1'000'000.0f;

		// スタート地点		: start
		// エンド地点		: end
		// 経過時間			: elapsedTime [s]
		// 移動完了の率(経過時間/全体時間) : timeRate (%)

		timeRate = min(elapsedTime / maxTime, 1.0f);

		position = lerp(start, end, timeRate);

		//描画---------------
		ClearDrawScreen();//画面を消去
		DrawAxis3D(500.0f);//xyz軸の描画

		// 球の描画
		DrawSphere3D(position, 5.0f, 32, GetColor(255, 0, 0), GetColor(255, 255, 255).TRUE);

		DrawKeyOperation();// キー操作の描画

		//---------  ここまでにプログラムを記述  ---------//
		// (ダブルバッファ)裏面
		ScreenFlip();

		// 20ミリ秒待機(疑似60FPS)
		WaitTimer(20);

		// Windowsシステムからくる情報を処理する
		if (ProcessMessage() == -1)
		{
			break;
		}

		// ESCキーが押されたらループから抜ける
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			break;
		}
	}
	// Dxライブラリ終了処理
	DxLib_End();

	// 正常終了
	return 0;
}

//オーバーロード

// ×yz軸の描画
void DrawAxis3D(const float length)
{
	//軸の線の描画
	DrawLine3D(Vector3(-length, 0, 0), Vector3(+length, 0, 0), GetColor(255, 0, 0));//x軸
	DrawLine3D(Vector3(0, -length, 0), Vector3(0, +length, 0), GetColor(0, 255, 0));//y軸
	DrawLine3D(Vector3(0, 0, -length), Vector3(0, 0, +length), GetColor(0, 0, 255));//z軸

	//軸の先の描画 ※×yz軸の先っぽに、円錐をつける
	const float coneSize = 10.0f;
	DrawCone3D(Vector3(length, 0, 0), Vector3(length - coneSize, 0, 0), coneSize / 2, 16,
		GetColor(255, 0, 0), GetColor(255, 255, 255), TRUE);

	DrawCone3D(Vector3(0, length, 0), Vector3(0, length - coneSize, 0), coneSize / 2, 16,
		GetColor(0, 255, 0), GetColor(255, 255, 255), TRUE);

	DrawCone3D(Vector3(0, 0, length), Vector3(0, 0, length - coneSize), coneSize / 2, 16,
		GetColor(0, 0, 255), GetColor(255, 255, 255), TRUE);

}

// DxLib => int DrawCone3D( VECTOR TopPos, VECTOR Bottompos, float r, int DivNum, unsigned int Difcolor, unsigned int Spccolor,int FillFlag);
int DrawCone3D(const Vector3& TopPos, const Vector3& BottomPos, const float r,
	const int DivNum, const unsigned int Difcolor, const unsigned int Spccolor, const int FillFlag)
{
	VECTOR topPos = { TopPos.x, TopPos.y, TopPos.z };
	VECTOR bottomPos = { BottomPos.x, BottomPos.y, BottomPos.z };

	return DrawCone3D(topPos, bottomPos, r, DivNum, Difcolor, Spccolor, FillFlag);
}

int DrawCircle(Vector2 vec, int r, unsigned int color)
{
	return DrawCircle(static_cast<int>(vec.x), static_cast<int>(vec.y), r, color);
}

//球の描画
//(!DXLib = > int DrawSphere3D(VECTOR Centerpos, float r, int DivNum, unsigned int DifColor, unsigned int Spccolor, int FillFlag);
int DrawSphere3D(const Vector3& CenterPos, const float r, const int DivNum, const unsigned int DifColor, const unsigned int SpcColor, const int FillFlag)
{
	VECTOR centerPos = { CenterPos.x, CenterPos.y, CenterPos.z };//構造体 初期化リスト

	return DrawSphere3D(centerPos, r, DivNum, DifColor, SpcColor, FillFlag); //DxLib関数の呼び出し
}

//線分の描画
//DxLib = > int DrawLine3D(VECTOR Pos1, VECTOR Pos2, unsigned int Color);
int DrawLine3D(const Vector3& Pos1, const Vector3& Pos2, const unsigned int color)
{
	VECTOR p1 = { Pos1.x, Pos1.y, Pos1.z };//構造体 初期化子リスト
	VECTOR p2 = { Pos2.x, Pos2.y, Pos2.z };//構造体 初期化子リスト

	return DrawLine3D(p1, p2, color);//DxLib関数の呼び出し
}

//カメラの位置と姿勢の設定
//DxLib = > int SetCamerapositionAndTargetAndUpVec(VECTOR Position, VECTOR Target, VECTOR Up);
int SetCameraPositionAndTargetAndUpVec(
	const Vector3& cameraPosition,//カメラの位置
	const Vector3& cameraTarget, //カメラの注視点
	const Vector3& cameraUp //カメラの上の向き
)
{
	VECTOR position = { cameraPosition.x, cameraPosition.y, cameraPosition.z };
	VECTOR target = { cameraTarget.x, cameraTarget.y, cameraTarget.z };
	VECTOR up = { cameraUp.x, cameraUp.y, cameraUp.z };
	return SetCameraPositionAndTargetAndUpVec(position, target, up);
}

//モデルの座標変換用行列をセットする
int MV1SetMatrix(const int MHandle, const Matrix4 Matrix)
{
	MATRIX matrix;
	std::memcpy(&matrix, &Matrix, sizeof MATRIX);//メモリ間コピー
	return MV1SetMatrix(MHandle, matrix);
}