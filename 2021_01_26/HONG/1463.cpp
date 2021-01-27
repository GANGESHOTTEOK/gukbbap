#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    function<int (int)> dp = [&dp](int n) -> int{ return n < 2 ? 0 : min(dp(n/2) + n%2, dp(n/3) + n%3) + 1; };
    cout << dp(N);
    return 0;
}