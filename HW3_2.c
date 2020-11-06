/*
20201514이현수
Assignment 3-2 : 주어진 행/열 값을 가진 행렬 출력
조건: 요소는 행+열이 짝수이면 X,홀수면O
5행 5열이 아닌 다른 어떠한 수를 대입해도 주어진 조건을 만족하게 출력
*/

#include<stdio.h>

void printm(int, int);

int main(void) {
    int row = 5, column = 5;
    printm(row, column);
    return 0; 
}

void printm(int r, int c) {
    int n = 1;
    int m = 1;
    while(1) {
        int y = n + m;
        if (y % 2 == 0)
            printf("X");
        if (y % 2 == 1)
            printf("O");
        if (n % r == 0){
            printf("\n");
            m += 1;
            n = 0;
        }
        if (m-1 == c){
            break;
        }
        n++;
    }
}