# 2021년 02월 02일 화요일
# 백준 9251번 [LCS]
### https://www.acmicpc.net/problem/9251

---

### 문제 해결 날짜 및 시간
- 2021.01.29 00:05

---

### 접근 방식
- 처음에는 2개 배열의 앞에서부터 하나씩 같은 것이 있는지 확인하고 있으면 다음 index로 넘기는 식으로 했는데 이는 모든 경우의 수를 탐색하지 않음. 그래서 AAATATA, ATATA를 넣으면 5(ATATA)가 아닌 3(AAA)이 출력 되는것
- 모든 경우의 수를 탐색할 필요가 있고 여기에서 현재 가르키고 있는 index 앞까지의 결과에 현재 결과를 추가할 필요가 있었음. 그래서 2중 for문으로 모든 경우의 수(글자수를 제한하며)를 조건문으로 결과 갱신이 필요했음
- 조건문으로는 현재 비교하는 두 문자가 동일한지 아닌지. 동일하다면 두 문자열의 현재 index 바로 앞까지 비교한 결과에서 Count[i-1][j-1]+1을 저장하고, 아니라면 두 문자열 중 어느 문자열의 결과가 더 큰지 비교 후 결과 반영(Count[i][j] = Count[i-1][j] >= Count[i][j-1] ? Count[i-1][j] : Count[i][j-1])
- 여기서 주의 할 점은 i or j의 index가 0일 때는 참조할 index가 없으니 초기화 해주는 과정이 필요하다.

---

### 소스코드
- 5028KB, 4ms

```C
#include <stdio.h>

int Count[1001][1001];

int main(void) {
	char Str1[1001], Str2[1001];
	int MaxCount = 0;
	
	scanf("%s", Str1);
	scanf("%s", Str2);
	
	for (int i = 0; Str1[i] != 0; i++) {
		for (int j = 0; Str2[j] != 0; j++) {
			if (i == 0 || j == 0) { // i or j가 0이라면 (참조할 index가 없으니 초기화)
				if (Str1[i] == Str2[j]) // 두 문자가 같으면
					Count[i][j] = 1; // 1로 초기화
				else // 두 문자가 다르면
					Count[i][j] = i == 0 ? Count[i][j-1]: Count[i-1][j]; // i or j 어느 index가 0인지 확인하고 0이 아닌 index의 앞 결과 반영
			}
			else if (Str1[i] == Str2[j]) { // 두 문자가 같으면
				Count[i][j] = Count[i-1][j-1] + 1; // 현재 index 바로 앞까지의 LCS 결과에 +1
			}
			else { // 두 문자가 다르면
				Count[i][j] = Count[i-1][j] >= Count[i][j-1] ? Count[i-1][j] : Count[i][j-1]; // 두 문자열 중 더 큰 값 선택
			}
			if (Count[i][j] > MaxCount) // 최대 count 
				MaxCount = Count[i][j];
		}
	}
	
	printf("%d\n", MaxCount);
	
	return 0;
}
```
