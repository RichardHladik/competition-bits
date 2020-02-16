#include <stdio.h>
#include <algorithm>
#include <vector>

int main(void) {
	std::vector<int> v(10000000);
	int sum = 0;
	for (int i = 0; i < (int)v.size(); i++)
		v[i] = sum = sum * 23 + 15412345;
	sort(v.begin(), v.end());
}
