#include<stdio.h>
#include<math.h>
#define N 10

int main (void) {
    int i;
    double avg = 0, std = 0;
    double sum1 = 0, sum2 = 0;

    double point[N] = {0.0,1.1,2.2,  
        3.3,4.4,5.5,6.6,7.7,8.8,9.9};
    
    for (i = 0; i < N; i++) {
        sum1 += point[i];
    }
    avg = sum1 / N;

    for (i = 0; i < N; i++) {
        sum2 += (point[i]-avg)* (point[i] - avg);
    }
    std = sqrt(sum2/N);

    printf("Avg is %.2f.\n", avg);
    
    printf("Std is %.2f.", std);
    
    return 0;
}