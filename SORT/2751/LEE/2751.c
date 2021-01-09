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
