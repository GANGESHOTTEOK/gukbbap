#include <stdio.h>

// 2021.02.22 21:53

// 4^8 = 16^4 = 256^2 = ANS

int A, B, C, Ans = 0;

int Multiple(int Num, int Repeat) {
	if (Repeat == 0)
		return 1;
	
	long long int Temp = Multiple(Num, Repeat/2);
	long long int Ans = Temp * Temp % C; // square

	if (Repeat&1) // odd 
		Ans = Ans * Num % C;
	
	return Ans;
}

int main(void) {
	
	scanf("%d %d %d", &A, &B, &C);

	Ans = Multiple(A, B)%C;
	
	printf("%d\n", Ans);
	
	return 0;
}
