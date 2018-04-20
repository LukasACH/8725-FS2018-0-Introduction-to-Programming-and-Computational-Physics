#include <float.h>
#include <math.h>

double lmind(double *list, int length) {
	double lowest = DBL_MAX;
	for (int i = 0; i < length; ++i) {
		if (list[i] < lowest) {
			lowest = list[i];
		}
	}
	return lowest;
}

double lmaxd(double *list, int length) {
	double highest = -DBL_MAX;
	for (int i = 0; i < length; ++i) {
		if (list[i] > highest) {
			highest = list[i];
		}
	}
	return highest;
}

double lsumd(double *list, int length) {
	double sum = 0.;
	for (int i = 0; i < length; ++i) {
		sum += list[i];
	}
	return sum;
}

double lmeand(double *list, int length) {
	return lsumd(list, length) / length;
}

double lvard(double *list, int length) {
	double sqsum = 0.;
	double mean = lmeand(list, length);
	for (int i = 0; i < length; ++i) {
		sqsum += pow(list[i] - mean, 2);
	}
	return sqsum / (length - 1);
}