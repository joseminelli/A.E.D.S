#include <stdio.h>
#include <stdlib.h>

#define MAX 100

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

void readMatrix(int matrix[MAX][MAX], int *rows, int *cols)
{
    int i, j;
    char opcao;

    do
    {
        printf("Digite o numero de linhas: ");
        scanf("%d", rows);
        printf("Digite o numero de colunas: ");
        scanf("%d", cols);
        if (*rows > MAX || *cols > MAX)
        {
            printf("\n==== AVISO ====");
            printf("\nO numero de linhas e colunas deve ser menor ou igual a %d.\n\n", MAX);
        }
        if (*rows < 1 || *cols < 1)
        {
            printf("\n==== AVISO ====");
            printf("\nO numero de linhas e colunas deve ser maior ou igual a 1.\n\n");
        }
    } while (*rows > MAX || *cols > MAX || *rows < 1 || *cols < 1);

    printf("Deseja preencher a matriz com numeros positivos nao nulos? (s/n): ");
    scanf(" %c", &opcao);
    printf("\n");
    if (opcao == 'S' || opcao == 's')
    {
        for (i = 0; i < *rows; i++)
        {
            for (j = 0; j < *cols; j++)
            {
                do
                {
                    printf("Digite o valor para matrix[%d][%d]: ", i, j);
                    scanf("%d", &matrix[i][j]);
                } while (matrix[i][j] < 1);
            }
        }
    }
    else
    {
        for (i = 0; i < *rows; i++)
        {
            for (j = 0; j < *cols; j++)
            {
                printf("Digite o valor para matrix[%d][%d]: ", i, j);
                scanf("%d", &matrix[i][j]);
            }
        }
    }
}

void printDiagonalPrincipal(int matrix[MAX][MAX], int rows, int cols)
{
    if (rows != cols)
    {
        printf("A matriz nao e quadrada, nao ha diagonal principal.\n");
        return;
    }

    printf("-- Diagonal Principal --\n");
    for (int i = 0; i < rows; i++)
    {
        printf("%d ", matrix[i][i]);
    }
    printf("\n");
}

void printAbaixoDiagonalPrincipal(int matrix[MAX][MAX], int rows, int cols)
{
    if (rows != cols)
    {
        printf("A matriz nao e quadrada, nao ha diagonal principal.\n");
        return;
    }

    printf("-- Valores Abaixo da Diagonal Principal --\n");
    for (int i = 1; i < rows; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void printAcimaDiagonalPrincipal(int matrix[MAX][MAX], int rows, int cols)
{
    if (rows != cols)
    {
        printf("A matriz nao e quadrada, nao ha diagonal principal.\n");
        return;
    }

    printf("-- Valores Acima da Diagonal Principal --\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = i + 1; j < cols; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf(" ");
        printf("\n");
    }
}

void printDiagonalSecundaria(int matrix[MAX][MAX], int rows, int cols)
{
    if (rows != cols)
    {
        printf("A matriz nao e quadrada, nao ha diagonal secundaria.\n");
        return;
    }

    printf("-- Diagonal Secundaria --\n");
    for (int i = 0; i < rows; i++)
    {
        printf("%d ", matrix[i][cols - 1 - i]);
    }
    printf("\n");
}

void printMatrix(int matrix[MAX][MAX], int rows, int cols)
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void writeMatrixToFile(int matrix[MAX][MAX], int rows, int cols, const char *fileName)
{
    FILE *arquivo = fopen(fileName, "w");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fprintf(arquivo, "%d %d\n", rows, cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            fprintf(arquivo, "%d ", matrix[i][j]);
        }
        fprintf(arquivo, "\n");
    }

    fclose(arquivo);
    printf("Matriz gravada em %s com sucesso.\n", fileName);
}

void readMatrixFromFile(int matrix[MAX][MAX], int *rows, int *cols, const char *fileName)
{
    FILE *arquivo = fopen(fileName, "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fscanf(arquivo, "%d %d", rows, cols);

    for (int i = 0; i < *rows; i++)
    {
        for (int j = 0; j < *cols; j++)
        {
            fscanf(arquivo, "%d", &matrix[i][j]);
        }
    }

    fclose(arquivo);
    printf("Matriz lida do arquivo %s com sucesso.\n", fileName);
}

void readMatrixFile()
{
    int newMatrix[MAX][MAX], newRows, newCols;
    readMatrixFromFile(newMatrix, &newRows, &newCols, "matriz.txt");

    printf("\n-- Matrix lida do arquivo --\n");
    printMatrix(newMatrix, newRows, newCols);

    Encerrar();
}

void Method_0911()
{
    int matrix[MAX][MAX], rows, cols;

    readMatrix(matrix, &rows, &cols);
    printf("\n-- Matrix --\n");
    printMatrix(matrix, rows, cols);

    Encerrar();
}

void Method_0912()
{
    int matrix[MAX][MAX], rows, cols;

    readMatrix(matrix, &rows, &cols);
    printf("\n-- Matrix --\n");
    printMatrix(matrix, rows, cols);

    const char *fileName = "matriz.txt";
    writeMatrixToFile(matrix, rows, cols, fileName);

    readMatrixFile();
}

void Method_0913()
{
    int matrix[MAX][MAX], rows, cols;
    readMatrix(matrix, &rows, &cols);
    printf("\n-- Matrix --\n");
    printMatrix(matrix, rows, cols);

    printDiagonalPrincipal(matrix, rows, cols);

    Encerrar();
}

void Method_0914()
{
    int matrix[MAX][MAX], rows, cols;

    readMatrix(matrix, &rows, &cols);
    printf("\n-- Matrix --\n");
    printMatrix(matrix, rows, cols);

    printDiagonalSecundaria(matrix, rows, cols);

    Encerrar();
}

void Method_0915()
{
    int matrix[MAX][MAX], rows, cols;
    readMatrix(matrix, &rows, &cols);
    printf("\n-- Matrix --\n");
    printMatrix(matrix, rows, cols);

    printAbaixoDiagonalPrincipal(matrix, rows, cols);

    Encerrar();
}

void Method_0916()
{
    int matrix[MAX][MAX], rows, cols;
    readMatrix(matrix, &rows, &cols);
    printf("\n-- Matrix --\n");
    printMatrix(matrix, rows, cols);

    printAcimaDiagonalPrincipal(matrix, rows, cols);

    Encerrar();
}

int main()
{
    int escolha;
    do
    {
        printf("\nEscolha uma opcao:\n");
        printf("1. Ler e printar matriz positiva\n");
        printf("2. Gravar matriz em arquivo e ler\n");
        printf("3. Printar matriz do arquivo\n");
        printf("4. Ler matriz e printar valores da diagonal principal\n");
        printf("5. Ler matriz e printar valores da diagonal secundaria\n");
        printf("6. Ler matriz e printar valores abaixo da diagonal secundaria\n");
        printf("7. Ler matriz e printar valores acima da diagonal secundaria\n");
        printf("\n0. Sair\n");
        printf("Opcao: ");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            Method_0911();
            break;
        case 2:
            Method_0912();
            break;
        case 3:
            readMatrixFile();
            break;
        case 4:
            Method_0913();
            break;
        case 5:
            Method_0914();
            break;
        case 6:
            Method_0915();
            break;
        case 7:
            Method_0916();
            break;
        case 0:
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
        }
    } while (escolha != 0);

    Encerrar();

    return 0;
}
