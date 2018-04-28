#pragma once

typedef struct {
	double x;
	double y;
	double z;
} Vector3D;

/* Dot product of two vectors. */
double dot(Vector3D v1, Vector3D v2) {
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

/* Cross product of two vectors. */
Vector3D cross(Vector3D v1, Vector3D v2) {
	return (Vector3D) { v1.y * v2.z - v1.z * v2.y, v1.z*v2.x - v1.x*v2.z, v1.x*v2.y - v1.y*v2.x };
}