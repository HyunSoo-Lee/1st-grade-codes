/*
20201514������
Assignment 3-1 : �־��� ��(base)�� ����(exp)�� �ŵ����� ���� ���ϴ� �Լ�
*/

#include<stdio.h>

int power(int, int);

int main(void) {
	int base = 5, exp = 3;
	printf("The %dth power of %d is %d.\n", exp, base, power(base, exp));
}

int power(int a, int b) {
	int n = 1;
	int m = 1;
	for (n = 1; n <= b; n++) {
		m *= a;
	}
	return m;
}
