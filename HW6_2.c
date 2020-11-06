#include<stdio.h>
#include<math.h>

double getrootp(double, double, double);
double getrootm(double* , double* , double*);

int main(void){
    double a=1,b=0,c=-25; 

    printf("%+.2f %-.2f", getrootp(a,b,c),getrootm(&a,&b,&c));

    return 0;
} 

double getrootp(double p,double q,double r) {
    int x;
    x = (-q + sqrt(q * q - 4 * p * r)) / (2 * p);
    return x;
} 

double getrootm(double* p, double* q, double* r) {
    int x;
    x = (-*q - sqrt(*q * *q - 4 * *p * *r)) / (2 * *p);
    return x;
}
