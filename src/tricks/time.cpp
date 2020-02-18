#include "base.hpp"
#include <chrono>

auto start = chrono::system_clock::now();

double from_start() {
	auto now = chrono::system_clock::now();
	auto diff = std::chrono::duration_cast<std::chrono::microseconds>(now - start).count();
	return (double)diff / (1000 * 1000);
}

int main(void) {
	int it = 0;
	while (from_start() < 1 - 0.01) {
		it++;
		ll mod = 0;
		for (int i = 0; i < 1000; i++)
			mod = (mod * 2423523578 + 23123);
	}

	printf("%d\n", it);
}
