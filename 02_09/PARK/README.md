# 2021년 02월 09일 화요일
# 백준 1541번 잃어버린 괄호
### https://www.acmicpc.net/problem/1541

---

### 문제 해결 날짜 및 시간
- 2021.02.05 21:56

---

### 접근방식
- 더하는 부분은 다 더하고 한번에 다 빼야 최소값을 구할 수 있다
- 그래서 string으로 받고 현재 index가 숫자라면 Temp에 숫자를 저장하고
- 현재 index가 '+'라면 ArrToSubtract(마지막에 최종으로 다 빼줄 수들) 배열에 합하기
- '-'라면 다음 ArrToSubtract의 index를 다음으로 넘기기
- 그러고 마지막에 ArrToSubtract 다 빼기

---

### 소스코드
- 1116KB, 0ms

```C
#include <stdio.h>

int main(void) {
	char Expression[51];
	int ArrToSubtract[51] = {0,};
	int Index = 0, Temp = 0, Min = 0;
	
	scanf("%s", &Expression);
	
	for (int i = 0; Expression[i]; i++) {
		if (Expression[i] == '-') { // 빼기라면
			ArrToSubtract[Index] = ArrToSubtract[Index] + Temp; // 기존에 만들어진 Temp 숫자를 추가
			Temp = 0; // 초기화
			Index = Index + 1; // 다음 index로
		}
		else if (Expression[i] == '+') { // 더하기라면
			ArrToSubtract[Index] = ArrToSubtract[Index] + Temp; // 기존에 만들어진 Temp 숫자를 추가
			Temp = 0; // 초기화
		}
		else { // 숫자라면
			Temp = Temp*10 + (Expression[i] - '0'); // char을 int로 만들기
		}
	}
	ArrToSubtract[Index] = ArrToSubtract[Index] + Temp;
	// 위 for문의 if는 '-' or '+'일 때 배열에 값을 추가한다
	// 그래서 마지막 수는 그냥 Temp에 저장만 되고 배열에 추가되지 않는 것
	// 이것 때문에 마지막에 한번 더 처리 

	Min = ArrToSubtract[0];
	for (int i = 1; i <= Index; i++)
		Min = Min - ArrToSubtract[i];
	
	printf("%d\n", Min);
	
	return 0;
}
```
