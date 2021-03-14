
# 백준 1654번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 3월 14일 21시 27분

---

### 접근 방식
- 

### 소스코드
- 메모리 : 2176KB
- 시간 : 4ms
```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int N,K;
    cin >> K >> N;
    vector<int> line(K);
    for(int i=0; i<K; i++) cin >> line[i];
    sort(line.begin(), line.end());
    int maxLine = 0;
    ll left = 1, right = line.back();
    while(left<=right) {
        ll mid = (left+right)/2;
        int cnt = 0;
        for(auto k:line) cnt += k/mid;
        if(cnt>=N) {
            maxLine = mid;
            left = mid+1;
        }
        else if(cnt<N) right = mid-1;
        else maxLine = mid;
    }
    cout << maxLine;
}
```