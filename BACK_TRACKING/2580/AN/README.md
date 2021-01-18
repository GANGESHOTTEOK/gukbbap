
# 백준 2580번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 1월 14일

---

### 접근 방식
- dfs탐색을 사용하여 구하였다.

### 소스코드
- 메모리 : KB
- 시간 : ms
```c++
#include <bits/stdc++.h>
using namespace std;
int N, cnt;
int board[15][15]={0,};
int dir[8][2] = {{1,1}, {1,0}, {1,-1}, {0,-1}, {0,1}, {-1,1}, {-1,0}, {-1,-1}};
stack< pair<int,int> > s;
void queen(int r, int c) {
    board[r][c] += 1;
    for(int i=1; i<N; i++) {
        for(int j=0; j<8; j++) {
            int row = r+dir[j][0]*i;
            int col = c+dir[j][1]*i;
            if(row>=0 && row<N && col>=0 && col<N) board[row][col] += 1;
        }
    }
}
void unQueen(int r, int c) {
    board[r][c] -= 1;
    for(int i=1; i<N; i++) {
        for(int j=0; j<8; j++) {
            int row = r+dir[j][0]*i;
            int col = c+dir[j][1]*i;
            if(row>=0 && row<N && col>=0 && col<N) board[row][col] -= 1;
        }
    }
}
void dfs(int depth) {
    if(depth==N) cnt++;
    else {
        pair<int, int> x = s.top();
        for(int i=x.first; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(board[i][j]!=0) continue;
                queen(i,j);
                s.push(make_pair(i,j));
                dfs(depth+1);
                s.pop();
                unQueen(i,j);
            }
        }
    }
}
int main() {
    cin >> N;
    for(int i=0; i<N; i++) {
        for(int j=i; j<N; j++) {
            s.push(make_pair(i,j));
            queen(i,j);
            dfs(1);
            s.pop();
            unQueen(i,j);
        }
    }
    cout << cnt;
} 
```