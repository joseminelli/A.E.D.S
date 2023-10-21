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

void readNumbers(char *fileName)
{
    FILE *arquivo = fopen(fileName, "rt");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    double numero = 0.0;

    while (fscanf(arquivo, "%lf", &numero) != EOF)
    {
        printf("%.10lf\n", numero); // Use %.10lf para imprimir com precisão de 10 casas decimais
    }

    fclose(arquivo);
}



/**
 Method_02.
*/
void method_02 ( )
{
 printf("\nConteudo do arquivo:\n");
 readNumbers ( "DADOS.TXT" );
} 


void Method_0711()
{
    printf("\nMethod_0711 - v0.0\n");
    
    int n;
    
    printf("Informe a quantidade de números a serem gerados: ");
    scanf("%d", &n);
    
    if (n <= 0)
    {
        printf("Quantidade inválida. Deve ser maior que zero.\n");
        return;
    }
    
    FILE *arquivo = fopen("DADOS.TXT", "wt");
    
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    
    int numero = 9;
    int count = 0;
    
    while (count < n)
    {
        if (numero % 3 == 0 && numero % 2 != 0)
        {
            fprintf(arquivo, "%d\n", numero);
            count++;
        }
        numero++;
    }
    
    fclose(arquivo);
    printf("Números gerados e gravados com sucesso em DADOS.TXT.\n");
}

void Method_0712()
{
    printf("\nMethod_0712 - v0.0\n");
    
    int n;
    
    printf("Informe a quantidade de números a serem gerados: ");
    scanf("%d", &n);
    
    if (n <= 0)
    {
        printf("Quantidade inválida. Deve ser maior que zero.\n");
        return;
    }
    
    FILE *arquivo = fopen("DADOS.TXT", "wt");
    
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    
    int numero = 77;
    int count = 0;
    
    while (count < n && numero >= 21)
    {
        if (numero % 7 == 0 && numero % 2 != 0)
        {
            fprintf(arquivo, "%d\n", numero);
            count++;
        }
        numero -= 14; 
    }
    
    fclose(arquivo);
    printf("Números gerados e gravados com sucesso em DADOS.TXT.\n");
}


void Method_0713()
{
    printf("\nMethod_0713 - v0.0\n");
    
    int n;
    
    printf("Informe a quantidade de números a serem gerados: ");
    scanf("%d", &n);
    
    if (n <= 0)
    {
        printf("Quantidade inválida. Deve ser maior que zero.\n");
        return;
    }
    
    FILE *arquivo = fopen("DADOS.TXT", "wt");
    
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    
    int numero = 1;
    int count = 0;
    
    while (count < n)
    {
        fprintf(arquivo, "%d\n", numero);
        numero *= 7;
        count++;
    }
    
    fclose(arquivo);
    printf("Números gerados e gravados com sucesso em DADOS.TXT.\n");
}

void Method_0714()
{
    printf("\nMethod_0714 - v0.0\n");
    
   int n;

    printf("Informe a quantidade de números a serem gerados: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Quantidade inválida. Deve ser maior que zero.\n");
        return;
    }

    FILE *arquivo = fopen("DADOS.TXT", "wt");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    double numero = 1.0;
    int count = 0;

    while (count < n)
    {
        fprintf(arquivo, "%.15lf\n", numero);
        numero *= (1.0 / 7.0); 
        count++;
    }

    fclose(arquivo);

    printf("Números gerados e gravados com sucesso em DADOS.TXT.\n");
}

void Method_0715()
{
    printf("\nMethod_0715 - v0.0\n");

    int n;
    double x;

    printf("Informe a quantidade de números a serem gerados (n): ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Quantidade inválida. Deve ser maior que zero.\n");
        return;
    }

    printf("Informe o valor real (x): ");
    scanf("%lf", &x);

    FILE *arquivo = fopen("DADOS.TXT", "wt");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    double resultado = 1.0;

    for (int i = 0; i < n; i++)
    {
        fprintf(arquivo, "%.10lf\n", resultado);
        resultado /= x * x; 
    }

    fclose(arquivo);

    printf("Números gerados e gravados com sucesso em DADOS.TXT.\n");
}

int main()
{
    int escolha;
    do
    {
        printf("\nEscolha uma opção:\n");
        printf("1. Ler Arquivo\n");
        printf("2. Ler quantidade e gravar múltiplos de 3 ímpares em ordem crescente\n");
        printf("3. Ler quantidade e gravar múltiplos de 7 ímpares em ordem decrescente\n");
        printf("4. Ler quantidade e gravar valores da sequência\n");
        printf("5. Ler quantidade e gravar em valores decrescentes na sequência\n");
        printf("6. Ler numeros e gravar sequência personalizada com potências\n");
        printf("\n0. Sair\n");
        printf("Opção: ");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            method_02();
            break;
        case 2:
            Method_0711();
            break;
        case 3:
            Method_0712();
            break;
        case 4:
            Method_0713();
        case 5:
            Method_0714();
            break;
        case 6:
            Method_0715();
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
