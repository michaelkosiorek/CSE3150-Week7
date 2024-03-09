#include "perfect.h"


template <class T>
bool is_perfect(const T& number, function<bool(int, int)> divides) {
    vector<T> vect_repeats(number-1, number);
    vector<T> divisors;

    int divisor=0;
    for (T val : vect_repeats) {
        if (divides(val, divisor)) divisors.push_back(divisor++);
    }

    T sum=0;
    for (T val : divisors) sum += val;

    if (sum==number) return true;
    else return false;
}