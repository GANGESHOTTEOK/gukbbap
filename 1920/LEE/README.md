
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

int N, M;
vector <int> arr;
vector <int> target;

int binarySearch(int &target, int start, int end) {
    int mid = (start + end) / 2;
    if (end - start == 1) {
        if (target == arr[start] || target == arr[end]) return 1;
        return 0;
    }
    if (target > arr[mid]) return binarySearch(target, mid, end);
    else return binarySearch(target, start, mid);
}

void findTarget() {
    for (int i = 0; i < M; i++) cout << binarySearch(target[i], 0, N - 1) << "\n";
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
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    init();
    findTarget();
    return 0;
}



```
잊지 말자. 이렇게 입력이 많은 경우에는 절대 endl 쓰면 안된다...




