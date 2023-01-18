#pragma once
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
};

const Quaternion operator/(const Quaternion& q, float s);