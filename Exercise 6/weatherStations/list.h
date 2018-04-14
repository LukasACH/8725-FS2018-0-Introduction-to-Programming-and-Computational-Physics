#pragma once
#include <stdlib.h>

typedef struct {
	double *data;
	int alloc_len;
	int data_len;
} list_double;


void ladd(list_double *list, double element) {
	if (list->alloc_len <= list->data_len) {
		int new_len = 2 * (list->alloc_len);
		list->data = (double*)realloc(list->data, new_len * sizeof(double));
		if (list->data == NULL) {
			int e = 0;
		}
		list->alloc_len = new_len;
	}
	list->data[(list->data_len)++] = element;
}