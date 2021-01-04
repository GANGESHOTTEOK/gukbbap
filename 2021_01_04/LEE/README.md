
# 백준 2751번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 01월 04일 21시 52분

---

### 접근 방식
```c
#include <stdio.h>
#include <stdlib.h>

int compare (void *first, void *second)
{
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else 
        return 0;
}

int main(int argc, char** argv)
{
    int n; scanf("%d", &n);
    int arr[n];
    int arr_size = n;
    int i;
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);

    qsort(arr, arr_size, sizeof(int), compare);

    for (i = 0; i < arr_size; i++) {
        printf("%d", arr[i]);
        if (i != arr_size - 1) printf("\n");    
    }

    return 0;
}

```
C++로 풀다가 아무리 퀵정렬을 써도 정답이 안나와서 다른 사람 퀵 정렬 코드 올리니까 통과됨.
그래서 걍 개빡쳐서 예전에 C 언어로 풀었던 퀵정렬로 올렸더니 460ms가 나옴;;
역시 이런 문제는 거르는게 건강에 좋은듯.




