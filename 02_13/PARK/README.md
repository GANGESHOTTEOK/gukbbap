# 2021년 02월 13일 토요일
# 백준 9012번 괄호
### https://www.acmicpc.net/problem/9012

---

### 문제 해결 날짜 및 시간
- 2021.02.10 21:44

---

### 접근방식
- VPS 변수를 선언해서 '('면 +1, ')'면 -1을 해서 결과에서 VPS == 0이라면 Yes출력 아니면 No출력
- 여기서 ')('이 입력되면 Yes라고 나오니까 VPS < 0인 경우 No로 출력하는 조건 추가

---

### 소스코드
- 1116KB, 0ms

```C
#include <stdio.h>

int main(void) {
	int T, Left = 0, Right = 0, VPS = 0;
	char Parenthesis[51];
	
	scanf("%d", &T);
	
	while (T--) {
		scanf("%s", &Parenthesis);
		for (int i = 0; Parenthesis[i] != '\0'; i++) {
			if (Parenthesis[i] == '(')
				VPS = VPS + 1;
			else
				VPS = VPS - 1;
			
			if (VPS < 0)
				break;
		}
		
		printf("%s\n", (VPS==0) ? "YES" : "NO");
		
		VPS = 0;
	}
	
	return 0;
} 
```
