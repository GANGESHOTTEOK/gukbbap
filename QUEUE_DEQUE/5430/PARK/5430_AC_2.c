#include <stdio.h>

int T, N, Front = 0, Back = 0, Reverse = 0, Error = 0;
char Command[400001];
int NumArr[101];

int FrontD(void) {
	if (Front <= Back) {
		Front++;
		return 1;
	}
	else
		return 0;
}

int BackD(void) {
	if (Back >= Front) {
		Back--;
		return 1;
	}
	else
		return 0;
}

int main(void) {
	
	scanf("%d", &T);
	
	for (int i = 0, Error = 0; i < T; i++) {
		scanf("%s", &Command);
		scanf("%d%*c", &N);
		
		Back = N-1;
		
		scanf("%*c");
		for (int j = 0; j < N; j++) {
			scanf("%d%*c", &NumArr[j]);
		}

		for (int j = 0; Command[j] != '\0'; j++) {
			if (Command[j] == 'D') {
				if (Reverse == 0) {
					if (FrontD() == 0) {
						Error = 1;
						break;
					}
				}
				else {
					if (BackD() == 0) {
						Error = 1;
						break;
					}
				}
			}
			else {
				Reverse == 0 ? (Reverse = 1) : (Reverse = 0);
			}
		}

		if (Error == 1) {
			printf("error\n");
		}
		else {
			if (Reverse == 0) {
				printf("[");
				for (int j = Front; j < Back; j++) {
					printf("%d,", NumArr[j]);
				}
				if (Front <= Back)
					printf("%d]\n", NumArr[Back]);
				else
					printf("]\n");
			}
			else {
				printf("[");
				for (int j = Back; j > Front; j--) {
					printf("%d,", NumArr[j]);
				}
				if (Back >= Front)
					printf("%d]\n", NumArr[Front]);
				else
					printf("]\n");
			}
		}
		scanf("%*c");
		Front = 0, Back = 0, Reverse = 0, Error = 0;
	}
	
	
	return 0;
}
