/*
20201514������
Assignment 3: while ���ǹ��� Ȱ��
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