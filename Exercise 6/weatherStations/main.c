#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>
#include "list.h"


int main() {
	FILE *report;
	report = fopen("weather.txt", "r");

	int timestamp;
	int station_count;
	int stat;

	int count[4] = { 0, 0, 0, 0 };
	double* temp[4];
	double* relh[4];

	while (!feof(report)) {
		fscanf(report, "%*i %i\n", &station_count);
		for (int idx = 0; idx < station_count; ++idx) {
			fscanf(report, "%i %*lf %*lf\n", &stat);
			count[stat-1] += 1;
		}
	}

	for (int i = 0; i < 4; ++i) {
		temp[i] = (double*)malloc(count[i] * sizeof(double));
		relh[i] = (double*)malloc(count[i] * sizeof(double));
	}

	rewind(report);
	int pos[4] = { 0, 0, 0, 0 };

	double _temp;
	double _relh;

	while (!feof(report)) {
		fscanf(report, "%i %i\n", &timestamp, &station_count);
		for (int idx = 0; idx < station_count; ++idx) {
			fscanf(report, "%i %lf %lf\n", &stat, &_temp, &_relh);
			temp[stat - 1][pos[stat - 1]] = _temp;
			relh[stat - 1][pos[stat - 1]] = _relh;
			pos[stat-1] += 1;
		}
	}


	double mean_temp[4] = { 0., 0., 0., 0. };
	double mean_relh[4] = { 0., 0., 0., 0. };
	double stdd_temp[4] = { 0., 0., 0., 0. };
	double stdd_relh[4] = { 0., 0., 0., 0. };
	for (int i = 0; i < 4; ++i) {
		double sum_temp = 0.;
		double sum_relh = 0.;
		for (int p = 0; p < count[i]; ++p) {
			sum_temp += temp[i][p];
			sum_relh += relh[i][p];
		}
		mean_temp[i] = sum_temp / count[i];
		mean_relh[i] = sum_relh / count[i];

		double sqsum_temp = 0.;
		double sqsum_relh = 0.;
		for (int p = 0; p < count[i]; ++p) {
			sqsum_temp += pow((temp[i][p] - mean_temp[i]), 2);
			sqsum_relh += pow((relh[i][p] - mean_relh[i]), 2);
		}
		stdd_temp[i] = sqrt(sqsum_temp / (count[i] - 1));
		stdd_relh[i] = sqrt(sqsum_relh / (count[i] - 1));
	}

	char* name[4] = { "Bern", "Zurich", "Geneva", "Basel" };
	for (int i = 0; i < 4; ++i) {
		printf("%s:\n  temp: mean %5.2f(%.2f)\n  relh: mean %5.2f(%.2f)\n", name[i], mean_temp[i], stdd_temp[i], mean_relh[i], stdd_relh[i]);
	}


	return 0;
}