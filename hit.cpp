#include"hit.h"

//矩形
float	CheckBox(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2) {
	float cl1 = x1;
	float	cr1 = x1 + w1;
	float cl2 = x2;
	float	cr2 = x2 + w2;

	if (cr1 <= cl2)
	{
		return	0;
	}

	if (cr2 <= cl1)
	{
		return	0;
	}

	float	cu1 = y1;
	float	cd1 = y1 + h1;
	float	cu2 = y2;
	float	cd2 = y2 + h2;

	if (cd1 <= cu2)
	{
		return	0;
	}

	if (cd2 <= cu1)
	{
		return	0;
	}

	return	1;
}

//矩形と円
						//円						//矩形
bool	CheckBoxCircle(float x1, float y1, float r, float x2, float y2, float w2, float h2) {
	float	cl1 = x1 - r;
	float	cr1 = x1 + r;
	float	cl2 = x2;
	float	cr2 = x2 + w2;

	if (cr1 <= cl2)
	{
		return	0;
	}

	if (cr2 <= cl1)
	{
		return	0;
	}

	float	cu1 = y1 - r;
	float	cd1 = y1 + r;
	float	cu2 = y2;
	float	cd2 = y2 + h2;

	if (cd1 <= cu2)
	{
		return	0;
	}

	if (cd2 <= cu1)
	{
		return	0;
	}

	return	1;
}


///--------------------------------///
///		   player						 map
///			  2				///			  4
///		-------------		///		-------------
///		|			|		///		|			|
///		|			|		///		|			|
/// 1	|			|	3	/// 3	|			|	1
///		|			|		///		|			|
///		|			|		///		|			|
///		-------------		///		-------------
///			 4				///			 2				
///--------------------------------///

//辺
bool	CheckSide1(float x1, float y1, float r, float x2, float y2, float w2,float	h2){
	float	cl1 = x1 - r;
	float	cr2 = x2 + w2 + 2;

	if (cr2 <= cl1)
	{
		return	0;
	}

	float	cu1 = y1 - r;
	float	cd1 = y1 + r;
	float	cu2 = y2;
	float	cd2 = y2 + h2;

	if (cd1 <= cu2)
	{
		return	0;
	}

	if (cd2 <= cu1)
	{
		return	0;
	}

	return	1;
}
bool	CheckSide2(float x1, float y1, float r, float x2, float y2, float w2, float h2) {
	float cl1 = x1-r;
	float	cr1 = x1 + r;
	float cl2 = x2;
	float	cr2 = x2 + w2;

	if (cr1 <= cl2)
	{
		return	0;
	}

	if (cr2 <= cl1)
	{
		return	0;
	}

	float	cu1 = y1-r;
	float	cd2 = y2 + h2 + 2;

	if (cd2 <= cu1)
	{
		return	0;
	}

	return	1;
}
bool	CheckSide3(float x1, float y1, float r,float x2, float y2, float w2, float h2) {
	float	cr1 = x1 + r;
	float	cl2 = x2 - 2;

	if (cr1 <= cl2)
	{
		return	0;
	}

	float	cu1 = y1 - r;
	float	cd1 = y1 + r;
	float	cu2 = y2;
	float	cd2 = y2 + h2;

	if (cd1 <= cu2)
	{
		return	0;
	}

	if (cd2 <= cu1)
	{
		return	0;
	}

	return	1;
}
bool	CheckSide4(float x1, float y1, float r, float x2, float y2, float w2, float h2) {
	float cl1 = x1-r;
	float	cr1 = x1 + r;
	float cl2 = x2;
	float	cr2 = x2 + w2;

	if (cr1 <= cl2)
	{
		return	0;
	}

	if (cr2 <= cl1)
	{
		return	0;
	}

	float	cd1 = y1 + r;
	float	cu2 = y2 - 2;


	if (cd1 <= cu2)
	{
		return	0;
	}

	return	1;
}

