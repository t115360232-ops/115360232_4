#include <stdio.h>
#define SIZE 15

int binarySearch(const int b[], int low, int high, int key);

int main(void) {
    int a[SIZE];
   
    for (int i = 0; i < SIZE; i++) {
        a[i] = 2 * i;
    }

    int key;
    printf("請輸入要搜尋的整數(0 ~28): ");
    scanf_s("%d", &key);

    int result = binarySearch(a, 0, SIZE - 1, key);

    if (result != -1) {
        printf("在陣列索引%d找到數值%d\n", result, key);
    }
    else {
        printf("找不到數值%d\n", key);
    }

    return 0;
}

int binarySearch(const int b[], int low, int high, int key) {
    if (low > high) {
        return -1;
    }

    int middle = (low + high) / 2;

    if (key == b[middle]) {
        return middle; 
    }
    else if (key < b[middle]) {
        return binarySearch(b, low, middle - 1, key); 
    }
    else {
        return binarySearch(b, middle + 1, high, key);
    }
}