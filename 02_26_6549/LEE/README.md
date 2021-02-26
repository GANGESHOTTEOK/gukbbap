
# 백준 6549번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 02월 26일 23시 35분

---
### 메모리 및 시간

- 메모리 : 4504KB
- 시간 : 52ms

---

### 접근 방식
https://kunkunwoo.tistory.com/71
```cpp
#include <iostream>
#include <algorithm>

typedef long long int LL;
using namespace std;

LL n = 1;
LL * rectangle;
LL maxRectangle = 0;

LL getMaxRectangle(LL left, LL right) {
    if (left == right) return rectangle[left];

    LL mid = (left + right) / 2;
    LL ret = max(getMaxRectangle(left, mid), getMaxRectangle(mid + 1, right));
    LL lo = mid, hi = mid + 1;
    LL height = min(rectangle[lo], rectangle[hi]);
    ret = max(ret, height * 2);

    while (left < lo || hi < right) {
        if (hi < right && (lo <= left || rectangle[lo - 1] < rectangle[hi + 1])) {
            hi++;
            height = min(height, rectangle[hi]);
        }
        else {
            lo--;
            height = min(height, rectangle[lo]);
        }
        ret = max(ret, height * (hi - lo + 1));
    }
    return ret;
}


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    while (n) {
        rectangle = new LL[n];
        for (LL i = 0; i < n; i++) cin >> rectangle[i];
        cout << getMaxRectangle(0, n - 1) << endl;
        cin >> n;
    }
    return 0;
}




```





