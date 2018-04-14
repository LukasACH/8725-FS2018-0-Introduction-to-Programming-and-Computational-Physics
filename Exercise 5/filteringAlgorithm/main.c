#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *input_file, *output_file;
	fopen_s(input_file, "data.txt", "r");
	fopen_s(output_file, "filterdata.txt", "w");

	float A, B, C;

	while (!feof(input_file)) {
		fscanf_s(input_file, "%f %f %f", &A, &B, &C);
		if (A*A + B * B >= 30 * 30) {
			fprintf_s(output_file, "%f %f %f", &A, &B, &C);
		}
	}
}