g++ cpp11.cpp -Wall -Wextra -std=c++11 -o /dev/null
g++ cpp14.cpp -Wall -Wextra -std=c++14 -o /dev/null
g++ cpp17.cpp -Wall -Wextra -std=c++17 -o /dev/null
python testnumpy.py > /dev/null
time python testnumpy.py > /dev/null
python testnumsci.py > /dev/null
time python testnumsci.py > /dev/null
python --version
