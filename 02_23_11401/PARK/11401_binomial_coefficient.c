#include <stdio.h>
#define Divisor 1000000007

// 2021.02.23 20:15

// (N,K) = nCk = nPk/n! = n!/k!(n-k)! = n!*(k!(n-k))^(-1)
// Fermat's little theorem : a^(p-1) = 1 (mod p) ... a = interger, p = prime number
// => a^(p-2) = a^(-1) (mod p)
// => n!*(k!(n-k))^(-1) % Divisor = n!*(k!(n-k))^(p-2) % Divisor

long long int Factorial[4000001] = {1,};

int Multiple(int Num, int Repeat) {
	if (Repeat == 0)
		return 1;
	
	long long int Temp = Multiple(Num, Repeat/2) % Divisor;
	long long int Ans = (Temp * Temp) % Divisor;

	if (Repeat&1)
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
