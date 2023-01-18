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
	float d0, d1, d2, d3;

	d0 = lhs.w * rhs.w;
	d1 = -lhs.x * rhs.x;
	d2 = -lhs.y * rhs.y;
	d3 = -lhs.z * rhs.z;
	quat.w = d0 + d1 + d2 + d3;

	d0 = lhs.w * rhs.x;
	d1 = rhs.w * lhs.x;
	d2 = lhs.y * rhs.z;
	d3 = -lhs.z * rhs.y;
	quat.x = d0 + d1 + d2 + d3;

	d0 = lhs.w * rhs.y;
	d1 = rhs.w * lhs.y;
	d2 = lhs.z * rhs.x;
	d3 = -lhs.x * rhs.z;
	quat.y = d0 + d1 + d2 + d3;

	d0 = lhs.w * rhs.z;
	d1 = rhs.w * lhs.z;
	d2 = lhs.x * rhs.y;
	d3 = -lhs.y * rhs.x;
	quat.z = d0 + d1 + d2 + d3;

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

const Quaternion operator/(const Quaternion& q, float s)
{
	Quaternion result = q;
	result.x /= s;
	result.y /= s;
	result.z /= s;
	result.w /= s;

	return result;
}
