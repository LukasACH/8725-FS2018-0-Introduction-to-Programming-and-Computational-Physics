#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define ESC "\x1B%s"

int main() {
	printf(ESC, "(0");
	printf("\x7B\x6F");
	printf(ESC, "(B");
	printf("\x7B\x6F");
	return 0;
}