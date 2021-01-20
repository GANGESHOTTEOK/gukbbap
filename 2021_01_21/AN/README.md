
# 백준 9461번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 1월 20일 17시 55분

---

### 접근 방식
- 점화식은 다음과 같다.
> n | f(n)
> --- | ---
> 1,2,3 | 1
> n>3 | f(n-3) + f(n-2)
### 소스코드
- 메모리 : 2016KB
- 시간 : 0ms
```c++
#include <bits/stdc++.h>

using namespace std;

long long m[101] = {0,1,1,1,};

long long fx(int n) {
    if(m[n]) return m[n];
    return m[n] = fx(n-3) + fx(n-2);
}

int main() {
    int T;
    cin >> T;
    int N[T];

    for(int i=0; i<T; i++) cin >> N[i];
    for(int i=0; i<T; i++) cout << fx(N[i]) << "\n";

    return 0;
}

```