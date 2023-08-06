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
    if (SetMainWindowText("Rational Bezier Curve") == -1) {
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

    // メインループ
    while (!ProcessMessage() && !ClearDrawScreen())
    {

        // 有理ベジェ曲線を描画
        for (int i = 0; i <= steps; ++i) {
            double t = t_min + (t_max - t_min) * i / steps;
            std::vector<double> result = rational_bezier_curve(control_points, weights, t);
            int x = static_cast<int>(result[0]);
            int y = static_cast<int>(result[1]);
            DrawPixel(x, y, GetColor(255, 255, 255));
        }

        // 画面の更新
        ScreenFlip();

        // キーが押されるまで待機
        WaitKey();
    }


    // DxLibの終了処理
    DxLib_End();

    return 0;
}
