
# 백준 2156번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 01월 28일 20시 15분

---
### 메모리 및 시간

- 메모리 : 2176KB
- 시간 : 4ms

---

### 접근 방식
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int length;
vector <long long int> sum;
int max_value = 0;
vector <long long int> value;

int get_max_value(int i, int j) {
    return i > j ? i : j;
}

void calculate() {
    sum[0] = value[0];
    sum[1] = value[0] + value[1];
    sum[2] = get_max_value(value[0] + value[2], value[1] + value[2]);
    sum[2] = get_max_value(sum[2], value[0] + value[1]);
    
    for (int i = 3; i < length + 1; i++) {
        if (value[i] != 0) {
            sum[i] = get_max_value(sum[i - 3] + value[i - 1] + value[i],
                               sum[i - 2] + value[i]);    
            sum[i] = get_max_value(sum[i], sum[i - 1]);
        }
        else {
            sum[i] = sum[i - 1];    
        }
    }
    
    for (int i = 0; i < length + 3; i++) {
        if (max_value < sum[i]) max_value = sum[i];
    }
    cout << max_value;
}

int main(void) {
    cin >> length;
    value = vector <long long int>(length + 1, 0);
    for (int i = 0; i < length; i++) {
        cin >> value[i];
    }
    sum = vector <long long int>(length + 3, 0);
    calculate();
    return 0;
}
```




