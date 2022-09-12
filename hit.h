#pragma once
#include<math.h>
#include"DxLib.h"

//矩形
float	CheckBox(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2);
//矩形と円
						//円						//矩形
bool	CheckBoxCircle(float x1, float y1, float r, float x2, float y2, float w2, float h2);

//辺
				//プレイヤー					//マップ
bool	CheckSide1(float x1, float y1, float r, float x2, float y2, float w2,float	h2);
				//プレイヤー					//マップ
bool	CheckSide2(float x1, float y1, float r, float x2, float y2, float w2, float	h2);//矩形
				//プレイヤー					//マップ
bool	CheckSide3(float x1, float y1, float r, float x2, float y2, float w2, float	h2);//矩形
				//プレイヤー					//マップ
bool	CheckSide4(float x1, float y1, float r, float x2, float y2, float w2, float	h2);





//辺
				//敵							//マップ
bool	CheckSideE1(float x1, float y1, float r, float x2, float y2, float w2, float	h2,float	num);
				//敵							//マップ
bool	CheckSideE2(float x1, float y1, float r, float x2, float y2, float w2, float	h2, float	num);//矩形
				//敵							//マップ
bool	CheckSideE3(float x1, float y1, float r, float x2, float y2, float w2, float	h2, float	num);//矩形
				//敵							//マップ
bool	CheckSideE4(float x1, float y1, float r, float x2, float y2, float w2, float	h2, float	num);


bool	CheckSideE11(float x1, float y1, float r, float x2, float y2, float w2, float	h2, float	num);
bool	CheckSideE21(float x1, float y1, float r, float x2, float y2, float w2, float h2, float	num);
bool	CheckSideE31(float x1, float y1, float r, float x2, float y2, float w2, float h2, float	num);
bool	CheckSideE41(float x1, float y1, float r, float x2, float y2, float w2, float h2, float	num);

//円
float	CheckCircle(float x1, float y1, float r1, float x2, float y2, float r2);

//点と円
bool	CheckCircleDot(float	x1, float	y1, float	r, float	x2, float	y2);

//4点と円
bool	CheckCircleDot4(float	x1, float	y1, float	r, float	x2, float	y2, float	w, float	h);

bool	CheckCircleDotL(float	x1, float	y1, float	r, float	x2, float	y2, float	w, float	h);