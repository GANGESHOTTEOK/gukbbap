#include <stdio.h>

// 2021.01.04 18:53
// int 범위 -2,147,483,648 ~ 2,147,483,647
// 카운팅 배열과 숫자 장난 문제 

int main(void) {
	int N, DescendingOrderN = 0; // 정렬되지 않은 수, 내림차순으로 정절된 수 
	int CountArr[10] = {0,}; // 카운팅 배열. 한자리에 올 수 있는 수는 0 ~ 9. 그래서 크기가 10인 배열 선언 
	
	scanf("%d", &N);
	
	while(N) { // N = N/10으로 1의 자리 수를 잘라서 남을 때까지
		CountArr[N%10] = CountArr[N%10] + 1; // 카운팅 배열에 +1 씩
		N = N/10; // 1의 자리수 짜르기 
	}

	for (int i = 9; i >= 0; i--) { // 내림차순으로 정렬해야 하니까 9부터 시작
		if (CountArr[i] > 0) { // 카운팅 배열에 수가 있으면
			for (int j = 0; j < CountArr[i]; j++) { // 카운팅 배열 value 값 만큼 
				DescendingOrderN = (DescendingOrderN * 10) + i; // 내림차순으로 수 만들어 주기. 이전 수에 10 곱하고 현재 수 더해주고 
			}
		}
	}
	
	printf("%d\n", DescendingOrderN);
	
	return 0;
}
