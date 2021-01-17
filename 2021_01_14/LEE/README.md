
# 백준 2580번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 01월 14일 20시 s25분

---
### 메모리 및 시간

- 메모리 : 2016KB
- 시간 : 316ms

---

### 접근 방식
```cpp
#include <iostream>
#include <vector>
using namespace std;

vector <vector <int>> sudoku(9, vector <int>(9, 0));

bool checkSudoku(int num, int x, int y) {
    
    for (int i = 0; i < 9; i++) {
        if (i != x && sudoku[i][y] == num) return false;
    }
    for (int i = 0; i < 9; i++) {
        if (i != y && sudoku[x][i] == num) return false;
    }
    int n_x = x / 3 * 3;
    int n_y = y / 3 * 3;
    for (int i = n_x; i < n_x + 3; i++) {
        for (int j = n_y; j < n_y + 3; j++) {
            if (i != x && j != y && sudoku[i][j] == num) return false;
        }
    }
    return true;
}

void printSudoku() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << sudoku[i][j] << " ";
        }
        cout << "\n";
    }
}

void dfs(vector <int> &visited, vector <pair<int,int>> &zeroList, int cnt) {
    if (cnt == zeroList.size()) {
        printSudoku();
        exit(0);
    }
    for (int i = 0; i < 9; i++) {
        if (!visited[cnt]) {
            int x = zeroList[cnt].first; int y = zeroList[cnt].second;
            visited[cnt] = true; sudoku[x][y] = i + 1;
            if (checkSudoku(i + 1, x, y)) dfs(visited, zeroList, cnt + 1);
            visited[cnt] = false; sudoku[x][y] = 0;
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    vector <int> visited;
    vector <pair <int, int>> zeroList;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> sudoku[i][j];
            if (sudoku[i][j] == 0) {
                zeroList.push_back(make_pair(i, j));
                visited.push_back(false);
            }
        }
    }
    dfs(visited, zeroList, 0);
    return 0;
}

```
빈 공간에 숫자를 `1 - 9` 중 하나를 선택해서 채워 넣고,  
채운 칸이 포함 된 행, 열, `3 * 3` 박스를 확인한다.




