#include <stdio.h>

int main(void) {
    char str1[100], str2[100], str[200];
    int i,j;

    printf("Input 1st string:"); 
    gets(str1);
    printf("Input2ndstring:"); 
    gets(str2);
    
    i = 0;
    while (str1[i] != '\0') {
        str[i] = str1[i];
        i++;
    }

    j = 0;
    while (str2[j] != '\0') {
        str[j+i] = str2[j];
        j++;
    }

    str[j + i] = '\0';

    printf("%s",str);
    return 0;
}