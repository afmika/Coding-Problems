#include <iostream>
#include <vector>
#include <cassert>

#define EPS 0.00001

float my_pow (float x, int n) {
    float r = 1;
    while (n--) r *= x;
    return r;
}

// idea
// f(x) = val - x^n = 0 <=> x = nth_root(val)
inline float f (float x, float val, int n) { return val - my_pow (x, n); }
inline float v_abs (float x) { return x < 0 ? -x : x; }
inline float equal (float x, float y) { return v_abs (x - y) <= EPS; }

float nth_root (float val, int n) {
    float a = 0, b = 0;

    if (n % 2 == 0) {
        assert (val >= 0);
        b = val;
    }
    if (n % 2 != 0) {
        if (val < 0) a = val; // ]x, 0]
        else b = val; // [0, x[
    }

    float ans = 0;

    while (a <= b && !equal(a, b)) {
        float m = (a + b) / 2;
        if (f(a, val, n) * f(m, val, n) <= 0)
            b = m;
        else
            a = m;
        ans = m;
    }

    return ans;
}

int main () {
    std::vector<std::pair<float, float>> list {
        {-8, 3},
        {-8192, 13},
        {15487.65, 7}
    };

    for (auto& [first, second] : list) {
        float ans = nth_root (first, second);
        float retrieve = my_pow (ans, second);
        float error = v_abs (first - retrieve);
        printf ("nth_(%f, %f) = %f | retrieved %f | error ~%f\n",
            first, second,ans, retrieve, error);
    }
}