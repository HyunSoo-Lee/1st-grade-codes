/*
20201514������
�� ��ȣ ���� �´� �� ǥ���ϱ�
*/

#include<stdio.h>

int main(void) { 
	int cr;  
	while (1) { 
		printf("Input color value:"); 
		scanf_s("%d", &cr); 
		if (0 <= cr && cr <= 100) {
			if (0 <= cr && cr < 25) {
				printf("Black!\n");
			}
			else if (25 <= cr && cr < 50) {
				printf("Dark Gray!\n");
			}
			else if (50 <= cr && cr < 75) {
				printf("Light Gray!\n");
			}
			else if (75 <= cr && cr < 100) {
				printf("White!\n");
			}

		}
		else {
			printf("Wrong!\n");
		}
	} 
	return 0; 
}