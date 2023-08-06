#include "DxLib.h"
#include <vector>

// ベジェ基底関数を計算する関数
double bezier_basis(int i, int n, double t) {
    double coeff = 1.0;
    for (int j = 0; j < i; ++j) {
        coeff *= (1 - t); // (1 - t)のi乗を計算
    }
    for (int j = i + 1; j <= n; ++j) {
        coeff *= t; // tのn-i乗を計算
    }
    return coeff;
}

// 有理ベジェ曲線を計算する関数
std::vector<double> rational_bezier_curve(std::vector<std::vector<double>>& control_points, std::vector<double>& weights, double t) {
    int n = control_points.size() - 1;
    std::vector<double> result(3, 0.0); // 3次元の場合
    double sum_basis_times_weights = 0.0;
    double sum_basis_times_weights_times_points = 0.0;

    // ベジェ基底関数の計算と重み付きの合計を求める
    for (int i = 0; i <= n; ++i) {
        double basis = bezier_basis(i, n, t);
        double weighted_basis = basis * weights[i];
        sum_basis_times_weights += weighted_basis;

        for (int j = 0; j < 3; ++j) { // 3次元の場合
            sum_basis_times_weights_times_points += weighted_basis * control_points[i][j];
        }
    }

    // 有理ベジェ曲線上の点を計算
    for (int i = 0; i < 3; ++i) { // 3次元の場合
        result[i] = sum_basis_times_weights_times_points / sum_basis_times_weights;
    }

    return result;
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    // DxLibの初期化
    if (DxLib_Init() == -1) {
        return -1;
    }

    // ウィンドウを作成
    ChangeWindowMode(TRUE);
    SetGraphMode(800, 600, 32);
    if (SetMainWindowText("Rational Bezier Curve - 3D Model") == -1) {
        return -1;
    }
    if (DxLib_Init() == -1) {
        return -1;
    }

    // 制御点とウェイトの定義
    std::vector<std::vector<double>> control_points = {
        {50.0, 200.0, 0.0},
        {300.0, 100.0, 0.0},
        {500.0, 300.0, 0.0},
        {750.0, 100.0, 0.0},
        {700.0, 400.0, 0.0}
    };
    std::vector<double> weights = { 1.0, 0.5, 2.0, 1.5, 1.0 };

    // パラメータtの範囲（0.0～1.0）とステップ数
    double t_min = 0.0;
    double t_max = 1.0;
    int steps = 100;

    // 3Dモデルを読み込む
    int modelHandle = MV1LoadModel("model/model.mqo"); // モデルファイルのパスを指定

    // モデルの位置と回転角度を初期化
    float modelX = 0.0f;
    float modelY = 0.0f;
    float modelZ = 0.0f;
    float modelAngle = 0.0f;

    // メインループ
    while (!ProcessMessage() && !CheckHitKey(KEY_INPUT_ESCAPE)) {
        // モデルを描画する
        MV1SetPosition(modelHandle, VGet(modelX, modelY, modelZ));
        MV1SetRotationXYZ(modelHandle, VGet(0.0f, modelAngle, 0.0f));
        MV1DrawModel(modelHandle);

        // 画面の更新
        ScreenFlip();
    }

    // 3Dモデルを解放
    MV1DeleteModel(modelHandle);

    // DxLibの終了処理
    DxLib_End();

    return 0;
}
