#include <iostream>

using namespace std;

int greatestCommonDivisor(int m, int n) {
    if (n > m) swap(m,n);
    if (n == 0) return m;

    return greatestCommonDivisor(m % n, n);
}

void greatestCommonDivisorTester() {
    cout << greatestCommonDivisor(18, 45);
}
