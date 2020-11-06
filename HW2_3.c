/*
20201514이현수
Assignment 3: while 조건문의 활용
*/

#include<stdio.h>

int main(void) {
	int i = 0;
	int j = 0;
	int k = 0;

	while (i < 5) {
        while (j > k) {
            printf(" ");
            k++;
        }
		if (i % 2 == 0) {
			printf("X");
			printf("\n");
		}
		if (i % 2 == 1) {
			printf("O");
			printf("\n");
		}
		i++;
		j += i;
	}
}