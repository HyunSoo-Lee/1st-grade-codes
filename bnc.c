#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int power(int x, int y);

int main(void) {
    srand(time(NULL));
    int ans_arr[4] = { 0, 0, 0, 0 };
    for (int i = 0; i < 4; i++) {
        ans_arr[i] = rand() % 9 + 1;

        for (int k = 0; k < i; k++) {
            if (ans_arr[i] == ans_arr[k])
                i--;
        }
    }
    
    printf("**Answer**");
    for (int i = 0; i < 4; i++) {
        printf("%d", ans_arr[i]);
    }
    
    while (1) {
        int input = 0;
        int cpr_arr[4] = { 0 };
        printf("\n**Input**");
        scanf("%d", &input);
        for (int i = 1; i < 5; i++) {
            cpr_arr[i - 1] = (input % power(10, i)) / power(10, i - 1);    
            //cpr_arr[i-1] : input을 10의 i승으로 나눈 나머지를 다시 10의 i-1승으로 나눈 해 ex) 1234 cpr_arr[0]은 4, cpr_arr[1]는 3...
        }
        int b_count = 0;
        int a_count = 0;
        for (int t = 0; t < 4; t++) {
            if (cpr_arr[3 - t] == ans_arr[t]) {
                a_count++;
            }
            else
                for (int k = 0; k < 4; k++) {
                    if (cpr_arr[3 - t] == ans_arr[k]) {
                        b_count++;
                    }
                }

        }
        if (a_count == 4) {
            printf("*** Congratulation, You Win!!! ***\n");
                break;
        }
        printf("Strike : %d \nBall : %d\nTry again...\n\n", a_count, b_count);
    }
    return 0;
}

int power(int x, int y) {
    if (y == 0) return 1;
    return x * power(x, y - 1);
}