#define NDEBUG

#include <cassert>

namespace MyGcdLcm {
    template <class T>
    T gcd(T a, T b) {
        T _temp;
        while (b != 0) {
            _temp = a;
            a     = b;
            b     = _temp % b;
        }
        return a;
    }

    template <class T>
    T lcm(T a, T b) {
        return a / gcd(a, b) * b;
    }
}  // namespace MyGcdLcm

int main() {
    MyGcdLcm::gcd(5, 3);
}