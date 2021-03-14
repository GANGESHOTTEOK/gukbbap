
# 2021년 3월
# 백준 10816번 [숫자 카드 2]
### https://www.acmicpc.net/problem/10816
---

### 문제 해결 날짜 및 시간

- 2021.03.13 22:08

---

### 접근 방식
- 1920 수 찾기는 해당 수를 찾는 거라면 이 문제는 구간을 찾아야 하는 문제
- 따라서 해당 수가 처음으로 나오는 index, 마지막으로 나오는 index를 찾는 함수가 필요하다
- 그리고 이 과정에서 구간을 둘로 나누고 택 1하는 것이 필요한 것
- 처음에는 수를 찾고 구간을 찾으려고 했는데 그러면 start와 end가 내가 원하는 범위만큼 가지지 않는다
- 따라서 바로 구간 찾는 문제

### 소스코드
- 메모리 : 8932KB
- 시간 : 440ms
```C
#include <stdio.h>
#include <stdlib.h>

// 배열을 카운팅 배열을 사용해서 엄청 간단하게 풀이가 가능하나 a[10000000]
// 이건 이 문제라서 사용할 수 있는 것. 만약에 수의 범위가 int 전체였다면 틀린 코드

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
```
