#include <stdio.h>

// 2021.02.05 21:56

int main(void) {
	char Expression[51];
	int ArrToSubtract[51] = {0,};
	int Index = 0, Temp = 0, Min = 0;
	
	scanf("%s", &Expression);
	
	for (int i = 0; Expression[i]; i++) {
		if (Expression[i] == '-') {
			ArrToSubtract[Index] = ArrToSubtract[Index] + Temp;
			printf("- %d %d\n", Index, ArrToSubtract[Index]);
			Temp = 0;
			Index = Index + 1;
		}
		else if (Expression[i] == '+') {
			ArrToSubtract[Index] = ArrToSubtract[Index] + Temp;
			printf("+ %d %d\n", Index, ArrToSubtract[Index]);
			Temp = 0;
		}
		else {
			Temp = Temp*10 + (Expression[i] - '0');
			printf("Temp %d\n", Temp);
		}
	}
	ArrToSubtract[Index] = ArrToSubtract[Index] + Temp;
	// 위 for문의 if는 '-' or '+'일 때 배열에 값을 추가한다
	// 그래서 마지막 수는 그냥 Temp에 저장만 되고 배열에 추가되지 않는 것
	// 이것 때문에 마지막에 한번 더 처리 
	
	/*
	printf("%d Temp %d\n",Index, Temp);
	for (int i = 0; i <= Index; i++)
		printf("%d %d\n", i, ArrToSubtract[i]);
	*/
	Min = ArrToSubtract[0];
	for (int i = 1; i <= Index; i++)
		Min = Min - ArrToSubtract[i];
	
	printf("%d\n", Min);
	
	return 0;
}
// 43-43+45-45
