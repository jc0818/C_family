#include <stdio.h>
#include <stdlib.h>

int main() {
    int size = 3;
    int arraySize = size;
    int count, input;
    int *arr = (int *)malloc(arraySize * sizeof(int));

    printf("입력할 숫자의 개수 >> ");
    scanf("%d", &count);

    for (int i = 0; i < count; i++) {
        if (i >= arraySize) {
            arraySize += size;
            printf("배열 크기를 확장합니다..\n");
            arr = (int *)realloc(arr, arraySize * sizeof(int));
        }
        printf("숫자 입력 >> ");
        scanf("%d", &input);
        arr[i] = input;
    }

    printf("최종 배열은 ");
    for (int i = 0; i < count; i++) {
        printf("%d ", arr[i]);
    }
    printf("입니다.\n");

    free(arr);
    return 0;
}
