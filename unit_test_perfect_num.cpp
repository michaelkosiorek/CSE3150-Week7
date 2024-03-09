#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "perfect.h"

TEST_CASE("perfect numbers") {

    SUBCASE("testing to see if function can find first 4") {
        const double epsilon = .01;
        vector<int> perfect_nums;
        vector<int> perfect_nums_true = {6, 28, 496, 8128};

        for (int i=1; i < 10000; i++) {
            bool is_perfect_num = is_perfect(i, ([=](int a, int b) -> bool {
                double remainder = fmod(a, b);
                return (fabs(remainder) < epsilon);
            }));
            if (is_perfect_num) perfect_nums.push_back(i);
        }
        for (int i=0; i < 4; i++) CHECK_EQ(perfect_nums[i], perfect_nums_true[i]);
    
    };

    SUBCASE("testing on very large, imperfect number") {
        const double epsilon = .01;
        int number = 10'000'000;

        bool is_perfect_num = is_perfect(number, ([=](int a, int b) -> bool {
            double remainder = fmod(a, b);
            return (fabs(remainder) < epsilon);
        }));
        CHECK_FALSE(is_perfect_num);
    };

    SUBCASE("testing on very large, imperfect number") {
        const double epsilon = .01;
        int number = 10'000'000;

        bool is_perfect_num = is_perfect(number, ([=](int a, int b) -> bool {
            double remainder = fmod(a, b);
            return (fabs(remainder) < epsilon);
        }));
        CHECK_FALSE(is_perfect_num);
    };
};









template <class T>
bool is_perfect(const T& number, function<bool(int, int)> divides) {
    vector<T> vect_repeats(number-1, number);
    vector<T> divisors;

    int divisor=0;
    for (T val : vect_repeats) {
        if (divides(val, divisor)) divisors.push_back(divisor);
        divisor++;
    }

    T sum=0;
    for (T val : divisors) sum += val;

    if (sum==number) return true;
    else return false;
}