#include<stdio.h>

int main (void) {
    char str[100] = "Yesterday \"All\" My \'Troubles\' Seemed So Far Away.";
    int nArr[3] = {0, 0, 0} , i = 0;
   

    while (str[i] != '\0') {

        int t = str[i];

        if (65 <= t && 90 >= t) {
            nArr[0]++;

        }
        else if (97 <= t && 122 >= t) {
            nArr[1]++;

        }
        else {
            nArr[2]++;
        }
        i++;
    }


    for (i = 0; i < 3; i++) {
        printf("%d,", nArr[i]);
    }
    return 0;
}