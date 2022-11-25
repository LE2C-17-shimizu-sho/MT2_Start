#include "DxLib.h"
#include "Vector2.h"
#include <cmath>

bool CollisionLineCircle(Vector2& startLine, Vector2& endLine, Vector2& circle, int radius);

// �E�B���h�E�̃^�C�g���ɕ\�����镶����
const char TITLE[] = "LE2C_17_�V�~�Y�V���E: �^�C�g��";

// �E�B���h�E����
const int WIN_WIDTH = 600;

// �E�B���h�E�c��
const int WIN_HEIGHT = 400;

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine,
                   _In_ int nCmdShow) {
	// �E�B���h�E���[�h�ɐݒ�
	ChangeWindowMode(TRUE);

	// �E�B���h�E�T�C�Y���蓮�ł͕ύX�������A
	// ���E�B���h�E�T�C�Y�ɍ��킹�Ċg��ł��Ȃ��悤�ɂ���
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	// �^�C�g����ύX
	SetMainWindowText(TITLE);

	// ��ʃT�C�Y�̍ő�T�C�Y�A�J���[�r�b�g����ݒ�(���j�^�[�̉𑜓x�ɍ��킹��)
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);

	// ��ʃT�C�Y��ݒ�(�𑜓x�Ƃ̔䗦�Őݒ�)
	SetWindowSizeExtendRate(1.0);

	// ��ʂ̔w�i�F��ݒ肷��
	SetBackgroundColor(0x00, 0x00, 0x00);

	// DXlib�̏�����
	if (DxLib_Init() == -1) { return -1; }

	// (�_�u���o�b�t�@)�`���O���t�B�b�N�̈�͗��ʂ��w��
	SetDrawScreen(DX_SCREEN_BACK);

	// �y�o�b�t�@��L���ɂ���
	SetUseZBuffer3D(TRUE);

	// �y�o�b�t�@�ւ̏������݂�L���ɂ���
	SetWriteZBuffer3D(TRUE);


	// �摜�Ȃǂ̃��\�[�X�f�[�^�̕ϐ��錾�Ɠǂݍ���


	// �Q�[�����[�v�Ŏg���ϐ��̐錾
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

	// �ŐV�̃L�[�{�[�h���p
	char keys[256] = {0};

	// 1���[�v(�t���[��)�O�̃L�[�{�[�h���
	char oldkeys[256] = {0};

	// �Q�[�����[�v
	while (true) {
		// �ŐV�̃L�[�{�[�h��񂾂������̂�1�t���[���O�̃L�[�{�[�h���Ƃ��ĕۑ�
		// �ŐV�̃L�[�{�[�h�����擾
		GetHitKeyStateAll(keys);

		// ��ʃN���A
		ClearDrawScreen();
		//---------  ��������v���O�������L�q  ----------//

		// �X�V����
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
		


		// �`�揈��
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

		//---------  �����܂łɃv���O�������L�q  ---------//
		// (�_�u���o�b�t�@)����
		ScreenFlip();

		// 20�~���b�ҋ@(�^��60FPS)
		WaitTimer(20);

		// Windows�V�X�e�����炭�������������
		if (ProcessMessage() == -1) {
			break;
		}

		// ESC�L�[�������ꂽ�烋�[�v���甲����
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
			break;
		}
	}
	// Dx���C�u�����I������
	DxLib_End();

	// ����I��
	return 0;
}

bool CollisionLineCircle(Vector2& startLine, Vector2& endLine, Vector2& circle, int radius)
{
	Vector2 vecLine = endLine - startLine;

	Vector2 endLineCircle = circle - endLine;

	Vector2 startLineCircle = circle - startLine;

	Vector2 normLineVec = vecLine.normalize();

	float distance = startLineCircle.cross(normLineVec);

	// ��悷��
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