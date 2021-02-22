#include <iostream>

using namespace std;

int divideAndConquer(int a, int b, int c) {
    if (b == 1) return a % c;
    else {
        long int temp = divideAndConquer(a, b / 2, c);
        if (b % 2 != 0) return ((temp * temp) % c * a) % c;
        return (temp * temp) % c;
    }
}

int main(void) {
    int a, b, c;
    cin >> a >> b >> c;
    cout << divideAndConquer(a, b, c);
    return 0;
}
