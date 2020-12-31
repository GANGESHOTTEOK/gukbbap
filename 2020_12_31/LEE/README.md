
# 백준 1018번 문제

---

### 문제 해결 날짜 및 시간

- 2020년 12월 31일 15시 37분

---

### 접근 방식
```c++
#include <iostream>
#include <string>
#include <vector>
#define MAX_BLOCK 250
using namespace std;

vector <string> generateBoard(int mode) {
    vector <string> temp(8);
    for (int i = 0; i < 8; i++) {
        string t;
        for (int j = 0; j < 8; j++) {
            if (mode) t.push_back('B');
            else t.push_back('W');
            mode = !mode;
        }
        temp[i] = t;
        mode = !mode;
    }
    return temp;
}

int compareBoard(vector <string> standard, vector <string> compare) {
    int diff = MAX_BLOCK;
    for (int i = 0; i < standard.size() - 7; i++) {
        for (int j = 0; j < standard[i].size() - 7; j++) {
            int tempDiff = 0;
            for (int x = 0; x < 8; x++) {
                for (int y = 0; y < 8; y++) {
                    tempDiff += (standard[i + x][j + y] != compare[x][y]);
                }
            }
            if (diff > tempDiff) diff = tempDiff;
        }
    }
    return diff;
}

int main(void) {
    int n, m, ans;
    cin >> n >> m;
    vector <string> chessBoard(n);
    for (int i = 0; i < n; i++) cin >> chessBoard[i];
    vector <string> blackFirst = generateBoard(1);
    vector <string> whiteFirst = generateBoard(0);
    int blackCount = compareBoard(chessBoard, blackFirst);
    int whiteCount = compareBoard(chessBoard, whiteFirst);
    
    ans = blackCount < whiteCount ? blackCount : whiteCount;
    cout << ans;
    return 0;
}

```
`string`과 `vector` 라이브러리를 사용하여 문제 해결.
어떻게 풀까 고민하다가 그냥 4중 반복문을 사용하기로 했다. 




