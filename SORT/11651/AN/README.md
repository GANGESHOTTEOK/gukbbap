
# 백준 11651번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 1월 9일 12시 25분

---

### 접근 방식
- `N`개의 좌표를 `pair<int,int>`로 `vector`에 저장하였다.
- `sort`함수를 사용하여 정렬했다. 

### 소스코드
- 메모리 : 3564KB
- 시간 : 120ms
```c++
#include <bits/stdc++.h>

using namespace std;

int cmp(pair<int,int> &a, pair<int,int> &b) {
    if(a.second==b.second) return a.first < b.first;
    return a.second < b.second;
}

int main() {
    int N;
    cin >> N;
    vector< pair<int ,int> > v;
    for(int i=0; i<N; i++) {
        int x,y;
        cin >> x >> y;
        v.push_back(make_pair(x,y));
    }

    sort(v.begin(), v.end(), cmp);
    
    for(auto k:v) cout << k.first << " " << k.second << "\n";
}
```