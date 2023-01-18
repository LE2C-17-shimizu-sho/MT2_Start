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

	// Quaternion‚ÌÏ
	Quaternion Multiply(const Quaternion& lhs, const Quaternion& rhs);
	// ’PˆÊQuaternion‚ğ•Ô‚·
	Quaternion IdentityQuaternion();
	// ‹¤–ğQuaternion‚ğ•Ô‚·
	Quaternion Conjugate(const Quaternion& quat);
	// Quaternion‚Ìnorm‚ğ•Ô‚·@
	float Norm(const Quaternion& quat);
	// ³‹K‰»‚µ‚½Quaternion‚ğ•Ô‚·
	Quaternion Normalize(const Quaternion& quat);
	// ‹tQuaternion‚ğ•Ô‚·
	Quaternion Inverse(const Quaternion& quat);
};

const Quaternion operator/(const Quaternion& q, float s);