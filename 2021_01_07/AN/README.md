
# 백준 1427번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 1월 7일 9시 6분

---

### 접근 방식
- `string`으로 입력받아 `sort`함수를 사용하여 내림차순으로 정렬하였다.

### 소스코드
- 메모리 : 2020KB
- 시간 : 0ms
```c++
#include <bits/stdc++.h>

using namespace std;

int cmp(int a, int b) {
    return a>b;
}

int main() {
    string s;
    cin >> s;
    sort(s.begin(), s.end(), cmp);
    cout << s;
}
```