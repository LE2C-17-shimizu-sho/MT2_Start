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

//モデルの座標変換用行列をセットする
// DxLib => int MV1SetMatrix(int MHandle, MATRIX Matrix);
int MV1SetMatrix(const int MHandle, const Matrix4 Matrix);

//関数プロトタイプ宣言
void DrawAxis3D(const float length); // ×,y,z 軸の描画
void DrawKeyOperation(); //キー操作の描画

// ウィンドウのタイトルに表示する文字列
const char TITLE[] = "10DaysGameJam";

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


	int haha;
	int	baka;

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
	SetCameraPositionAndTargetAndUpVec(cameraPosition, cameraTarget, cameraup);

	//アプリで使用する変数
	int model = MV1LoadModel("fighter/fighter.mqo");

	//xyz軸の回転角度
	const float ROT_UNIT = 0.01f;
	float rotX = 0.0f;
	float rotY = 0.0f;
	float rotZ = 0.0f;

	int scene = 0;

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
		if (CheckHitKey(KEY_INPUT_A))	rotY += ROT_UNIT;
		if (CheckHitKey(KEY_INPUT_D))	rotY -= ROT_UNIT;

		if (CheckHitKey(KEY_INPUT_W))	rotX += ROT_UNIT;
		if (CheckHitKey(KEY_INPUT_S))	rotX -= ROT_UNIT;

		if (CheckHitKey(KEY_INPUT_E))	rotZ += ROT_UNIT;
		if (CheckHitKey(KEY_INPUT_Z))	rotZ -= ROT_UNIT;

		//[R]でリセット
		if (CheckHitKey(KEY_INPUT_R))
		{
			rotX = rotY = rotZ = 0;
		}

		//各種変換行列の計算
		Matrix4 matScale = scale(Vector3(5.0f, 5.0f, 5.0f)); //モデルの拡大率

		Matrix4 matRotX = rotateX(rotX);

		Matrix4 matRotY = rotateY(rotY);

		Matrix4 matRotZ = rotateZ(rotZ);

		Matrix4 matRot = matRotY * matRotX * matRotZ;

		Matrix4 matWorld = matScale * matRot;


		MV1SetMatrix(model, matWorld);



		//描画---------------
		ClearDrawScreen();//画面を消去
		DrawAxis3D(200.0f);//xyz軸の描画
		MV1DrawModel(model);//モデルの描画

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

//キー操作の描画
void DrawKeyOperation()
{
	const unsigned white = GetColor(255, 255, 255);
	DrawFormatString(10, 20 * 1, white, "  [W][E][R]  R : リセット");
	DrawFormatString(10, 20 * 2, white, "[A][S][D]    AD: y軸まわりの回転");
	DrawFormatString(10, 20 * 3, white, " [Z]         WS: x軸まわりの回転");
	DrawFormatString(10, 20 * 4, white, "             EZ: z軸まわりの回転");
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