# 2021년 02월 23일 화요일
# 백준 11401번 이항 계수 3
### https://www.acmicpc.net/problem/11401

---
### 문제 해결 날짜 및 시간
- 2021.02.23 20:15

---

### 접근 방식
- (N,K) = nCk = nPk/n! = n!/k!(n-k)! = n!*(k!(n-k))^(-1)
- Fermat's little theorem : a^(p-1) = 1 (mod p) ... a = interger, p = prime number
- => a^(p-2) = a^(-1) (mod p)
- => n!*(k!(n-k))^(-1) % Divisor = n!*(k!(n-k))^(p-2) % Divisor
- 조합을 페르마의 소정리에 적용하기 위해 변형하여 적용
- 외에 제곱 부분은 곱셈과 

---

### 소스코드
- 메모리 : 32364KB
- 시간 : 40ms
```c
#include <stdio.h>
#define Divisor 1000000007

long long int Factorial[4000001] = {1,};

int Multiple(int Num, int Repeat) {
	if (Repeat == 0)
		return 1;
	
	long long int Temp = Multiple(Num, Repeat/2) % Divisor;
	long long int Ans = (Temp * Temp) % Divisor;

	if (Repeat&1) // if odd
		Ans = (Ans * Num) % Divisor;
	
	return Ans;
}

int main(void) {
	int N, K;
	long long int A, B, Ans = 0;
	
	scanf("%d %d", &N, &K);
	
	if (K > (N/2)) // nCk = nC(n-k)
		K = N-K;
	
	if (K == 0) { // exception nC0
		printf("1\n");
		return 0;
	}
	
	for (int i = 1; i < N; i++) { // make Factorial(Dynamic Programming)
		Factorial[i] = (Factorial[i-1]*(i+1)) % Divisor;
	}
	
	A = Factorial[N-1] % Divisor;
	B = (Factorial[K-1]*Factorial[N-K-1]) % Divisor;
	
	Ans = Multiple(B, Divisor-2) % Divisor; // pow
	
	printf("%lld\n", (A*Ans) % Divisor);
	
	return 0;
}
```
