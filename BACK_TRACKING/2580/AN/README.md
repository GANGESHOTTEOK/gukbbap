
# 백준 2580번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 1월 17일 12시 44분

---

### 접근 방식
- dfs탐색을 사용하여 구하였다.
- 각 행과 열, 3x3에 있는 값들을 `unordered_set`에 저장하여 빈 칸에 들어갈 수 있는 값인지 확인했다.
- https://jeonggyun.tistory.com/225

### 소스코드
- 메모리 : 2020KB
- 시간 : 924ms
```c++
#include <bits/stdc++.h>

using namespace std;

int sudoku[9][9];
vector< unordered_set<int> > R(9), C(9), S(9);
vector< pair<int,int> > blank;
int N;

int isFit(int row, int col, int val) {
    if(C[col].find(val)!=C[col].end()) return 0;
    if(S[row/3*3+col/3].find(val)!=S[row/3*3+col/3].end()) return 0;
    return 1;
}

void dfs(int depth) {
    if(depth==N) {      // 스도쿠 출력 후 프로그램 종료
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) 
                cout << sudoku[i][j] << " ";
            cout << "\n";
        }
        exit(0);
    }

    int r = blank[depth].first;     // sudoku[r][c] 탐색
    int c = blank[depth].second;

    for(int i=1; i<=9; i++) {
        if(R[r].find(i) != R[r].end()) continue;    // i가 해당 행,열,3x3에 있으면 skip
        if(!isFit(r,c,i)) continue;                 

        sudoku[r][c] = i;
        R[r].insert(i);
        C[c].insert(i);
        S[r/3*3+c/3].insert(i);

        dfs(depth+1);

        R[r].erase(i);
        C[c].erase(i);
        S[r/3*3+c/3].erase(i);
    }
}

int main() {
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            int temp;
            cin >> temp;
            sudoku[i][j] = temp;
            if(!temp) blank.push_back(make_pair(i,j));  // temp가 0이면 blank에 해당 인덱스 저장
            else {                                      // 0이 아니면 set에 삽입
                R[i].insert(temp);
                C[j].insert(temp);
                S[i/3*3+j/3].insert(temp);
            }
        }
    }
    N = blank.size();
    dfs(0);
}
```
- `int isFit(int row, int col, int val)` : 인덱스 `(row, col)`에 `val`이 들어갈 수 있는 값인지를 반환해준다.
- `void dfs(int depth)` : `blank`의 `depth`번째 인덱스에 해당하는 탐색. 만약 `depth`가 `blank`의 개수와 같아지면 `sudoku`를 출력한 후 프로그램을 종료시킨다.
- `unordered_set`의 `insert()`, `find()`, `erase()`은 O(1)의 복잡도를 가진다.