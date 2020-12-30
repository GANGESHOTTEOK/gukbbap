#include <stdio.h>

// 2020.12.29 18:16

// 4중 for문 refactoring 무조건 하기!!! 
// 충분히 줄이기 가능. 지금은 비효율적임. 간결하게 바꾸기
// 특히 now_fix 없애고 해보기 
// refactoring 후에 다른 사람 코드 참고하기 

// 배열로 문자열 받기(선언은 2차원 배열) scanf("%s", &board[i]);

int traversal(int n, int m, char now, char board[][51]) {
	int count = 0, min = 64;
	char now_fix = now;

	for (int k = 0; k < n-8+1; k++) {
		for (int l = 0; l < m-8+1; l++) {
			now = now_fix;
			
			for (int i = k; i < k+8; i++) {
				for (int j = l; j < l+8; j++) {

					if (now != board[i][j])
						count = count + 1;
					
					if (now == 'W')
						now = 'B';
					else
						now = 'W';
				}
				
				if (now == 'W')
					now = 'B';
				else
					now = 'W';
			}
			if (count < min)
				min = count;

			count = 0;
		}
	}
	return min;
}

int main(void) {
	int n = 0, m = 0, count = 0, min = 64;
	char now = 'W';
	int Black = 0, White = 0;
	char board[51][51] = {0,};
	
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%s", &board[i]);
	}
	
	White = traversal(n, m, now, board);
	now = 'B';
	Black = traversal(n, m, now, board);
	
	if (White < Black)
		printf("%d\n", White);
	else
		printf("%d\n", Black);
	
	return 0;
}

