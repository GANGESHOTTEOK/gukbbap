#include <stdio.h>
#define Divisor 1000000007
#define N 2

// 2021.02.25 21:47

// fuction refactoring, use array pointer 

long long int B;
long long int Matrix[2][2] = {{1,1}, {1,0}}, Power[2][2] = {0,}, Temp[2][2] = {{1,1}, {1,0}};

int InitTemp(void) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			Temp[i][j] = Power[i][j];
		}
	}
	
	return 0;
}

int Multiplication(void) {
	long long int Trash = 0;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			Trash = 0;
			for (int l = 0; l < N; l++) // point!!
				Trash += (Temp[i][l]*Temp[l][j]) % Divisor;
			Power[i][j] = Trash % Divisor;
		}
	}
	return 0;
}

int Multiplication2(void) {
	long long int Trash = 0;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			Trash = 0;
			for (int l = 0; l < N; l++) // point!!
				Trash += (Temp[i][l]*Matrix[l][j]) % Divisor;
			Power[i][j] = Trash % Divisor;
		}
	}
	return 0;
}

int MatrixPower(long long int Repeat) {
	
	if (Repeat <= 1)
		return 1;
	
	MatrixPower(Repeat/2);

	Multiplication();
	InitTemp();
	
	if (Repeat&1) {
		Multiplication2();
		InitTemp();
	}
	
	return 0;
}

int main(void) {

	scanf("%lld", &B);
	
	if (B <= 2) {
		printf("%d\n", 1);
		return 0;
	}
	
	MatrixPower(B-1);
	
	printf("%lld\n", Power[0][0]);
	
	return 0;
}

// 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597
