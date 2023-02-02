#pragma once
#include"vector3.h"
#include"Matrix4.h"
class Quaternion
{
public:
	float x_;
	float y_;
	float z_;
	float w_;

	Quaternion();
	Quaternion(float x, float y, float z, float w);

	//Quaternion�̐�
	Quaternion Multiply(Quaternion r);
	//�P��Quaternion��Ԃ�
	Quaternion IdentityQuaternion();
	//����Quaternion��Ԃ�
	Quaternion Conjugate();
	//Quaternion��norm��Ԃ�
	float Norm() const;
	//���K������Quaternion��Ԃ�
	Quaternion Normalize();
	//�tQuaternion��Ԃ�
	Quaternion INverse();
	//�x�N�g����Quaternion�ŉ�]���������ʂ̃x�N�g�������߂�
	Vector3 RotateVector(const Vector3& vector);
	//Quaternion�����]�s������߂�
	Matrix4 MakeRotateMatrix();
	//�C�ӎ���]��\��Quaternion�̐���
	Quaternion MakeAxisAngle(const Vector3& axsi, float angle);
	// u����v�ւ̉�]�𐶐�
	Quaternion DirectionToDirection(const Vector3& u, const Vector3& v);

	//���ʐ��`���
	Quaternion Slerp(const Quaternion& p, float t);
	float Dot(const Quaternion& q)const;


	//�P�����Z�q�I�[�o�[���[�h
	Quaternion operator + ();
	Quaternion operator - ()const;

	//������Z�q�I�[�o�[���[�h
	Quaternion& operator += (const Quaternion& q);
	Quaternion& operator -= (const Quaternion& q);
	Quaternion& operator *= (float s);
	Quaternion& operator /= (float s);
	Quaternion& operator *= (const Quaternion& q);
};

//2�����Z�q�I�[�o�[���[�h
const Quaternion operator + (const Quaternion& q1, const Quaternion& q2);
const Quaternion operator - (const Quaternion& q1, const Quaternion& q2);
const Quaternion operator * (const Quaternion& q1, const Quaternion& q2);
const Quaternion operator * (const Quaternion& q, float s);
const Quaternion operator * (float s, const Quaternion& q);
const Quaternion operator / (const Quaternion& q, float s);
const Vector3 operator*(Quaternion q, Vector3 vec);