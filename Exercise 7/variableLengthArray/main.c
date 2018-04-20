#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <float.h>
#include <math.h>
#include <ctype.h>

#include "list.h"
#include "arropsd.h"


bool checkIfDouble(char *buffer, double *value);


int main() {
	list_double list = { malloc(sizeof(double)), 1, 0 };
	char buffer[50];
	double input;
	while (true)
	{
		fgets(buffer, 50, stdin);
		if ('\n' == (char)*buffer) {
			break;
		}
		if (checkIfDouble(buffer, &input)) {
			ladd(&list, input);
		}
	}
	printf("I got an array with %i values.\n", list.data_len);
	printf("- Minimum: %lf\n", lmind(list.data, list.data_len));
	printf("- Maximum: %lf\n", lmaxd(list.data, list.data_len));
	printf("- Summe:   %lf\n", lsumd(list.data, list.data_len));
	printf("- Mittelw: %lf\n", lmeand(list.data, list.data_len));
	printf("- Varianz: %lf\n", lvard(list.data, list.data_len));
	printf("- Stddev:  %lf\n", sqrt(lvard(list.data, list.data_len)));
	return 0;
}

bool checkIfDouble(char *buffer, double *value) {
	char c;
	for (int i = 0; i < 50; ++i) {
		c = (char)*(buffer + i);
		if (isdigit(c) || c == '.' || c == '-') {
			continue;
		}
		if (c == '\n') {
			char* endPtr;
			*value = strtod(buffer, &endPtr);
			break;
		}
		return false;
	}
	return true;
}
