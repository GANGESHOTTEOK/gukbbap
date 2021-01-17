
# 백준 9663번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 01월 13일 20시 17분

---
### 메모리 및 시간

- 메모리 : 2016KB
- 시간 : 3456ms

---

### 접근 방식
```cpp
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool checkQueen(vector <int> &queen) {
    int comp = (int) queen.size() - 1;
    for (int i = 0; i < queen.size() - 1; i++) {
        if (abs(queen[i] - queen[comp]) == abs(i - comp)) return false;
    }
    return true;
}

int countCase(vector <bool> &visited, vector <int> &queen) {
    int ret = 0; int n = (int) visited.size();
    if (queen.size() == n) {
        return 1;
    }
    for (int i = 0; i < n; i++){
        if (!visited[i]) {
            visited[i] = true;
            queen.push_back(i);
            if (checkQueen(queen)) {
                ret += countCase(visited, queen);
            }
            visited[i] = false;
            queen.pop_back();
        }
    }
    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n; cin >> n;
    vector <bool> visited(n, false);
    vector <int> queen;
    cout << countCase(visited, queen) << endl;
    return 0;
}





```
대각선만 확인하게끔 코드를 작성해서 시간 복잡도를 줄임.




