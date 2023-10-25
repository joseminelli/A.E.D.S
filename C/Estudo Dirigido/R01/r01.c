#include <stdio.h>
#include <stdlib.h>
#include "JMRL.h"

#define TAM 100


// Função para calcular o maior entre três valores
double maiorEntreTres(double a, double b, double c) {
    if (a >= b && a >= c) {
        return a;
    } else if (b >= a && b >= c) {
        return b;
    } else {
        return c;
    }
}
/*  COLOQUEI NA MINHA BIBLIOTECA (JMRL.h)
int detectarCaractere(char c) {
    if (isalpha(c)) {
        return 1; // Caracteres alfabéticos
    } else if (isdigit(c)) {
        return 2; // Dígitos
    } else if (isspace(c)) {
        return 3; // Espaço em branco
    } else {
        return 4; // Outros símbolos
    }
}

int ehPrimo(int numero) {
    int divisores = 0;
    for (int i = 1; i <= numero; i++) {
        if (numero % i == 0) {
            divisores++;
        }
    }
    return divisores == 2;
}
*/


int somaDivisoresImpares(int numero) {
    int soma = 0;
    for (int i = 1; i <= numero; i += 2) {
        if (numero % i == 0) {
            soma += i;
        }
    }
    return soma;
}
void exercicio02()
{
    int quantidade;
    do
    {
        quantidade = Readint("Digite uma quantidade: ");
    } while (quantidade < 0 || quantidade > TAM);

    int vetor[TAM];
    for (int i = 0; i < quantidade; i++)
    {
        vetor[i] = Readint("Digite um numero: ");
    }
    Print("\n");
    
    for (int i = 0; i < quantidade; i++) {
        if (ehPrimo(vetor[i])) {
            printf("o numero %d eh primo\n", vetor[i]);
        } else {
            printf("o numero %d NAO eh primo\n", vetor[i]);
        }
    }
}

void exercicio01()
{
    int quantidade;
    do
    {
        quantidade = Readint("Digite uma quantidade: ");
    } while (quantidade < 0 || quantidade > TAM);

    int vetor[TAM];
    for (int i = 0; i < quantidade; i++)
    {
        vetor[i] = Readint("Digite um numero: ");
    }
    Print("\n");
    for (int i = 0; i < quantidade; i++) {
        int resultado = somaDivisoresImpares(vetor[i]);
        printf("A soma dos divisores impares de %d é %d\n", vetor[i], resultado);
    }
}

void exercicio05() {
    int n;
    double valor;
    double somaMenor = 0.0, somaEntre = 0.0, somaMaior = 0.0;
    int contMenor = 0, contEntre = 0, contMaior = 0;
    double mediaMenor, mediaEntre, mediaMaior; 
    n = Readint("Digite a quantidade de valores: ");

    for (int i = 0; i < n; i++) {
        valor = Readdouble("Digite um valor real: ");
        if (valor < -13.25) {
            somaMenor += valor;
            contMenor++;
        } else if (valor >= -13.25 && valor <= 83.75) {
            somaEntre += valor;
            contEntre++;
        } else {
            somaMaior += valor;
            contMaior++;
        }
    }

    if (contMenor > 0) {
        mediaMenor = somaMenor / contMenor;
        printf("Média dos valores menores que -13.25: %.2lf\n", mediaMenor);
    } else {
        printf("Nenhum valor menor que -13.25 foi digitado.\n");
    }

    if (contEntre > 0) {
        mediaEntre = somaEntre / contEntre;
        printf("Média dos valores entre -13.25 e 83.75: %.2lf\n", mediaEntre);
    } else {
        printf("Nenhum valor entre -13.25 e 83.75 foi digitado.\n");
    }

    if (contMaior > 0) {
        mediaMaior = somaMaior / contMaior;
        printf("Média dos valores maiores que 83.75: %.2lf\n", mediaMaior);
    } else {
        printf("Nenhum valor maior que 83.75 foi digitado.\n");
    }

    double maiorMedia = maiorEntreTres(mediaMenor, mediaEntre, mediaMaior);
    printf("A maior média entre todas: %.2lf\n", maiorMedia);
}

int main()
{
    int escolha;
    do
    {
        Print("\nEscolha uma opcao:\n");
        Print("1. Exercicio 01\n");
        Print("2. Exercicio 02\n");
        Print("3. Exercicio 03\n");
        Print("4. Exercicio 04\n");
        Print("0. Sair\n");
        escolha = Readint("\nOpcao: ");
        
        switch (escolha)
        {
        case 1:
            exercicio01();
            Encerrar();
            break;
        case 2:
            exercicio02();
            Encerrar();
            break;
        case 3:
            exercicio03();
            Encerrar();
            break;
        case 4:
            exercicio4();
            Encerrar();
            break;
        case 0:
            break;
        default:
            Print("Opcao invalida. Tente novamente.\n");
        }
    } while (escolha != 0);

    Encerrar();

    return 0;
}
