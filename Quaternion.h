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

	// Quaternionの積
	Quaternion Multiply(const Quaternion& lhs, const Quaternion& rhs);
	// 単位Quaternionを返す
	Quaternion IdentityQuaternion();
	// 共役Quaternionを返す
	Quaternion Conjugate(const Quaternion& quat);
	// Quaternionのnormを返す　
	float Norm(const Quaternion& quat);
	// 正規化したQuaternionを返す
	Quaternion Normalize(const Quaternion& quat);
	// 逆Quaternionを返す
	Quaternion Inverse(const Quaternion& quat);

	// 任意軸回転を表すQuaternionの生成
	Quaternion MakeAxisAngle(const Vector3& axis, float angle);
	// ベクトルをQuaternionで回転させた結果のベクトルを求める
	Vector3 RotateVector(const Vector3& vector, const Quaternion& quat);
	// Quaternionから回転行列を求める
	Matrix4 MakeRotateMatrix(const Quaternion& quat);
};

const Quaternion operator/(const Quaternion& q, float s);