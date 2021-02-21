
# 백준 1629번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 2월 22일 2시 27분

---

### 접근 방식
- [modulo 연산이 곱셈에서 분배법칙](https://sexycoder.tistory.com/66)이 성립한다는 점과 지수법칙을 이용한다.
<img src="https://t1.daumcdn.net/cfile/tistory/99DD8A335A66C98426" alt="image">


### 소스코드
- 메모리 : 2016KB
- 시간 : 0ms
```c++
#include <bits/stdc++.h>
using namespace std;
long long A,B,C;
long long fx(long long x, long long y) {
    if(!y) return 1;
    long long num = fx(x,y/2)%C;
    num = (num*num)%C;
    if(y%2) return (num*x)%C;
    else return num%C;
}
int main() {
    cin >> A >> B >> C;
    cout << fx(A%C, B);
}
```