#pragma once
#include<math.h>
#include"DxLib.h"

//��`
float	CheckBox(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2);
//��`�Ɖ~
						//�~						//��`
bool	CheckBoxCircle(float x1, float y1, float r, float x2, float y2, float w2, float h2);

//��
				//�v���C���[					//�}�b�v
bool	CheckSide1(float x1, float y1, float r, float x2, float y2, float w2,float	h2);
				//�v���C���[					//�}�b�v
bool	CheckSide2(float x1, float y1, float r, float x2, float y2, float w2, float	h2);//��`
				//�v���C���[					//�}�b�v
bool	CheckSide3(float x1, float y1, float r, float x2, float y2, float w2, float	h2);//��`
				//�v���C���[					//�}�b�v
bool	CheckSide4(float x1, float y1, float r, float x2, float y2, float w2, float	h2);

//�~
float	CheckCircle(float x1, float y1, float r1, float x2, float y2, float r2);

//�_�Ɖ~
bool	CheckCircleDot(float	x1, float	y1, float	r, float	x2, float	y2);

//4�_�Ɖ~
bool	CheckCircleDot4(float	x1, float	y1, float	r, float	x2, float	y2, float	w, float	h);

bool	CheckCircleDotL(float	x1, float	y1, float	r, float	x2, float	y2, float	w, float	h);