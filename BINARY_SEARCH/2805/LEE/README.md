
# 백준 2805번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 03월 22일 21시 54분

---
### 메모리 및 시간

- 메모리 : 5924KB
- 시간 : 168ms

---

### 접근 방식
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> tree;

int N, treeAmount;
int maxTreeHeight = 0;
int maxInput = 0;

bool checkTreeSum(int cutHeight) {
    long long int treeSum = 0;
    for (int treeHeight: tree) {
        if (treeHeight > cutHeight)
            treeSum += treeHeight - cutHeight;
    }
    return treeSum >= treeAmount;
}

void divideAndConquer(int start, int end) {
    if (start > end) return;
    int mid = (start + end) / 2;
    if (checkTreeSum(mid)) {
        maxTreeHeight = mid > maxTreeHeight ? mid : maxTreeHeight;
        divideAndConquer(mid + 1, end);
    }
    else divideAndConquer(start, mid - 1);
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> N >> treeAmount;
    tree = vector <int>(N);
    for (int i = 0; i < N; i++) {
        cin >> tree[i];
        maxInput = tree[i] > maxInput ? tree[i] : maxInput;
    }
    
    if (checkTreeSum(maxInput)) {
        cout << maxInput << "\n";
        return 0;
    }
    
    divideAndConquer(0, maxInput);
    cout << maxTreeHeight << "\n";
    return 0;
}


```




