#!/bin/sh

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
