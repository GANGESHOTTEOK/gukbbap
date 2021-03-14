
# 백준 1654번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 03월 14일 19시 03분

---
### 메모리 및 시간

- 메모리 : 2016KB
- 시간 : 12ms

---

### 접근 방식
```cpp
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


```




