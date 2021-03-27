
# 백준 2110번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 03월 22일 21시 54분

---
### 메모리 및 시간

- 메모리 : 2408KB
- 시간 : 16ms

---

### 접근 방식
```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int N, M;
vector <int> house;

int countRouter(int interval) {
    int numOfRouter = 1;
    int distance = 0;
    int standard = house[0];
    for (int i = 1; i < N; i++) {
        distance = house[i] - standard;
        if (distance >= interval) {
            numOfRouter++;
            standard = house[i];
        }
    }
    return numOfRouter;
}

int binarySearch() {
    int left = 1;
    int right = house[N - 1] - house[0];
    int ans = 0;
    
    while(left <= right) {
        int interval = (right + left) / 2;
        int numOfRouter = countRouter(interval);
        if (numOfRouter >= M) {
            ans = max(ans, interval);
            left = interval + 1;
        }
        else right = interval - 1;
    }
    return ans;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    house = vector<int>(N);
    for (int i = 0; i < N; i++) cin >> house[i];
    sort(house.begin(), house.end());
    
    if (M == 2) {
        cout << house[N - 1] - house[0] << "\n";
        return 0;
    }
    cout << binarySearch() << endl;
    return 0;
}


```




