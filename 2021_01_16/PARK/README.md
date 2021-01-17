
# 2021년 01월 16일 토요일
# 백준 14889번 [스타트와 링크]
### https://www.acmicpc.net/problem/14889

---

### 문제해결 날짜 및 시간
- 2021.01.13 17:47

---

### 접근방식
- 팀을 만드는 부분, 팀의 능력치를 계산하는 부분, 2팀 능력치의 최소차 부분 필요
- 팀 만드는 부분은 백트래킹(Visited 배열로 0팀과 1팀)
- 팀의 능력치를 계산하는 부분은 2중 for문으로 index 2개 다 0 인 팀 or 1인 팀으로 연산
- 2팀 능력치 최소차 부분은 abs사용해서 현재 최소보다 더 최소이면 대입 연산

---

### 소스코드
- 1116KB, 132ms
```C
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// 2021.01.13 17:47

int StatArr[20][20]; // 처음 stat을 입력 받는 배열 
int Gap = 0, MinGap = INT_MAX; // 스타트 팀과 링크팀의 차와 그 차의 최소값
int StartStat = 0, LinkStat = 0; // 각 팀의 스탯 저장
int Visited[20] = {0,}; // 처음 팀을 만들 때 사용하는 배열 
int N; // 인원 입력 받는 변수

int GetMinGap(void) {
	Gap = abs(StartStat - LinkStat);
	
	if (MinGap > Gap) {
		MinGap = Gap;
	}
	return 0;
}

// 나눈 팀을 바탕으로 팀의 각 원소별 쌍방 능력치를 계산하여 2팀의 차를 구하고 그 값의 최소를 판단한다
// 처음 입력 받은 배열을 사용하기 위해 2중 for문을 사용하였다
int CalcStat(void) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (Visited[i] && Visited[j]) { // 각 원소가 1번 팀이라면
				StartStat = StartStat + StatArr[i][j];
			}
			else if (!Visited[i] && !Visited[j]) { // 각 원소가 0번 팀이라면 
				LinkStat = LinkStat + StatArr[i][j];
			}
		}
	}

	GetMinGap();
	StartStat = 0, LinkStat = 0;
	return 0;
}

// Visited 배열의 value가 1인 팀과 0인 팀으로 팀을 구성한다 
// 팀을 나누기 위해서 모든 경우의 수가 필요했고 백트래킹을 사용하였다.
// NowPlayer는 현재 몇번 player인지를 나타낸다
// Depth는 현재 팀원이 몇명인지 나타낸다 
int MakeTeam(int NowPlayer, int Depth) {
	if (Depth == N/2) { // 각 팀의 인원은 총 인원의 반이다.
		CalcStat();
	}
	for (int i = NowPlayer; i < N; i++) {
		if(!Visited[i]) {
			Visited[i] = 1;
			MakeTeam(i+1, Depth+1);
			Visited[i] = 0;
		}
	}
}

int main(void) {

	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &StatArr[i][j]);
		}
	}
	
	MakeTeam(0, 0);
	
	printf("%d\n", MinGap);
	
	return 0;
}
```

```C
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// 2021.01.13 17:47
// 다른사람 코드와 비교해보기 https://www.acmicpc.net/source/13484770

// 2팀을 만들고 팀의 점수를 계산한다. 2팀의 최소 능력치 차이를 구하는 문제
// 팀을 만드는 함수, 팀의 능력치를 계산하는 함수, 최소를 구하는 함수로 나누었다 

// 팀을 만드는 함수 : 백트래킹을 사용했다. 15649 N&M과 동일하게 만들었다.
// 정지 조건으로는 N/2가 되었을 때 각 팀의 능력치를 계산하는 함수를 호출한다 
// 결과로 Visited배열에 value가 0인 팀과 1인 팀으로 나누어 진다. 

// 팀의 능력치를 계산하는 함수 : 능력치 배열(StatArr)을 사용하기 위해 2중 for을 사용했다
// 조건문으로 2명의 선수가 모두 1번 팀인지 0번 팀인지 판단해서 각 팀 능력치를 계산한다
// 계산 후에 능력치 차의 최소를 구하는 함수를 호출한다

// 능력치 차의 최소를 구하는 함수 : 차를 구하고 조건문으로 최소 차를 구했다. 

int StatArr[20][20]; // 처음 stat을 입력 받는 배열 
int Gap = 0, MinGap = INT_MAX; // 스타트 팀과 링크팀의 차와 그 차의 최소값
int StartStat = 0, LinkStat = 0; // 각 팀의 스탯 저장
int Visited[20] = {0,}; // 처음 팀을 만들 때 사용하는 배열 
int N; // 인원 입력 받는 변수

int GetMinGap(void) {
	Gap = abs(StartStat - LinkStat);
	
	if (MinGap > Gap) {
		MinGap = Gap;
	}
	return 0;
}

// 나눈 팀을 바탕으로 팀의 각 원소별 쌍방 능력치를 계산하여 2팀의 차를 구하고 그 값의 최소를 판단한다
// 처음 입력 받은 배열을 사용하기 위해 2중 for문을 사용하였다
int CalcStat(void) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (Visited[i] && Visited[j]) { // 각 원소가 1번 팀이라면
				StartStat = StartStat + StatArr[i][j];
			}
			else if (!Visited[i] && !Visited[j]) { // 각 원소가 0번 팀이라면 
				LinkStat = LinkStat + StatArr[i][j];
			}
		}
	}

	GetMinGap();
	StartStat = 0, LinkStat = 0;
	return 0;
}

// Visited 배열의 value가 1인 팀과 0인 팀으로 팀을 구성한다 
// 팀을 나누기 위해서 모든 경우의 수가 필요했고 백트래킹을 사용하였다.
// NowPlayer는 현재 몇번 player인지를 나타낸다
// Depth는 현재 팀원이 몇명인지 나타낸다 
int MakeTeam(int NowPlayer, int Depth) {
	if (Depth == N/2) { // 각 팀의 인원은 총 인원의 반이다.
		CalcStat();
	}
	// 팀을 구성하는 모든 경우의 수 탐색이 필요했기에 for문에 재귀를 사용했다. 
	// 아래 과정을 통해 value가 0인 팀과 1인 팀으로 나누진다. 
	for (int i = NowPlayer; i < N; i++) {
		if(!Visited[i]) {
			Visited[i] = 1;
			MakeTeam(i+1, Depth+1);
			Visited[i] = 0;
		}
	}
}

int main(void) {

	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &StatArr[i][j]);
		}
	}
	
	MakeTeam(0, 0);
	
	printf("%d\n", MinGap);
	
	return 0;
}
```