bool	CheckSideE1(float x1, float y1, float r, float x2, float y2, float w2, float	h2, float	num) {
	float	cl1 = x1 - r - num;
	float	cr1 = x1 - r;
	float	cl2 = x2 + w2;
	float	cr2 = x2 + w2;

	if (cr1 < cl2)
	{
		return	0;
	}

	if (cr2 < cl1)
	{
		return	0;
	}

	float	cu1 = y1 - r;
	float	cd1 = y1 + r;
	float	cu2 = y2;
	float	cd2 = y2 + h2;

	if (cd1 < cu2)
	{
		return	0;
	}

	if (cd2 < cu1)
	{
		return	0;
	}

	return	1;
}
bool	CheckSideE2(float x1, float y1, float r, float x2, float y2, float w2, float h2,float	num) {
	float	cl1 = x1 - r;
	float	cr1 = x1 + r;
	float	cl2 = x2 ;
	float	cr2 = x2 + w2;

	if (cr1 < cl2)
	{
		return	0;
	}

	if (cr2 < cl1)
	{
		return	0;
	}

	float	cu1 = y1 - r - num;
	float	cd1 = y1 - r;
	float	cu2 = y2 + h2;
	float	cd2 = y2 + h2;


	if (cd1 < cu2)
	{
		return	0;
	}

	if (cd2 <cu1)
	{
		return	0;
	}

	return	1;
}
bool	CheckSideE3(float x1, float y1, float r, float x2, float y2, float w2, float h2,float	num) {
	float	cl1 = x1 + r;
	float	cr1 = x1 + r + num;
	float	cl2 = x2 ;
	float	cr2 = x2 ;
	if (cr1 < cl2)
	{
		return	0;
	}

	if (cr2 < cl1)
	{
		return	0;
	}


	float	cu1 = y1 - r;
	float	cd1 = y1 + r;
	float	cu2 = y2;
	float	cd2 = y2 + h2;

	if (cd1 < cu2)
	{
		return	0;
	}

	if (cd2 <cu1)
	{
		return	0;
	}

	return	1;
}
bool	CheckSideE4(float x1, float y1, float r, float x2, float y2, float w2, float h2,float	num) {
	float cl1 = x1 - r;
	float	cr1 = x1 + r;
	float cl2 = x2;
	float	cr2 = x2 + w2;

	if (cr1 < cl2)
	{
		return	0;
	}

	if (cr2 < cl1)
	{
		return	0;
	}
	float	cu1 = y1 + r;
	float	cd1 = y1 + r+num;
	float	cu2 = y2 ;
	float	cd2 = y2 ;

	if (cd1 < cu2)
	{
		return	0;
	}

	if (cd2 < cu1)
	{
		return	0;
	}

	return	1;
}

//円
float	CheckCircle(float x1, float y1, float r1, float x2, float y2, float r2) {
	float sum_x = (x1 - x2) * (x1 - x2);
	float	sum_y = (y1 - y2) * (y1 - y2);
	float sum_r = (r1 + r2) * (r1 + r2);


	if (sum_r > sum_y + sum_x)
	{
		return	1;
	}
	return	0;
}
//点と円
bool	CheckCircleDot(float	x1, float	y1, float	r, float	x2, float	y2) {
	float	dx= (x1 - x2) * (x1 - x2);
	float	dy = (y1 - y2) * (y1 - y2);
	float	dr = r * r;
	
	if (dr >= dx + dy)
	{
		return	true;
	}
	return	false;
};

//4点と円
bool	CheckCircleDot4(float	x1, float	y1, float	r, float	x2, float	y2, float	w, float	h)
{
	if (CheckCircleDot(x1, y1, r, x2, y2)) { return	true; };		//右上
	if (CheckCircleDot(x1, y1, r, x2, y2 + h)) { return	true; };	//右下
	if (CheckCircleDot(x1, y1, r, x2 + w, y2)) { return	true; };	//左上
	if (CheckCircleDot(x1, y1, r, x2 + w, y2 + h)) { return	true; };//左下
	if (CheckCircleDot(x1, y1, r, x2 + (w / 2), y2)) { return	true; };//上辺真ん中
	if (CheckCircleDot(x1, y1, r, x2, y2 + (h / 2))) { return	true; };//左辺真ん中
	if (CheckCircleDot(x1, y1, r, x2 + (w / 2), y2 + h)) { return	true; };//下辺真ん中
	if (CheckCircleDot(x1, y1, r, x2 + w, y2 + (h / 2))) { return	true; };//右辺真ん中

	return	false;
}

bool	CheckCircleDotL(float	x1, float	y1, float	r, float	x2, float	y2, float	w, float	h)
{
	
	if (CheckCircleDot(x1, y1, r, x2 , y2)&&			//左上
		CheckCircleDot(x1, y1, r, x2, y2 + (h * 0.25)) )//左下のちょい上
	{ return	true; };	
	if (CheckCircleDot(x1, y1, r, x2 , y2 + h)&&		  //左下
		 CheckCircleDot(x1, y1, r, x2, y2 + (h * 0.75))) //左上のちょい下
	{ return	true; };

	if (CheckCircleDot(x1, y1, r, x2, y2 + (h * 0.25)) &&	//左下のちょい上
		CheckCircleDot(x1, y1, r, x2, y2 + (h * 0.75)))		//左上のちょい下
	{
		return	true;
	};

	return	false;
}