#include "DxLib.h"
#include "Vector3.h"
#include "Vector2.h"
#include"Matrix4.h"
#include<cstring>
// �֐��v���g�^�C�v�錾
int DrawCircle(Vector2 vec, int r, unsigned int color);

//Vector3�^�𗘗p���₷�����邽�߂� �I�[�o�[���[�h�֐��Q
//���̕`��
//DxLib = > int DrawSphere3D(VECTOR Centerpos, float r, int DivNum, unsigned int DifColor, unsigned int Spccolor, int FillFlag);
int DrawSphere3D(const Vector3& CenterPos, const float r, const int DivNum, const unsigned int Difcolor, const unsigned int Spccolor, const int FillFlag);

//�����̕`��
// DxLib => int DrawLine3D(VECTOR Pos1, VECTOR Pos2, unsigned int Color);
int DrawLine3D(const Vector3& Pos1, const Vector3& Pos2, const unsigned int Color);

//�~��(cone)�̕`��
// DxLib => int DrawCone3D( VECTOR TopPos, VECTOR Bottompos, float r, int DivNum, unsigned int Difcolor, unsigned int Spccolor,int FillFlag);
int DrawCone3D(const Vector3& Toppos, const Vector3& BottomPos, const float r,
	const int DivNum, const unsigned int Difcolor, const unsigned int Spccolor, const int FillFlag);

// �J�����̈ʒu�Ǝp���̐ݒ�
// DxLib => int SetCamerapositionAndTargetAndUpVec(VECTOR Position, VECTOR Target, VECTOR Up);
int SetCameraPositionAndTargetAndUpVec(
	const Vector3& cameraPosition,//�J�����̈ʒu 
	const Vector3& cameraTarget,//�J�����̒����_
	const Vector3& cameraUp //�J�����̏�̌���
);

//�֐��v���g�^�C�v�錾
void DrawAxis3D(const float length); // x,y,z ���̕`��
void DrawKeyOperation(); //�L�[����̕`��

// �E�B���h�E�̃^�C�g���ɕ\�����镶����
const char TITLE[] = "LE2B_13_�V�~�Y_�V���E: �^�C�g��";

// �E�B���h�E����
const int WIN_WIDTH = 1600;

