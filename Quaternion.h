#pragma once
#include "Vector3.h"
#include "Matrix4.h"
#include <cmath>

class Quaternion
{
public:
	float x;
	float y;
	float z;
	float w;

	Quaternion();
	Quaternion(float x, float y, float z, float w);

	// Quaternion�̐�
	Quaternion Multiply(const Quaternion& lhs, const Quaternion& rhs);
	// �P��Quaternion��Ԃ�
	Quaternion IdentityQuaternion();
	// ����Quaternion��Ԃ�
	Quaternion Conjugate(const Quaternion& quat);
	// Quaternion��norm��Ԃ��@
	float Norm(const Quaternion& quat);
	// ���K������Quaternion��Ԃ�
	Quaternion Normalize(const Quaternion& quat);
	// �tQuaternion��Ԃ�
	Quaternion Inverse(const Quaternion& quat);

	// �C�ӎ���]��\��Quaternion�̐���
	Quaternion MakeAxisAngle(const Vector3& axis, float angle);
	// �x�N�g����Quaternion�ŉ�]���������ʂ̃x�N�g�������߂�
	Vector3 RotateVector(const Vector3& vector, const Quaternion& quat);
	// Quaternion�����]�s������߂�
	Matrix4 MakeRotateMatrix(const Quaternion& quat);
};

const Quaternion operator/(const Quaternion& q, float s);