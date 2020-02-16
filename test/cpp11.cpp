#include <stdio.h>
#include <vector>
#include <iostream>

int main(void) {
	std::vector<int> a = {1, 2, 3};
	for (auto b : a)
		std::cout << b;
}
