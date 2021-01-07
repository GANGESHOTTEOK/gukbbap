
# 백준 1427번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 01월 07일 22시 11분

---
### 메모리 및 시간

- 메모리 : 2020KB
- 시간 : 0ms

---

### 접근 방식
```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define FOR(i, n) for (int i = 0; i < n; i++)
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    string str; cin >> str; int length = str.length();
    vector <char> alphaList(length);
    FOR(i, length) alphaList[i] = str[i];
    sort(alphaList.rbegin(), alphaList.rend());
    FOR(i, length) cout << alphaList[i];
    return 0;
}
```
입력값을 `string`으로 받은 다음, `vector`에 한 글자 씩 집어넣은 후 `vector::sort()`로 내림차순 정렬.




