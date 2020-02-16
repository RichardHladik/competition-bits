#!/bin/sh

cd "$(dirname "$0")"
g++ cpp11.cpp -Wall -Wextra -std=c++11 -o /dev/null
g++ cpp14.cpp -Wall -Wextra -std=c++14 -o /dev/null
g++ cpp17.cpp -Wall -Wextra -std=c++17 -o /dev/null
python testnumpy.py > /dev/null
time python3 testnumpy.py > /dev/null
python3 testnumsci.py > /dev/null
time python3 testnumsci.py > /dev/null
python3 --version
g++ sanitizer-test.cpp -o bin/sanitizer-test && bin/sanitizer-test
g++ sanitizer-test.cpp -o bin/sanitizer-test -fsanitize=address -g && bin/sanitizer-test
g++ sanitizer-test.cpp -o bin/sanitizer-test -g && valgrind bin/sanitizer-test

for t in perf-for perf-sort; do
	g++ $t.cpp -o bin/$t -O2 && time bin/$t
done
