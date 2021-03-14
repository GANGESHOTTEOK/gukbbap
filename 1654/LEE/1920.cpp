#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long int LL;

LL answer = 0;
int N, K;
vector <LL> cable;

int getCableSum(LL length) {
    int answer = 0;
    for (LL c: cable) answer += c / length;
    return answer;
}

void binarySearch(LL minLen,LL maxLen) {
    LL midLen = (minLen + maxLen) / 2;
    if (minLen > maxLen) return ;
    if (getCableSum(midLen) < K) {
        binarySearch(minLen, midLen - 1);
    }
    else {
        answer = midLen > answer ? midLen : answer;
        binarySearch(midLen + 1, maxLen);
    }
}

int main(void) {
    cin >> N >> K;
    cable = vector <LL>(N);
    for (int i = 0; i < N; i++) cin >> cable[i];
    sort(cable.begin(), cable.end());
    binarySearch(1, cable[N - 1]);
    cout << answer << endl;
    return 0;
}