// �E�B���h�E�c��
const int WIN_HEIGHT = 900;

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine,
	_In_ int nCmdShow)
{
	// �E�B���h�E���[�h�ɐݒ�
	ChangeWindowMode(TRUE);

	// �^�C�g����ύX
	SetMainWindowText(TITLE);

	// ��ʃT�C�Y�̍ő�T�C�Y�A�J���[�r�b�g����ݒ�(���j�^�[�̉𑜓x�ɍ��킹��)
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);

	// ��ʃT�C�Y��ݒ�(�𑜓x�Ƃ̔䗦�Őݒ�)
	SetWindowSizeExtendRate(1.0);

	// ��ʂ̔w�i�F��ݒ肷��
	SetBackgroundColor(0x00, 0x00, 0x40);

	// DXlib�̏�����
	if (DxLib_Init() == -1)
	{
		return -1;
	}

	// (�_�u���o�b�t�@)�`���O���t�B�b�N�̈�͗��ʂ��w��
	SetDrawScreen(DX_SCREEN_BACK);

	// �摜�Ȃǂ̃��\�[�X�f�[�^�̕ϐ��錾�Ɠǂݍ���


	// �Q�[�����[�v�Ŏg���ϐ��̐錾

	// �ŐV�̃L�[�{�[�h���p
	char keys[256] = { 0 };

	// 1���[�v(�t���[��)�O�̃L�[�{�[�h���
	char oldkeys[256] = { 0 };

	// �y�o�b�t�@��L���ɂ���
	SetUseZBuffer3D(TRUE);
	// �y�o�b�t�@�ւ̏������݂�L���ɂ���
	SetWriteZBuffer3D(TRUE);

	//�N���b�v�ʋ߉�
	SetCameraNearFar(1.0f, 10000.0f);//�J�����̗L���͈͂�ݒ�
	SetCameraScreenCenter(WIN_WIDTH / 2.0f, WIN_HEIGHT / 2.0f); //��ʂ̒��S���J�����̒��S�ɍ��킹��
	SetCameraPositionAndTargetAndUpVec(
		Vector3(0.0f, 200.0f, 0.0f),
		Vector3(0.0f, 0.0f, 0.0f),
		Vector3(0.0f, 0.0f, 1.0f));

	// ���Ԍv���ɕK�v�ȃf�[�^
	long long startCount = 0;
	long long nowCount = 0;
	long long elapsedCount = 0;

	// ��ԂŎg���f�[�^
	// start �� end �� 5 [s] �Ŋ���������
	Vector3 p0(-100.0f, 0.0f, 0.0f);
	Vector3 p1(-10.0f,  0.0f, 50.0f);
	Vector3 p2(+10.0f,  0.0f, -50.0f);
	Vector3 p3(+100.0f, 0.0f, 0.0f);
	float maxTime = 5.0f;
	float timeRate;

	// ���̈ʒu
	Vector3 position;

	// ���s�O�� �J�E���^�l���擾
	startCount = GetNowHiPerformanceCount(); // long long int�^  64bit int

	// �Q�[�����[�v
	while (true)
	{
		// �ŐV�̃L�[�{�[�h��񂾂������̂�1�t���[���O�̃L�[�{�[�h���Ƃ��ĕۑ�
		for (int i = 0; i < 256; ++i)
		{
			oldkeys[i] = keys[i];
		}
		// �ŐV�̃L�[�{�[�h�����擾
		GetHitKeyStateAll(keys);

		//---------  ��������v���O�������L�q  ----------//

		//�X�V

		// [R]�L�[�ŁA���X�^�[�g
		if (CheckHitKey(KEY_INPUT_R))
		{
			startCount = GetNowHiPerformanceCount();
		}

		// �o�ߎ���(elapsedTime [s]) �̌v�Z
		nowCount = GetNowHiPerformanceCount();
		elapsedCount = nowCount - startCount;
		float elapsedTime = static_cast<float> (elapsedCount) / 1'000'000.0f;

		// �X�^�[�g�n�_		: start (p0)
		// �G���h�n�_		: end   (p3)
		// �o�ߎ���			: elapsedTime [s]
		// �ړ������̗�(�o�ߎ���/�S�̎���) : timeRate (%)

		timeRate = min(elapsedTime / maxTime, 1.0f);

		// 3���x�W�F�Ȑ��̌v�Z
		Vector3 a = lerp(p0, p1, timeRate);
		Vector3 b = lerp(p1, p2, timeRate);
		Vector3 c = lerp(p2, p3, timeRate);
		Vector3 d = lerp(a, b, timeRate);
		Vector3 e = lerp(b, c, timeRate);

		position = lerp(d, e, timeRate);

		//�`��---------------
		ClearDrawScreen();//��ʂ�����
		DrawAxis3D(500.0f);//xyz���̕`��

		// ���̕`��
		DrawSphere3D(position, 5.0f, 32, GetColor(255, 0, 0), GetColor(255, 255, 255), true);

		DrawSphere3D(p0, 2.0f, 32, GetColor(0, 255, 0), GetColor(255, 255, 255), true);
		DrawSphere3D(p1, 2.0f, 32, GetColor(0, 255, 0), GetColor(255, 255, 255), true);
		DrawSphere3D(p2, 2.0f, 32, GetColor(0, 255, 0), GetColor(255, 255, 255), true);
		DrawSphere3D(p3, 2.0f, 32, GetColor(0, 255, 0), GetColor(255, 255, 255), true);

		// 
		DrawFormatString(0, 0, GetColor(255, 255, 255), "position (%6.1f,%6.1f,%6.1f)", position.x, position.y, position.z);

		DrawFormatString(0, 20, GetColor(255, 255, 255), "%7.3f [s]", elapsedTime);
		DrawFormatString(0, 40, GetColor(255, 255, 255), "[R] : Restart");

		DrawFormatString(0, 80, GetColor(255, 255, 255), "p0 (%6.1f,%6.1f,%6.1f)", p0.x, p0.y, p0.z);

		DrawFormatString(0, 100, GetColor(255, 255, 255), "p1 (%6.1f,%6.1f,%6.1f)", p1.x, p1.y, p1.z);

		DrawFormatString(0, 120, GetColor(255, 255, 255), "p2 (%6.1f,%6.1f,%6.1f)", p2.x, p2.y, p2.z);

		DrawFormatString(0, 140, GetColor(255, 255, 255), "p3 (%6.1f,%6.1f,%6.1f)", p3.x, p3.y, p3.z);


		DrawKeyOperation();// �L�[����̕`��

		//---------  �����܂łɃv���O�������L�q  ---------//
		// (�_�u���o�b�t�@)����
		ScreenFlip();

		// 20�~���b�ҋ@(�^��60FPS)
		WaitTimer(20);

		// Windows�V�X�e�����炭�������������
		if (ProcessMessage() == -1)
		{
			break;
		}

		// ESC�L�[�������ꂽ�烋�[�v���甲����
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			break;
		}
	}
	// Dx���C�u�����I������
	DxLib_End();

	// ����I��
	return 0;
}

