
# 백준 2630번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 02월 18일 23시 30분

---
### 메모리 및 시간

- 메모리 : 2148KB
- 시간 : 0ms

---

### 접근 방식
```cpp
#include <iostream>
#include <vector>

using namespace std;

int n, t;
int paperCount[2] = {0, 0};
bool ** paper;

void init() {
    paper = new bool *[n];
    for (int i = 0; i < n; i++) {
        paper[i] = new bool[n];
        for (int j = 0; j < n; j++) {
            cin >> t; paper[i][j] = t;
        }
    }
}

bool checkSameColor(int len, int x, int y) {
    bool check = paper[x][y];
    for (int i = x; i < x + len; i++) {
        for (int j = y; j < y + len; j++) {
            if (check != paper[i][j]) return false;
        }
    }
    return true;
}

void countPaper(int len, int x, int y) {
    for (int i = x; i < x + len; i += len / 2) {
        for (int j = y; j < y + len; j += len / 2) {
            if (checkSameColor(len / 2, i, j)) paperCount[paper[i][j]] += 1;
            else {
                countPaper(len / 2, i, j);
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    init();
    countPaper(n, 0, 0);
    cout << paperCount[0] << "\n" << paperCount[1] << endl;
    return 0;
}



```





