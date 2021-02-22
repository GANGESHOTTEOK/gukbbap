
# 백준 1780번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 02월 20일 00시 00분

---
### 메모리 및 시간

- 메모리 : 20776KB
- 시간 : 364ms

---

### 접근 방식
```cpp
#include <iostream>
#include <vector>

using namespace std;

int n, t;
int paperCount[3] = {0, 0, 0};
int ** paper;

void init() {
    paper = new int *[n];
    for (int i = 0; i < n; i++) {
        paper[i] = new int[n];
        for (int j = 0; j < n; j++) {
            cin >> t; paper[i][j] = t;
        }
    }
}

bool checkSameColor(int len, int x, int y) {
    int check = paper[x][y];
    for (int i = x; i < x + len; i++) {
        for (int j = y; j < y + len; j++) {
            if (check != paper[i][j]) return false;
        }
    }
    return true;
}

void countPaper(int len, int x, int y) {
    if (checkSameColor(len, x, y)) {
        paperCount[paper[x][y] + 1] += 1;
        return ;
    }
    for (int i = x; i < x + len; i += len / 3) {
        for (int j = y; j < y + len; j += len / 3) {
            if (checkSameColor(len / 3, i, j)) paperCount[paper[i][j] + 1] += 1;
            else {
                countPaper(len / 3, i, j);
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    init();
    countPaper(n, 0, 0);
    cout << paperCount[0] << "\n" << paperCount[1] << "\n" << paperCount[2] << "\n";
    return 0;
}


```





