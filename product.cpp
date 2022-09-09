#include"product.h"

void	OuterProduct(float&	x1, float&	x2, float&	y1, float&	y2, float	speed) {
	float range_x = x1 - x2;
	float range_y = y1 - y2;
	float angle = (float)atan2(range_y, range_x);
	float move_x = cos(angle) * speed;
	float move_y = sin(angle) * speed;
	x2 += move_x;
	y2 += move_y;
}

void	OuterProduct2(float& x1, float& x2, float& y1, float& y2, float	speed, float& posx, float& posy) {
	float range_x = x1 - x2;
	float range_y = y1 - y2;
	float angle = (float)atan2(range_y, range_x);
	float move_x = cos(angle) * speed;
	float move_y = sin(angle) * speed;
	posx += move_x;
	posy += move_y;
}

