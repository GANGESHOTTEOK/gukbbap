
# 백준 11651번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 01월 09일 23시 21분

---
### 메모리 및 시간

- 메모리 : 2800KB
- 시간 : 48ms

---

### 접근 방식
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i, n) for (int i = 0; i < n; i++)
using namespace std;
bool compare(pair<int, int> &v1, pair<int, int> &v2) {
    if (v1.second == v2.second) return v1.first < v2.first;
    return v1.second < v2.second;
}
int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int num; cin >> num;
    vector <pair <int, int>> numList(num);
    FOR(i, num) cin >> numList[i].first >> numList[i].second;
    sort(numList.begin(), numList.end(), compare);
    FOR(i, num) cout << numList[i].first << " " << numList[i].second << "\n";
    
    return 0;
}


```
`sort()`함수에서 사용자 설정 함수 `compare()`를 만들어서 정렬을 수행했다.
덕분에 좌표정렬하기 1과 거의 유사하게 코드를 짤 수 있었다.




