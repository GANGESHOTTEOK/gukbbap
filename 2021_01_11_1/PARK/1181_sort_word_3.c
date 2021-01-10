#include <stdio.h>
#include <string.h>

// 2021.01.08 22:49
// 구조체 사용의 이유를 알게 해준 문제
// 구조체 확실히 공부하기. 11650_sort_coordinate 부터 다 구조체 활용 문제였음

// 중복 처리를 sort 할 때 다 쳐리하려고 하니 어려웠던 것.
// 그냥  출력부에서 처리해주면 되던 것 

// N이 1일 때를 처리하지 못해서 100%에서 틀렸다고 나왔던 것
// strcmp의 반환은 -1, 0, 1이 아니라 음수, 0, 양수

char StringArr[20000][51] = {0,};
char SortedStringArr[20000][51] = {0,};

int merge(int Left, int Right, int Middle, char StringArr[][51]) {
	
	int i = Left, j = Middle+1, k = Left;
	// 길이 확인 필요. 0이 되면 멈추기 (clear)
	// 중복 word
	int iLength = 0, jLength = 0;
	
	while(i <= Middle && j <= Right) {
		for (int l = 0; StringArr[i][l]; l++) // 첫번째 배열 길이
			iLength = iLength + 1;
		for (int l = 0; StringArr[j][l]; l++) // 두번째 배열 길이
			jLength = jLength + 1;
		
		if (iLength < jLength) { // 첫번째 배열의 길이가 작으면
			for (int l = 0; l < 51; l++) {
				SortedStringArr[k][l] = StringArr[i][l];
			}
			i = i + 1;
		}
		else if (jLength < iLength) { // 두번째 배열의 길이가 작으면
			for (int l = 0; l < 51; l++) {
				SortedStringArr[k][l] = StringArr[j][l];
			}
			j = j + 1;
		}
		else { // 길이가 같으면 
			if (strcmp(StringArr[i], StringArr[j]) < 0) { // 사전 순으로
				for (int l = 0; l < 51; l++) {
					SortedStringArr[k][l] = StringArr[i][l];
				}
				i = i + 1;
			}
			else {
				for (int l = 0; l < 51; l++) {
					SortedStringArr[k][l] = StringArr[j][l];
				}
				j = j + 1;
			}
		}
		k = k + 1;
		iLength = 0; // 길이 변수 초기화
		jLength = 0;
	}
	
	if (i <= Middle) {
		for (; i <= Middle; i++) {
			for (int l = 0; l < 51; l++) {
				SortedStringArr[k][l] = StringArr[i][l];
			}
			k = k + 1;
		}
	}
	else if (j <= Right) {
		for(; j <= Right; j++) {
			for (int l = 0; l < 51; l++) {
				SortedStringArr[k][l] = StringArr[j][l];
			}
			k = k + 1;
		}
	}

	for (int i = Left; i <= Right; i++) {
		for (int l = 0; l < 51; l++) {
			StringArr[i][l] = SortedStringArr[i][l];
		}
	}
}

int merge_sort(int Left, int Right, char StringArr[][51]) {
	int Middle = (Left+Right)/2;
	
	if (Left < Right) {
		merge_sort(Left, Middle, StringArr);
		merge_sort(Middle+1, Right, StringArr);
		merge(Left, Right, Middle, StringArr);
	}
}


int main(void) {
	int N;
	
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		scanf("%s", &StringArr[i]);
	}
	
	merge_sort(0, N-1, StringArr);
	
	printf("%s\n", StringArr[0]);
	for (int i = 1; i < N; i++) {
		if (strcmp(SortedStringArr[i-1], SortedStringArr[i]) != 0)
			printf("%s\n", SortedStringArr[i]);
	}
	
	return 0;
}
