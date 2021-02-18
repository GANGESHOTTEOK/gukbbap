
# 백준 2630번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 2월 18일 22시 6분

---

### 접근 방식
- 

### 소스코드
- 메모리 : 2080KB
- 시간 : 0ms
```c++
#include <bits/stdc++.h>
using namespace std;

int N, a[128][128], blue=0, white=0;
int idx[4][2] = {{0,0}, {0,1}, {1,0}, {1,1}};

int isPaper(int row, int col, int n) {
    int color = a[row][col];
    for(int i=0; i<n; i++) 
        for(int j=0; j<n; j++)  // a[row][col]과 다른 색이면 -1을 반환
            if(a[row+i][col+j] != color) return -1; 
    return color;
}

void cutPaper(int row, int col, int n) {
    if(!n) return;
    for(int i=0; i<4; i++) {
        int r = row + n/2*idx[i][0];
        int c = col + n/2*idx[i][1];
        
        int result = isPaper(r,c,n/2);

        if(result == -1) cutPaper(r,c,n/2);
        else if(!result) white++;
        else blue++;
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> N;
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) cin >> a[i][j];
    cutPaper(0,0,N);
    cout << white << "\n" << blue;
}
```
- `int isPaper(int row, int col, int n)` : `a[row][col]`에서 시작된 길이가 `n`인 정사각형이 종이인지 아닌지, 종이라면 어떤 색 종이인지 반환한다. 종이가 아니라면 `-1`, 흰색종이라면 `0`, 파란종이라면 `1`을 반환한다.
- `void cutPaper(int row, int col, int n)` : `a[row][col]`에서 시작된 길이가 `n`인 정사각형을 길이가 `n/2`인 네 조각의 정사각형으로 분리해 종이인지 아닌지 확인한다. 종이라면 해당 색의 카운트를 증가시키고, 아니면 재귀하여 다시 네 조각으로 분리한다.