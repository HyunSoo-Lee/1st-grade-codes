/*
20201514������
Assignment 3-3 : ������������ Ȱ���Ͽ� �ִ�, �ּڰ� ���ϴ� �ڵ�
����: �����Լ� ������� �ʱ�
a,b,c�� ���� ���� ���� ���ư��� �ڵ� ����
*/

#include<stdio.h>

void getmax(void);
void getmin(void);
float a, b, c, max, min;

int main(void) {
    a = 3.5, b = -4.5, c = 2.3e-1, max = min = 0;
    getmax();
    getmin();
    printf("Max number is %f.\n", max);
    printf("Min number is %f.\n", min);
    return 0;
}

void getmax(void) {
    if (a - b >= 0) {
        if (a - c >= 0) {
            max += a;
        }
        else
            max += c;
    }
    else
        if (b - c >= 0) {
            max += b;
        }
        else
            max += c;
}

void getmin(void) {
    if (a - b <= 0) {
        if (a - c <= 0) {
            min += a;
        }
        else
            min += c;
    }
    else
        if (b - c <= 0) {
            min += b;
        }
        else
            min += c;
}
