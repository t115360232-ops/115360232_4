#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

void stringReverse(const char str[]);

int main(void) {
    char str[MAX_LEN];

    printf("請輸入一段字串:");
    if (fgets(str, sizeof(str), stdin) != NULL) {

        str[strcspn(str, "\n")] = '\0';

        printf("反向輸出:");
        stringReverse(str);
        printf("\n");
    }

    return 0;
}

void stringReverse(const char str[]) {
    if (str[0] == '\0') {
        return;
    }
    stringReverse(&str[1]);
    putchar(str[0]);
}