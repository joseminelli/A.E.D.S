/*
Dados um valor inteiro positivo (n) e uma função real para calcular a soma

Se (n) for impar, calcular a diferença entre o valor da soma para essa quantidade e o valor da soma para o próximo ímpar;
Se (n) for par, calcular apenas o valor da soma para o impar imediatamente inferior.

NÃO GARANTO ESTAR CERTO

*/

#include <stdio.h>

double calcularSoma(int n) {
    double soma = 0.0;

    for (int i = 1; i <= n; i += 2) {
        soma += i;
    }

    return soma;
}

int main() {
    int n;
    double resultado;

    printf("Digite um valor inteiro positivo (n): ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("O valor de n deve ser um inteiro positivo.\n");
    } else {
        if (n % 2 == 1) {
            double soma_n = calcularSoma(n);
            double soma_proximo_impar = calcularSoma(n + 2);
            resultado = soma_n - soma_proximo_impar;
            printf("Diferença entre a soma de %d e a soma do próximo ímpar: %.2f\n", n, resultado);
        } else {
            resultado = calcularSoma(n - 1);
            printf("Soma para o ímpar imediatamente inferior a %d: %.2f\n", n, resultado);
        }
    }

    return 0;
}
