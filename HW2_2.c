/*
20201514������
Assignment 2 : �ϳ��� ����ϴ� for���� Ȱ��
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