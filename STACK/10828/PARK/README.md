# 2021년 02월 11일 목요일
# 백준 10828번 스택
### https://www.acmicpc.net/problem/10828

---

### 문제 해결 날짜 및 시간
- 2021.02.10 19:52

---

### 접근방식
- 스택의 명령을 그냥 구현하면 되는 문제

---

### 소스코드
- 1116KB, 4ms

```C
#include <stdio.h>
#include <string.h>

// 구조체에 Top, Stack[10000]가 정석인가 봄 
// https://www.acmicpc.net/source/10919744

// 간단 https://www.acmicpc.net/source/17761153 

int main(void) {
	int N, Size = -1, PushNum;
	int Stack[10000], Command[7];
	
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		scanf("%s", Command);
		
		if (strcmp(Command, "push") == 0) { // push라면
			Size = Size + 1; // 배열 길이 +1
			scanf("%d", &Stack[Size]); // 배열에 값 저장
		}
		else if (strcmp(Command, "pop") == 0) { // pop라면
			if (Size == -1) // 배열에 값이 없으면
				printf("%d\n", -1); // 없어용~
			else { // 배열에 값이 있으면
				printf("%d\n", Stack[Size]); // 해당 값 출력하고 삭제
				Size = Size - 1; // index 변경(유사 삭제)
			}
		}
		else if (strcmp(Command, "size") == 0) // size라면
			printf("%d\n", Size + 1); // Size가 -1부터 시작하니 +1후에 출력
		else if (strcmp(Command, "empty") == 0) // empty라면
			printf("%d\n", (Size != -1) ? 0 : 1); // 비어 있으면(Size == 1) 1출력, 아니면 0출력
		else { // top이라면
			if (Size == -1) // 배열에 값이 없다면
				printf("%d\n", -1); // -1 출력
			else // 배열에 값이 있다면
				printf("%d\n", Stack[Size]); // 해당 index 값 출력
		}
	}
	
	return 0;
}
```
