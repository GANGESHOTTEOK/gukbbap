
# 백준 1003번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 1월 18일 12시 55분

---

### 접근 방식
- 시간을 줄이기 위해 메모이제이션을 사용하였다. 계산된 `fibo(n)`의 값과 `zeroCnt`, `oneCnt`의 값은 저장해놓았다.

### 소스코드
- 메모리 : 2016KB
- 시간 : 0ms
```c++
#include <bits/stdc++.h>

using namespace std;

int zeroCnt, oneCnt;
vector< pair<int,int> > memoCnt(41);
vector<int> m(41);

int fibo(int n) {
    if(!n) {
        zeroCnt++;
        return 0;
    }
    else if(n==1) {
        oneCnt++;
        return 1;
    }
    else if(m[n]) {
        zeroCnt += memoCnt[n].first;
        oneCnt += memoCnt[n].second;
        return m[n];
    }
    else {
        m[n] = fibo(n-1) + fibo(n-2);
        memoCnt[n].first = zeroCnt;
        memoCnt[n].second = oneCnt;
        return m[n];
    }
}

int main() {
    int T, N;
    cin >> T;
    for(int i=0; i<T; i++) {
        cin >> N;
        zeroCnt = oneCnt = 0;
        fibo(N);
        cout << zeroCnt << " " << oneCnt << "\n";
    }
    return 0;
}
```