#include "Quaternion.h"
#include<cmath>

Quaternion::Quaternion()
{
	w = 1;
	x = 0;
	y = 0;
	z = 0;
}

Quaternion::Quaternion(float x, float y, float z, float w)
{
	w = w;
	x = x;
	y = y;
	z = z;
}

Quaternion Quaternion::Multiply(Quaternion r)
{
	Quaternion result;

	result.w = w * r.w - x * r.x - y * r.y - z * r.z;
	result.x = y * r.z - z * r.y + r.w * x + w * r.x;
	result.y = z * r.x - x * r.z + r.w * y + w * r.y;
	result.z = x * r.y - y * r.x + r.w * z + w * r.z;

	return result;
}

Quaternion Quaternion::IdentityQuaternion()
{
	Quaternion result;

	result.w = 1;
	result.x = 0;
	result.y = 0;
	result.z = 0;

	return result;
}

Quaternion Quaternion::Conjugate()
{
	Quaternion result;

	result.w = w;
	result.x = -x;
	result.y = -y;
	result.z = -z;

	return result;
}

float Quaternion::Norm() const
{
	return sqrt(pow(w, 2) + pow(x, 2) + pow(y, 2) + pow(z, 2));
}

Quaternion Quaternion::Normalize()
{
	Quaternion result = *this;

	float len = Norm();

	result = result / len;

	return result;
}

Quaternion Quaternion::INverse()
{
	Quaternion result = Conjugate() / pow(Norm(), 2);

	return result;
}

Quaternion MakeAxisAngle(const Vector3& axsi, float angle)
{
	Quaternion result;

	result.w = cos(angle / 2);

	Vector3 VecResult = axsi * sin(angle / 2);

	result.x = VecResult.x;
	result.y = VecResult.y;
	result.z = VecResult.z;

	return result;
}

Vector3 Quaternion::RotateVector(const Vector3& vector)
{
	Quaternion result;
	Quaternion VecQua;

	VecQua.w = 0;
	VecQua.x = vector.x;
	VecQua.y = vector.y;
	VecQua.z = vector.z;

	Quaternion conQuaternion = Conjugate();

	result = Multiply(VecQua);
	result = result.Multiply(conQuaternion);

	return { result.x,result.y,result.z };
}

Matrix4 Quaternion::MakeRotateMatrix()
{
	Matrix4 result = identity();

	result.m[0][0] = w * w + x * x - y * y - z * z;
	result.m[0][1] = 2 * (x * y + w * z);
	result.m[0][2] = 2 * (x * z - w * y);
	result.m[1][0] = 2 * (x * y - w * z);
	result.m[1][1] = w * w - x * x + y * y - z * z;
	result.m[1][2] = 2 * (y * z + w * x);
	result.m[2][0] = 2 * (x * z + w * y);
	result.m[2][1] = 2 * (y * z - w * x);
	result.m[2][2] = w * w - x * x - y * y + z * z;

	return result;
}

const Quaternion operator/(const Quaternion& v, float s)
{
	Quaternion result;

	result.w = v.w / s;
	result.x = v.x / s;
	result.y = v.y / s;
	result.z = v.z / s;

	return result;
}