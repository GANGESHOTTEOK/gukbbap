#include <stdio.h>

// 2021.01.15 22:25
// The Black Skirts - Till the End of Time

// 문제의 if 순서를 바꿔서 해결(21 0 0의 경우 1이나와야 하는데 1048576이 나옴) 

// 동적계획법 관련 자료 https://han.gl/2VFT8

int Memoization[21][21][21]; // w(a,b,c) 저장하기 위한 배열

int main(void) {
	int a, b, c;
	
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 21; j++) {
			for (int k = 0; k < 21; k++) {
				if (i <= 0 || j <= 0 || k <= 0) { // 3개의 index 중 0이 하나라도 있으면
					Memoization[i][j][k] = 1; // value = 1입니다, 아닌 경우에 계산 할 바탕을 만들기 위함 
				}
				else if (i < j && j < k) // i < j < k 라면 
					Memoization[i][j][k] = Memoization[i][j][k-1] + Memoization[i][j-1][k-1] - Memoization[i][j-1][k];
				else // 그 외 경우 
					Memoization[i][j][k] = Memoization[i-1][j][k] + Memoization[i-1][j-1][k] + Memoization[i-1][j][k-1] - Memoization[i-1][j-1][k-1];
			}
		}
	}

	while(1) {
		scanf("%d %d %d", &a, &b, &c);
		if (a == -1 && b == -1 && c == -1) // a==b==c==-1이라면 
			break; //while을 나가세요 
		else if (a <= 0 || b <= 0 || c <= 0) // 3중 하나라도 0이라면
			printf("w(%d, %d, %d) = %d\n", a, b, c, 1); // 답은 1
		else if (a > 20 || b > 20 || c > 20) // 하나라도 20보다 크면 
			printf("w(%d, %d, %d) = %d\n", a, b, c, Memoization[20][20][20]); // w(20, 20, 20)이 답
		else
			printf("w(%d, %d, %d) = %d\n", a, b, c, Memoization[a][b][c]); // 나머지는 w(a,b,c)가 답
	}
	
	return 0;
}
