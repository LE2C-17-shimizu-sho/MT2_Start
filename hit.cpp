#include"hit.h"
//‹éŒ`
int	CheckHit(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2) {
	int cl1 = x1;
	int	cr1 = x1 + w1;
	int cl2 = x2;
	int	cr2 = x2 + w2;

	if (cr1 <= cl2)
	{
		return	0;
	}

	if (cr2 <= cl1)
	{
		return	0;
	}

	int	cu1 = y1;
	int	cd1 = y1 + h1;
	int	cu2 = y2;
	int	cd2 = y2 + h2;

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

//‰~
int	CheckHit(int x1, int y1, int r1, int x2, int y2, int r2) {
	int sum_x = (x1 - x2) * (x1 - x2);
	int	sum_y = (y1 - y2) * (y1 - y2);
	int sum_r = (r1 + r2) * (r1 + r2);


	if (sum_r > sum_y + sum_x)
	{
		return	1;
	}
	return	0;
}