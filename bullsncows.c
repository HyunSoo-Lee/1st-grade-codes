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
    printf("\n");
    
    while (1) {
        int input = 0;
        int cpr_arr[4] = { 0 };
        while (1) {
            int counta = 0;
            int countb = 0;
            printf("Input : ");
            scanf("%d", &input);
            for (int i = 1; i < 5; i++) {
                cpr_arr[i - 1] = (input % power(10, i)) / power(10, i - 1);
            } // cpr_arr에 대입
            for (int i = 0; i < 4; i++) {
                for (int k = 0; k < i; k++) {
                    if (cpr_arr[i] == cpr_arr[k])
                        counta++; //같은 숫자가 있다면, count값을 1 증가
                }
            }
            for (int i = 0; i < 4; i++) {
                if (cpr_arr[i] == 0)
                    countb++;
            }
            if (counta == 0 && countb == 0) {
                break;
            }
            else
                printf("**Caution: 숫자가 중복되거나, 0이 들어갔습니다.**\nTry again...\n\n");
        }
        int b_count = 0;
        int s_count = 0;
        for (int t = 0; t < 4; t++) {
            if (cpr_arr[3 - t] == ans_arr[t]) {
                s_count++;
            }
            else
                for (int k = 0; k < 4; k++) {
                    if (cpr_arr[3 - t] == ans_arr[k]) {
                        b_count++;
                    }
                }
        }
        if (s_count == 4) {
            printf("*** Congratulation, You Win!!! ***\n");
            break;
        }
        printf("Strike : %d \nBall : %d\nTry again...\n\n", s_count, b_count);
    }
    return 0;
}


int power(int x, int y) {
    if (y == 0) return 1;
    return x * power(x, y - 1);
}
