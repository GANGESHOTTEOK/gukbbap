#include <stdio.h>

// 2020.01.01 17:28

// 입력받는 숫자가 index가 되고 그 value를 하나씩 추가
// value가 1 이상인 배열의 index(number)만 출력 

// 굳이 if(Arr[i] > 0)을 넣을 필요가 없었음. 넣어서 더 느려졌던 것 

// 전역 변수를 사용하는 것이 메모리는 더 차지하지만 시간은 더 작음 

int Arr[10001] = {0,}; // 카운팅 배열 전역 변수로 선언

int main(void) {
	int N, Index = 0;
	
	scanf("%d", &N); // 입력 받는 수의 개수

	for (int i = 0; i < N; i++) {
		scanf("%d", &Index); // 값 입력 받기
		Arr[Index] = Arr[Index] + 1; // Index가 입력 받는 수. 그 수의 횟수가 몇개인 지 +1 
	}

	for (int i = 0; i < 10001; i++) { // 모든 수 탐색 
		for (int j = 0; j < Arr[i]; j++) { // 해당 수(i)에 값이 있다면(Arr[i]) for문이 한번 더 돌면서 출력 
			printf("%d\n", i);
		}
	}
	
	return 0;
}
