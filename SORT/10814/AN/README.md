
# 백준 10814번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 1월 11일 14시 5분

---

### 접근 방식
- `N`개의 좌표를 `pair<int,string>`로 `vector`에 저장하였다.
- `pair`의 `first`에는 나이를, `second`에는 이름을 저장한다.
- `stable_sort`함수를 사용하여 정렬했다.

### 소스코드
- 메모리 : 9848KB
- 시간 : 104ms
```c++
#include <bits/stdc++.h>

using namespace std;

int cmp(pair<int, string> a, pair<int, string> b) {
    return a.first<b.first;     // 나이만 비교
}

int main() {
    int N;
    cin >> N;
    vector< pair<int, string> > v(N);
    for(int i=0; i<N; i++) 
        cin >> v[i].first >> v[i].second;
    // stable_sort
    stable_sort(v.begin(), v.end(), cmp);

    for(auto k:v) cout << k.first << " " << k.second << "\n";
}
```
- 정렬의 안정성 : 원소의 값이 같을 때, 원래의 순서를 유지하는 정렬을 `stable`하다고 한다.
- STL에서 `sort`함수는 `unstable`하다. 따라서 이번 문제에서는 `stable_sort`함수를 이용하였다.