//�I�[�o�[���[�h

// �~yz���̕`��
void DrawAxis3D(const float length)
{
	//���̐��̕`��
	DrawLine3D(Vector3(-length, 0, 0), Vector3(+length, 0, 0), GetColor(255, 0, 0));//x��
	DrawLine3D(Vector3(0, -length, 0), Vector3(0, +length, 0), GetColor(0, 255, 0));//y��
	DrawLine3D(Vector3(0, 0, -length), Vector3(0, 0, +length), GetColor(0, 0, 255));//z��

	//���̐�̕`�� ���~yz���̐���ۂɁA�~��������
	/*const float coneSize = 10.0f;
	DrawCone3D(Vector3(length, 0, 0), Vector3(length - coneSize, 0, 0), coneSize / 2, 16,
		GetColor(255, 0, 0), GetColor(255, 255, 255), TRUE);

	DrawCone3D(Vector3(0, length, 0), Vector3(0, length - coneSize, 0), coneSize / 2, 16,
		GetColor(0, 255, 0), GetColor(255, 255, 255), TRUE);

	DrawCone3D(Vector3(0, 0, length), Vector3(0, 0, length - coneSize), coneSize / 2, 16,
		GetColor(0, 0, 255), GetColor(255, 255, 255), TRUE);*/

}

//�L�[����̕`��
void DrawKeyOperation()
{
	const unsigned white = GetColor(255, 255, 255);
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

//���̕`��
//(!DXLib = > int DrawSphere3D(VECTOR Centerpos, float r, int DivNum, unsigned int DifColor, unsigned int Spccolor, int FillFlag);
int DrawSphere3D(const Vector3& CenterPos, const float r, const int DivNum, const unsigned int DifColor, const unsigned int SpcColor, const int FillFlag)
{
	VECTOR centerPos = { CenterPos.x, CenterPos.y, CenterPos.z };//�\���� ���������X�g

	return DrawSphere3D(centerPos, r, DivNum, DifColor, SpcColor, FillFlag); //DxLib�֐��̌Ăяo��
}

//�����̕`��
//DxLib = > int DrawLine3D(VECTOR Pos1, VECTOR Pos2, unsigned int Color);
int DrawLine3D(const Vector3& Pos1, const Vector3& Pos2, const unsigned int color)
{
	VECTOR p1 = { Pos1.x, Pos1.y, Pos1.z };//�\���� �������q���X�g
	VECTOR p2 = { Pos2.x, Pos2.y, Pos2.z };//�\���� �������q���X�g

	return DrawLine3D(p1, p2, color);//DxLib�֐��̌Ăяo��
}

//�J�����̈ʒu�Ǝp���̐ݒ�
//DxLib = > int SetCamerapositionAndTargetAndUpVec(VECTOR Position, VECTOR Target, VECTOR Up);
int SetCameraPositionAndTargetAndUpVec(
	const Vector3& cameraPosition,//�J�����̈ʒu
	const Vector3& cameraTarget, //�J�����̒����_
	const Vector3& cameraUp //�J�����̏�̌���
)
{
	VECTOR position = { cameraPosition.x, cameraPosition.y, cameraPosition.z };
	VECTOR target = { cameraTarget.x, cameraTarget.y, cameraTarget.z };
	VECTOR up = { cameraUp.x, cameraUp.y, cameraUp.z };
	return SetCameraPositionAndTargetAndUpVec(position, target, up);
}

//���f���̍��W�ϊ��p�s����Z�b�g����
int MV1SetMatrix(const int MHandle, const Matrix4 Matrix)
{
	MATRIX matrix;
	std::memcpy(&matrix, &Matrix, sizeof MATRIX);//�������ԃR�s�[
	return MV1SetMatrix(MHandle, matrix);
}