#include <malloc.h>
#include <stdio.h>

void overwrite() {
	int *a = (int *) malloc(10 * sizeof(int));
	for (int i = 0; i <= 10; i++)
		a[i] = i;
	free(a);
}

void nofree() {
	malloc(10);
}

int main(void) {
	overwrite();
	nofree();
}
