/*
20201514������
Assignment 3-2 : �־��� ��/�� ���� ���� ��� ���
����: ��Ҵ� ��+���� ¦���̸� X,Ȧ����O
5�� 5���� �ƴ� �ٸ� ��� ���� �����ص� �־��� ������ �����ϰ� ���
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