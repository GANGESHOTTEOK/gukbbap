
# 백준 1904번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 1월 20일 17시 20분

---

### 접근 방식
- 점화식을 찾기위해 N이 0일때부터 8까지의 결과값을 구했더니, 0, 1, 2, 3, 5, 8, 13, 21, 34가 나왔다.

### 소스코드
- 메모리 : 	40956KB
- 시간 : 40ms
```c++
#include <iostream>

using namespace std;

long long reg[1000001];

long long fx(int n) {
    if(n==0) return 0;
    if(n==1) return 1;
    if(n==2) return 2;
    if(reg[n]) return reg[n]%15746;
    return (reg[n] = fx(n-1) + fx(n-2))%15746;
};

int main() {
    cin.tie(NULL);
	ios::sync_with_stdio(false);

    int N;
    cin >> N;
    cout << fx(N);

    return 0;
}
```