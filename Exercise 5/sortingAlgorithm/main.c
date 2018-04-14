#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>
#include "utils.h"


void bubbleSort(int *list, int length);
void insertionSort(int *list, int length);
void mergeSort(int *list, int length);
void bogoSort(int *list, int length);
void shuffle(int *list, int length);


int main(const int argc, const char *argv) {
	int list[8] = { 8, 7, 6, 5, 4, 3, 2, 1 };
	int length = 8;
	bogoSort(&list, length);
	return 0;
}

// Bubble sort: yet to exist
void bubbleSort(int *list, int length) {

}

void mergeSort(int *list, int length) {
	int idmin;
	for (int idx = 0; idx < length - 1; ++idx) {
		idmin = idx;
		for (int idy = idx + 1; idy < length; ++idy) {
			if (list[idmin] > list[idy]) {
				idmin = idy;
			}
		}
		swap((list + idmin), (list + idx));
	}
}

// Insertion sort:
//		This sort works by swapping
//		Time complexity: O(n!)
void insertionSort(int *list, int length) {
	for (int idx = 0; idx < length - 1; ++idx) {
		for (int idy = idx; idy >= 0; --idy) {
			if (list[idy] > list[idx + 1]) {
				swap((list + idy), (list + idx + 1));
			}
			else {
				break;
			}
		}
	}
}

// Bogo sort:
//		This might be one of the dumbest sorting algorithms.
//		The list is shuffled until it happens to be sorted.
void bogoSort(int *list, int length) {
	int t = __TIMESTAMP__;
	srand(t);
	bool sorted = false;
	do {
		shuffle(list, length);
		sorted = true;
		for (int idx = 0; idx < length - 1; ++idx) {
			if (list[idx] > list[idx + 1]) {
				sorted = false;
			}
		}
	} while (!sorted);
}


// Shuffle a list
// Please seed srand(_Seed) once before
void shuffle(int *list, int length) {
	for (int idx = 0; idx < length; ++idx) {
		swap((list + idx), (list + (unsigned)rand() % length));
	}
}