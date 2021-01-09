
# 백준 10989번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 1월 5일 13시 27분

---

### 접근 방식
- N의 최댓값이 10,000,000이기 때문에 모든 수를 저장하면 메모리 초과가 날 수 밖에 없다.
- 입력되는 정수의 범위가 1~10,000이기 때문에 크기가 10,001인 배열을 선언한다.
- 배열의 인덱스가 입력받는 정수를, 배열의 원소가 해당 인덱스의 개수를 의미한다.

### 소스코드
- 메모리 : 2016KB
- 시간 : 1576ms
```c++
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a[10001]={0,};
    int N;

    cin >> N;
    for(int i=0; i<N; i++) {
        int temp;
        cin >> temp;
        a[temp]++;
    }

    for(int i=0; i<10001; i++) {
        for(int j=0; j<a[i]; j++) {
            cout << i << "\n";
        }
    }
}
```
- cin, cout은 scanf,printf에 비해 속도가 느리다. 이번 문제처럼 입출력할 데이터가 많아지면 입출력 속도가 꽤 중요해진다. 따라서 `ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);`을 삽입하여 입출력 속도를 향상시켜주었다.