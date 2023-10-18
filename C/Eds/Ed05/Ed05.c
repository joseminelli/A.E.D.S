#include <stdio.h>
#include <math.h>

void Encerrar()
{
    printf("\nPressione ENTER para continuar...");
    char x = '0';
    do
    {
        x = getchar();
    } while ('\n' != x);
    getchar();
}

int calcularFatorial(int n)
{
    int fatorial = 1;
    for (int i = 1; i <= n; i++)
    {
        fatorial *= i;
    }
    return fatorial;
}


void exercicio0511()
{
    int n;
    printf("Digite a quantidade de múltiplos de 7 desejada: ");
    scanf("%d", &n);
    
    printf("Múltiplos de 7: ");
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", 7 * i);
    }
    printf("\n");
    Encerrar();
}

void exercicio0512()
{
    int n;
    printf("Digite a quantidade de múltiplos de 3 e 4 desejada: ");
    scanf("%d", &n);

    printf("Múltiplos de 3 e 4: ");
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", 12 * i);
    }
    printf("\n");
    Encerrar();
}

void exercicio0513()
{
    int n;
    printf("Digite a quantidade de potências de 5 desejada: ");
    scanf("%d", &n);

    int potencia = 5;
    printf("Potências de 5: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", potencia);
        potencia /= 5;
    }
    printf("\n");
    Encerrar();
}

void exercicio0514()
{
    int n;
    printf("Digite a quantidade de inversos de múltiplos de 7 desejada: ");
    scanf("%d", &n);

    printf("Inversos dos múltiplos de 7: ");
    for (int i = 1; i <= n; i++)
    {
        printf("%.2f ", 1.0 / (7 * i));
    }
    printf("\n");
    Encerrar();
}

void exercicio0515()
{
    int n;
    double x;
    printf("Digite a quantidade de valores desejada: ");
    scanf("%d", &n);
    printf("Digite o valor real x: ");
    scanf("%lf", &x);

    printf("Valores ímpares crescentes nos denominadores: ");
    for (int i = 0; i < n; i++)
    {
        printf("%.2f ", 1.0 / pow(x, 2 * i));
    }
    printf("\n");
    Encerrar();
}

void exercicio0516()
{
    int n;
    printf("Digite a quantidade de termos desejada: ");
    scanf("%d", &n);

    int soma = 0;
    int valor = 3;
    int cont = 0;
    while (cont < n)
    {
        if (valor % 3 == 0 && valor % 4 != 0)
        {
            soma += valor;
            cont++;
        }
        valor++;
    }

    printf("Soma dos primeiros %d termos: %d\n", n, soma);
    Encerrar();
}

void exercicio0517()
{
    int n;
    printf("Digite a quantidade de termos desejada: ");
    scanf("%d", &n);

    double soma = 0.0;
    int valor = 7;
    int cont = 0;
    while (cont < n)
    {
        if (valor % 7 == 0 && valor % 5 != 0)
        {
            soma += 1.0 / valor;
            cont++;
        }
        valor++;
    }

    printf("Soma dos inversos dos primeiros %d termos: %.2f\n", n, soma);
    Encerrar();
}

void exercicio0518()
{
    int n;
    printf("Digite a quantidade de termos desejada: ");
    scanf("%d", &n);

    int soma = 0;
    int valor = 7;
    for (int i = 0; i < n; i++)
    {
        soma += valor;
        valor++;
    }

    printf("Soma da adição dos primeiros %d números naturais: %d\n", n, soma);
    Encerrar();
}

void exercicio0519()
{
    int n;
    printf("Digite a quantidade de termos desejada: ");
    scanf("%d", &n);

    int soma = 0;
    int valor = 7;
    for (int i = 0; i < n; i++)
    {
        soma += valor * valor;
        valor++;
    }

    printf("Soma dos quadrados da adição dos primeiros %d números naturais: %d\n", n, soma);
    Encerrar();
}

void exercicio0520()
{
    int n;
    printf("Digite a quantidade de termos desejada: ");
    scanf("%d", &n);

    double soma = 0.0;
    int valor = 6;
    for (int i = 0; i < n; i++)
    {
        soma += 1.0 / valor;
        valor++;
    }

    printf("Soma dos inversos das adições de números naturais: %.2f\n", soma);
    Encerrar();
}


int main()
{
    int escolha;
    do
    {
        printf("\nEscolha uma opção:\n");
        printf("1. Exercício 0511\n");
        printf("2. Exercício 0512\n");
        printf("3. Exercício 0513\n");
        printf("4. Exercício 0514\n");
        printf("5. Exercício 0515\n");
        printf("6. Exercício 0516\n");
        printf("7. Exercício 0517\n");
        printf("8. Exercício 0518\n");
        printf("9. Exercício 0519\n");
        printf("10. Exercício 0520\n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            exercicio0511();
            break;
        case 2:
            exercicio0512();
            break;
        case 3:
            exercicio0513();
            break;
        case 4:
            exercicio0514();
            break;
        case 5:
            exercicio0515();
            break;
        case 6:
            exercicio0516();
            break;
        case 7:
            exercicio0517();
            break;
        case 8:
            exercicio0518();
            break;
        case 9:
            exercicio0519();
            break;
        case 10:
            exercicio0520();
            break;
        case 0:
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
        }
    } while (escolha != 0);
    Encerrar();

    return 0;
}