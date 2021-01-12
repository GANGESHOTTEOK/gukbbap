
# 백준 15652번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 1월 12일 12시 56분

---

### 접근 방식
- 중복 조합 구하기
- dfs탐색을 사용하여 구하였다.

### 소스코드
- 메모리 : 2020KB
- 시간 : 8ms
```c++
#include <bits/stdc++.h>

using namespace std;

int N,M;
stack<int> s;

void printStack(stack<int> sck) {
    vector<int> v;
    while(!sck.empty()) {
        v.push_back(sck.top());
        sck.pop();
    }
    for(int i=M-1; i>=0; i--) cout << v[i] << " ";
    cout << "\n";
}

void dfs(int depth) {
    if(depth==M) printStack(s);
    else {
        int x = s.top();
        for(int i=x; i<=N; i++) {   // 중복체크없이 자기자신부터 탐색
            s.push(i);
            dfs(depth+1);
            s.pop();
        }
    }
}

int main() {
    cin >> N >> M;
    for(int i=1; i<=N; i++) {
        s.push(i);
        dfs(1);
    }
}
```