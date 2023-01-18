#include "Quaternion.h"

Quaternion::Quaternion()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
	this->w = 1;
}

Quaternion::Quaternion(float x, float y, float z, float w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

Quaternion Quaternion::Multiply(const Quaternion& lhs, const Quaternion& rhs)
{
	Quaternion quat;
	float f0, f1, f2, f3;

	f0 = lhs.w * rhs.w;
	f1 = -lhs.x * rhs.x;
	f2 = -lhs.y * rhs.y;
	f3 = -lhs.z * rhs.z;
	quat.w = f0 + f1 + f2 + f3;

	f0 = lhs.w * rhs.x;
	f1 = rhs.w * lhs.x;
	f2 = lhs.y * rhs.z;
	f3 = -lhs.z * rhs.y;
	quat.x = f0 + f1 + f2 + f3;

	f0 = lhs.w * rhs.y;
	f1 = rhs.w * lhs.y;
	f2 = lhs.z * rhs.x;
	f3 = -lhs.x * rhs.z;
	quat.y = f0 + f1 + f2 + f3;

	f0 = lhs.w * rhs.z;
	f1 = rhs.w * lhs.z;
	f2 = lhs.x * rhs.y;
	f3 = -lhs.y * rhs.x;
	quat.z = f0 + f1 + f2 + f3;

	return quat;
}

Quaternion Quaternion::IdentityQuaternion()
{
	Quaternion iden(0, 0, 0, 1);

	return iden;
}

Quaternion Quaternion::Conjugate(const Quaternion& quat)
{
	Quaternion mul;

	mul.x = -quat.x;
	mul.y = -quat.y;
	mul.z = -quat.z;
	mul.w = quat.w;

	return mul;
}

float Quaternion::Norm(const Quaternion& quat)
{
	float norm = sqrt(quat.x * quat.x + quat.y * quat.y + quat.z * quat.z + quat.w * quat.w);

	return norm;
}

Quaternion Quaternion::Normalize(const Quaternion& quat)
{
	float len = Norm(quat);

	if (len != 0)
	{
		Quaternion tmp = quat;
		tmp.x /= len;
		tmp.y /= len;
		tmp.z /= len;
		tmp.w /= len;

		return tmp;
	}

	return quat;
}

Quaternion Quaternion::Inverse(const Quaternion& quat)
{
	Quaternion Inv = Conjugate(quat) / (Norm(quat) * Norm(quat));
	return Inv;
}

Quaternion Quaternion::MakeAxisAngle(const Vector3& axis, float angle)
{
	Quaternion quat;

	quat.w = cos(angle / 2);

	Vector3 vec = axis * sin(angle / 2);

	quat.x = vec.x;
	quat.y = vec.y;
	quat.z = vec.z;

	return quat;
}

Vector3 Quaternion::RotateVector(const Vector3& vector, const Quaternion& quat)
{
	Quaternion vecQuat;

	vecQuat.w = 0;
	vecQuat.x = vector.x;
	vecQuat.y = vector.y;
	vecQuat.z = vector.z;

	Quaternion conQuat = Conjugate(quat);
	
	Multiply(quat);

	return Vector3();
}

Matrix4 Quaternion::MakeRotateMatrix(const Quaternion& quat)
{
	return Matrix4();
}

const Quaternion operator/(const Quaternion& q, float s)
{
	Quaternion result = q;
	result.x /= s;
	result.y /= s;
	result.z /= s;
	result.w /= s;

	return result;
}
