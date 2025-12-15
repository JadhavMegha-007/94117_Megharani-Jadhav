#include<stdio.h>
void displayBinary(int n) {
    int bin[32];
    int i = 0;
    while (n > 0) {
        bin[i] = n % 2;
        n = n / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", bin[j]);
    }
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Binary: ");
    displayBinary(num);

    return 0;
}