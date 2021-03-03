#include <iostream>

using namespace std;

typedef long long LL;

LL n, k;
LL divisor = 1000000007;

LL square(LL num, LL i) {
    if (i == 1) return num % divisor;
    
    if (i % 2 != 0) return (square(num, i - 1) * num) % divisor;
    LL temp = square(num, i / 2) % divisor;
    return (temp * temp) % divisor;
}

LL factorial(LL num) {
    LL ans = 1;
    for (int i = 2; i <= num; i++) { ans *= i; ans %= divisor; }
    return ans;
}

int main(void) {
    cin >> n >> k;
    LL a = factorial(n) % divisor;
    LL b = (factorial(k) * factorial(n - k)) % divisor;
    LL ans = (a * (square(b, divisor - 2))) % divisor;
    cout << ans << endl;
    return 0;
}

