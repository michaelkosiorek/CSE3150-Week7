#include <iostream>
#include <vector>
#include <cmath>
#include <functional>

using namespace std;

template <class T>
bool is_perfect(const T& number, function<bool(int, int)> divides);