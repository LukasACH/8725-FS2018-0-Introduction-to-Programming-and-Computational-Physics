#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h> 
#include "record.h"


int main() {
	FILE* rec;
	rec = fopen("records.txt", "r");

	size_t count = 0;
	while (!feof(rec)) {
		fscanf(rec, "%*i %*s %*s %*i %*s %*f %*f");
		++count;
	}

	rewind(rec);
	
	record* record_list = calloc(count, sizeof(record));

	printf("%s", "\x1B[38;2;100;255;255m");
	for (size_t i = 0; i < count; ++i) {
		fscanf(rec, "%u %s %s %u %s %f %f", &(record_list[i].date), &(record_list[i].firstname), &(record_list[i].lastname), &(record_list[i].year), &(record_list[i].nation), &(record_list[i].time), &(record_list[i].wind));
	}

	fclose(rec);

	for (size_t i = 0; i < count; ++i) {
		char buffer[67];
		sprintf(buffer, "%s %s (%u)", record_list[i].firstname, record_list[i].lastname, record_list[i].year);
		printf("%35s  from  %13s  ran in  %u  100m in %5.2fs with a windspeed of %3.1fm/s\n", buffer, record_list[i].nation, record_list[i].date, record_list[i].time, record_list[i].wind);
	}

	// Youngest record holder
	size_t idx_record = 0;
	unsigned int record = UINT_MAX;
	for (size_t i = 0; i < count; ++i) {
		if ((record_list[i].date - record_list[i].year) < record) {
			idx_record = i;
			record = (record_list[i].date - record_list[i].year);
		}
	}
	printf("\nYoungest worldrecord holder is %s %s from %s at an age of %u.\n\n", record_list[idx_record].firstname, record_list[idx_record].lastname, record_list[idx_record].nation, record);

	// Backwind calculations
	float* newtime = calloc(count, sizeof(float));
	for (size_t i = 0; i < count; ++i) {
		newtime[i] = 1000. * record_list[i].time / (1000. - record_list[i].time * record_list[i].wind);
	}
	for (size_t i = 0; i < count; ++i) {
		printf("%s %s (%u) ran a corrected time of %5.2f (p %5.2f)\n", record_list[i].firstname, record_list[i].lastname, record_list[i].year, newtime[i], record_list[i].time);
	}

	return 0;
}