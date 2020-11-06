/*
20201514이현수
Assignment 2 : 하나만 사용하는 for문의 활용
*/

#include<stdio.h>

int main(void) {
	int i = 0;

	for (i = 1;i <= 32;i++) {
		printf("$");
		if (i % 8 == 0) {
			printf("\n");
		}
	}
}