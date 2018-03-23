#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "utils.h"


void insertionSort(int *list, int length);


int main(const int argc, const char *argv) {
	int list[8] = { 3, 2, 4, 5, 8, 6, 7, 1 };
	int length = 8;
	insertionSort(&list, length);
	return 0;
}

void insertionSort(int *list, int length) {
	for (int idx = 0; idx < length - 1; ++idx) {
		for (int idy = idx; idy >= 0; --idy) {
			if (list[idy] > list[idy + 1]) {
				swap((list + idy), (list + idy + 1));
			}
			else
			{
				break;
			}
		}
	}
}
