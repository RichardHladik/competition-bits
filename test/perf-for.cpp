#include <stdio.h>

int main(void) {
	int sum = 0;
	for (int i = 0; i < 500000000; i++)
		sum = sum * 23 + 15412345;
	printf("%d\n", sum);
}
