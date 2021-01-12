
# 백준 15649번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 1월 11일 22시 36분

---

### 접근 방식
- dfs탐색을 사용하여 구하였다.

### 소스코드
- 메모리 : 2020KB
- 시간 : 40ms
```c++
#include <bits/stdc++.h>

using namespace std;

int N,M;
stack<int> s;
int chk[9]={0,};    // 방문한 정수인지 확인

void printStack(stack<int> sck) {   // stack 출력
    vector<int> v;
    while(!sck.empty()) {           // stack을 vector에 저장
        v.push_back(sck.top());
        sck.pop();
    }
    for(int i=M-1; i>=0; i--) cout << v[i] << " ";
    cout << "\n";
}

void dfs(int depth) {
    if(depth==M) printStack(s);
    else {
        for(int i=1; i<=N; i++) {
            if(chk[i]==1) continue;
            chk[i] = 1;
            s.push(i);
            dfs(depth+1);
            s.pop();
            chk[i] = 0;
        }
    }
}

int main() {
    cin >> N >> M;
    dfs(0);
}
```