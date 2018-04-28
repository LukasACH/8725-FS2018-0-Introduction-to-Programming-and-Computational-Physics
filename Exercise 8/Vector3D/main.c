#include <stdio.h>
#include "Vector3D.h"


int main() {
	Vector3D v1 = { 1., 1., 1. };
	Vector3D v2 = { 2., -1., 0. };

	double d = dot(v1, v2);
	Vector3D c = cross(v1, v2);
	return 0;
}