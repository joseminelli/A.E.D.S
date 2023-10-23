/*

Definir um procedimento para:
Dado um valor inteiro positivo (n> 2), produzir uma saída semelhante à descrita abaixo (um triângulo):
EX:
    *
    **
    ***
    ****
    *****
    ****
    ***
    **
    *
*/

#include <stdio.h>

void imprimirTriangulo(int n) {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
    
    for (i = n - 1; i >= 1; i--) {
        for (j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Digite um valor inteiro positivo (n > 2): ");
    scanf("%d", &n);
    
    if (n <= 2) {
        printf("O valor de n deve ser maior que 2.\n");
    } else {
        imprimirTriangulo(n);
    }

    return 0;
}
