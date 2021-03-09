
# 백준 1920번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 03월 09일 22시 37분

---
### 메모리 및 시간

- 메모리 : 2800KB
- 시간 : 56ms

---

### 접근 방식
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, ans;
vector <int> arr;
vector <int> target;

int binarySearchLower(int &target) {
    int start = 0;
    int end = N - 1;
    while (start < end) {
        int mid = (start + end) / 2;
        if (target <= arr[mid]) end = mid;
        else start = mid + 1;
    }
    return end;
}
int binarySearchHigher(int &target) {
    int start = 0;
    int end = N - 1;
    while (start < end) {
        int mid = (start + end) / 2;
        if (target < arr[mid]) end = mid;
        else start = mid + 1;
    }
    return end;
}

void countTarget() {
    for (int i = 0; i < M; i++) {
        int lower = binarySearchLower(target[i]);
        int higher = binarySearchHigher(target[i]);
        if (higher == N - 1 && arr[higher] == target[i]) higher++;
        cout << higher - lower << " ";
    }
}

void init() {
    cin >> N;
    arr = vector<int>(N);
    for (int i = 0; i < N; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    
    cin >> M;
    target = vector<int>(M);
    for (int i = 0; i < M; i++) cin >> target[i];
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    init();
    countTarget();
    return 0;
}




```
`lower bound`와 `higher bound`를 구하는 방법은 외우자...




