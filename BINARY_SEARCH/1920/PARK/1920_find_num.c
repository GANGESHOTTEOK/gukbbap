#include <stdio.h>
#include <stdlib.h>

// 2021.03.13 22:08

int ArrN[100001], ArrM[100001];

int compare(const void *a, const void *b)
{
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if (num1 < num2)
        return -1;
    
    if (num1 > num2)
        return 1;
    
    return 0;
}

int Find(int Start, int End, int Num) {
	int MiddleIndex = Start+((End-Start)/2);
	
	if (Start > End)
		return 0;

	if (ArrN[MiddleIndex] == Num)
		return 1;
	else if (ArrN[MiddleIndex] > Num)
		Find(Start, MiddleIndex-1, Num);
	else if (ArrN[MiddleIndex] < Num)
		Find(MiddleIndex+1, End, Num);
	else
		return 0;
}

int main(void) {
	int N, M;
	
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++)
		scanf("%d", &ArrN[i]);
	
	qsort(ArrN, N, sizeof(int), compare);
	
	scanf("%d", &M);
	
	for (int i = 0; i < M; i++)
		scanf("%d", &ArrM[i]);

	for (int i = 0; i < M; i++) {
		printf("%d\n", Find(0, N, ArrM[i])); // 여기 범위를 틀림(N이 아니라 M을 넣어버림) 
	} 
	
	return 0;
}
/*
7
1 3 4 6 9 13 18
18
3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
*/
