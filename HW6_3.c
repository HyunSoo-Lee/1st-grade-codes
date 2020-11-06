#include<stdio.h>
int factorial(int); 
void getpermu(int,int,int*);
void getcombi(int,int,int*);
int address;

int main(void) {
    int n=4, r=2, nPr=0, nCr=0;
    
    getpermu(n, r, &nPr);
    getcombi(n, r, &nCr);
    
    printf("nPr is %d, and nCr is %d.", nPr, nCr);
    
    return 0;
}  

void getpermu(int n,int r,int *pp) {
    *pp = factorial(n) / factorial(n - r);
    address = *pp;
}

void getcombi(int n,int r,int *pc) {
    *pc = address / factorial(r);
}
    
int factorial(int n) {
    int i, result = 1;

    for (i = 1; i <= n; i++)
        result *= i;
    
    return result; 
}