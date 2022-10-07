#include "Vector3.h"
#include <cmath>


const Vector3 lerp(const Vector3& start, const Vector3& end, const float t)
{
	return start * (1.0f - t) + end * t;
}