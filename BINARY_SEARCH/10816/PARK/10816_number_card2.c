#include <stdio.h>
#include <stdlib.h>

// 2021.03.14 21:21

// 배열을 카운팅 배열을 사용해서 엄청 간단하게 풀이가 가능하나
// 이건 이 문제라서 사용할 수 있는 것. 만약에 수의 범위가 int 전체였다면 틀린 코드

// 해당 수를 찾고 거기서 내가 원하는 수를 찾으려고 하니
// 범위가 이상해 졌던 것
// 그냥 처음부터 범위를 구해야 하는 문제 

int Card[500001], NumArr[500001], Repetition[500001];
int N, M;

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

// lower와 Upper를 만들지 않고 그냥 하나의 함수로 처리하고 마지막에 +1 해줘도 됐을 듯 
int Lower(int Start, int End, int Num) {
	
	while (End > Start) {
		int MiddleIndex = Start+((End-Start)/2);
		if (Card[MiddleIndex] >= Num)
			End = MiddleIndex;
		else
			Start = MiddleIndex+1;
	}
	return End;
}

int Upper(int Start, int End, int Num) {
	
	while (End > Start) {
		int MiddleIndex = Start+((End-Start)/2);
		if (Card[MiddleIndex] > Num)
			End = MiddleIndex;
		else
			Start = MiddleIndex+1;
	}
	return End;
}

int main(void) {

	scanf("%d", &N);
	
	for (int i = 0; i < N; i++)
		scanf("%d", &Card[i]);
	
	qsort(Card, N, sizeof(int), compare);
	
	scanf("%d", &M);
	
	for (int i = 0; i < M; i++)
		scanf("%d", &NumArr[i]);

	for (int i = 0; i < M; i++) {
		printf("%d ", Upper(0, N, NumArr[i]) - Lower(0, N, NumArr[i]));
	}
	
	return 0;
} 
