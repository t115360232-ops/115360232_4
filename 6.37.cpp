#include <stdio.h>


#define MAX_SIZE 100

int recursiveMaximum(const int array[], int size);

int main(void) {
    int n;
    int data[MAX_SIZE];

    printf("請輸入陣列元素個數(1 ~%d):", MAX_SIZE);
    if (scanf_s("%d", &n) != 1 || n <= 0 || n > MAX_SIZE) {
        printf("輸入個數無效！\n");
        return 1;
    }

    printf("請依序輸入%d個整數:", n);
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &data[i]);
    }

    int maxVal = recursiveMaximum(data, n);
    printf("陣列中的最大值為:%d\n", maxVal);

    return 0;
}

int recursiveMaximum(const int array[], int size) {
    if (size == 1) {
        return array[0];
    }
    int subMax = recursiveMaximum(array, size - 1);

    if (array[size - 1] > subMax) {
        return array[size - 1];
    }
    else {
        return subMax;
    }
}