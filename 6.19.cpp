#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROLLS 36000

int main(void) {
    int frequency[13] = { 0 };

    srand(time(NULL)); 

    for (int i = 0; i < ROLLS; i++) {
        int die1 = 1 + rand() % 6;
        int die2 = 1 + rand() % 6;
        frequency[die1 + die2]++;
    }

    printf("%s %13s %15s\n", "點數總和", "出現次數", "預期機率(%)");
    
    int expected_ways[13] = { 0, 0, 1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1 };

    for (int sum = 2; sum <= 12; sum++) {
        double expected_pct = (expected_ways[sum] / 36.0) * 100;
        printf("%8d %13d %14.2f % %\n", sum, frequency[sum], expected_pct);
    }

    return 0;
}