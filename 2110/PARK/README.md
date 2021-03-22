
# 2021년 3월
# 백준 2110번 [공유기 설치]
### https://www.acmicpc.net/problem/2110
---

### 문제 해결 날짜 및 시간

- 2021.03.22 16:03

---

### 접근 방식
- 공유기 간의 간격을 기준으로 잡고 이분탐색
- 기준 간격보다 집의 간격이 더 크거나 같으면 설치
- 설치된 라우터의 개수와 설치해야할 라우터의 개수 

### 소스코드
- 메모리 : 2168KB
- 시간 : 28ms
```C
#include <stdio.h>
#include <stdlib.h>

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

int main(void) {
	int N, C, Ans, NowLen = 0, MaxLen = 0, PreHome = 0;
	int Home[200001];
	
	scanf("%d %d", &N, &C);
	
	for (int i = 0; i < N; i++)
		scanf("%d", &Home[i]);
	
	qsort(Home, N, sizeof(int), compare); // 정렬
	
	NowLen = 1; // 공유기 간의 최소 간격
	//MaxLen = (Home[N-1] - Home[0] + 1)/C; // 랜선 문제처럼 두려고 했는데 넣으면 시간 초과
	MaxLen = Home[N-1] - Home[0]; // 공유기 간의 최대 간격
	
	while(NowLen <= MaxLen) { // 현재 공유기 간의 간격이 최대 간격을 넘을 때까지 반복
		int Mid = (NowLen+MaxLen)/2; // 공유기 간의 간격 기준
		int PreHome = Home[0]; // 바로 전에 라우터 설치한 집의 좌표 저장
		int Count = 1; // 첫 집에는 무조건 넣고 시작
		
		for (int i = 1; i < N; i++) { // 모든 집 탐색
			if (Mid <= (Home[i] - PreHome)) { // 이전에 설치한 집과 현재 집의 차가 기준보다 크다면
				PreHome = Home[i]; // 이전 집 갱신
				Count++; // 라우터 개수 추가
			}
		}
		
		if (Count >= C) { // 현재 mid 간격에 따라 설치한 개수가 원래 개수보다 크거나 같으면
			NowLen = Mid+1; // 현재 len 더 크게
			Ans = Mid; // 정답 가능성
		}
		else
			MaxLen = Mid-1;
		
	}
	
	printf("%d\n", Ans);
	
	return 0;
}
```
