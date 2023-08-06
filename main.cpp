#include "DxLib.h"
#include <vector>
#include <cmath>

// �x�W�F���֐����v�Z����֐�
double bezier_basis(int i, int n, double t) {
    double coeff = 1.0;
    for (int j = 0; j < i; ++j) {
        coeff *= (1 - t); // (1 - t)��i����v�Z
    }
    for (int j = i + 1; j <= n; ++j) {
        coeff *= t; // t��n-i����v�Z
    }
    return coeff;
}

// �L���x�W�F�Ȑ����v�Z����֐�
std::vector<double> rational_bezier_curve(std::vector<std::vector<double>>& control_points, std::vector<double>& weights, double t) {
    int n = control_points.size() - 1;
    std::vector<double> result(3, 0.0); // 3�����̏ꍇ
    double sum_basis_times_weights = 0.0;
    double sum_basis_times_weights_times_points = 0.0;

    // �x�W�F���֐��̌v�Z�Əd�ݕt���̍��v�����߂�
    for (int i = 0; i <= n; ++i) {
        double basis = bezier_basis(i, n, t);
        double weighted_basis = basis * weights[i];
        sum_basis_times_weights += weighted_basis;

        for (int j = 0; j < 3; ++j) { // 3�����̏ꍇ
            sum_basis_times_weights_times_points += weighted_basis * control_points[i][j];
        }
    }

    // �L���x�W�F�Ȑ���̓_���v�Z
    for (int i = 0; i < 3; ++i) { // 3�����̏ꍇ
        result[i] = sum_basis_times_weights_times_points / sum_basis_times_weights;
    }

    return result;
}


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    // DxLib�̏�����
    if (DxLib_Init() == -1) {
        return -1;
    }

    // �E�B���h�E���쐬
    ChangeWindowMode(TRUE);
    SetGraphMode(800, 600, 32);
    if (SetMainWindowText("Rational Bezier Curve - Moving Control Points") == -1) {
        return -1;
    }
    if (DxLib_Init() == -1) {
        return -1;
    }

    // ����_�ƃE�F�C�g�̒�`
    std::vector<std::vector<double>> control_points = {
        {50.0, 200.0, 0.0},
        {300.0, 0.0, 0.0},
        {500.0, 300.0, 0.0},
        {750.0, 0.0, 0.0},
        {700.0, 400.0, 0.0}
    };
    std::vector<double> weights = { 1.0, 0.5, 2.0, 1.5, 1.0 };

    // �p�����[�^t�͈̔́i0.0�`1.0�j�ƃX�e�b�v��
    double t_min = 0.0;
    double t_max = 1.0;
    int steps = 100;

    // �Ԃ����́i����_�j�̔��a
    float controlPointRadius = 10.0f;

    // ����_��i�ނ悤�ȃ��C�����[�v
    double t = t_min;
    double t_step = (t_max - t_min) / steps;
    while (!ProcessMessage() && !CheckHitKey(KEY_INPUT_ESCAPE)) {
        // �`��J�n
        ClearDrawScreen();

        // �x�W�F�Ȑ��̕]��
        std::vector<double> result = rational_bezier_curve(control_points, weights, t);
        float x = static_cast<float>(result[0]);
        float y = static_cast<float>(result[1]);
        float z = static_cast<float>(result[2]);

        // �Ԃ����̂�`��i����_�j
        DrawSphere3D(VGet(x, y, z), controlPointRadius,2, GetColor(255, 0, 0), GetColor(255, 0, 0),true);
        DrawFormatString(0, 0, GetColor(255, 255, 255), "pointX:%f", x);
        DrawFormatString(0, 25, GetColor(255, 255, 255), "pointY:%f", y);

        // �x�W�F�Ȑ��̃p�����[�^t���X�V
        t += t_step;
        if (t > t_max) {
            t = t_min;
        }

        // �`��I��
        ScreenFlip();
    }

    // DxLib�̏I������
    DxLib_End();

    return 0;
}