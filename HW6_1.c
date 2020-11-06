#include<stdio.h>

int main(void){
	char cArr[2] = { 'a','b' };
	int iArr[2] = { 0,1 };
	double dArr[2] = { 0.1,0.2 };

	printf("The size of cArr, iArr, dArr is %d, %d, %d\n"
			, sizeof(cArr), sizeof(iArr), sizeof(dArr));
	printf("The address of cArr is %p\n", cArr);
	printf("The address of cArr[0] is %p\n", &cArr[0]);
	printf("The address of cArr[1] is %p\n", &cArr[1]);
	printf("The address of iArr is %p\n", iArr);
	printf("The address of iArr[0] is %p\n", &iArr[0]);
	printf("The address of iArr[1] is %p\n", &iArr[1]);
	printf("The address of dArr is %p\n", dArr);
	printf("The address of dArr[0] is %p\n", &dArr[0]);
	printf("The address of dArr[1] is %p\n", &dArr[1]);

	return 0;
	}