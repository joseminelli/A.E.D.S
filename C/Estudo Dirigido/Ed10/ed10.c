#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "JMRL.h"

#define MAX 100

int* readArrayFromFile(const char* fileName, int* size) {
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        *size = 0; 
        return NULL;
    }

    int* numeros = NULL;
    int capacidade = 10;
    int count = 0;
    int numero;

    numeros = (int*)malloc(capacidade * sizeof(int));

    while (fscanf(file, "%d", &numero) != EOF) {
        numeros[count] = numero;
        count++;

        if (count >= capacidade) {
            capacidade *= 2;
            numeros = (int*)realloc(numeros, capacidade * sizeof(int));
        }
    }

    fclose(file);
    *size = count; 
    
    return numeros;
}

int arraySearch(int valor, int arranjo[], int tamanho) {
    int resposta; 
    int  encontrou = 0;
    for (int i = 0; i < tamanho; i++) {
        if (valor == arranjo[i]) {
            resposta = arranjo[i];
            encontrou = 1;
        Print("O Numero foi encontrado");
            return resposta;
        }
    }
    if(encontrou == 0){
        Print("O Numero NAO foi encontrado");
    }
}

int arrayCompare(int arranjo1[], int arranjo2[], int tamanho1, int tamanho2) {
    printf("%d %d ", tamanho1, tamanho2);
    
    if (tamanho1 == tamanho2) {
        printf("Os arranjos têm o mesmo tamanho\n");

        for (int i = 0; i < tamanho1; i++) {
            if (arranjo1[i] != arranjo2[i]) {
                printf("\nOs arranjos são diferentes\n");
                return 2;
            }
        }

        printf("Os arranjos são iguais\n");
        return 1;
    } else {
        printf("Os arranjos têm tamanhos diferentes\n");
        return 0;
    }
}

int* arrayAdd(int arranjo1[], int constante, int arranjo2[], int tamanho) {
    int* novoArranjo = (int*)malloc(tamanho * sizeof(int));
    if (novoArranjo == NULL) {
        printf("Erro de alocação de memória\n");
        exit(1);
    }

    for (int i = 0; i < tamanho; i++) {
        novoArranjo[i] = arranjo1[i] + (constante * arranjo2[i]);
    }

    return novoArranjo;
}

int isArrayDecrescent(int arranjo[], int tamanho) {
    for (int i = 1; i < tamanho; i++) {
        if (arranjo[i] > arranjo[i - 1]) {
            return 1;
        }
    }
    return 0;
}

int matrixZero(int **matriz, int numRows, int numCols) {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (i == 0) {
                continue;
            }
            if (matriz[i][j] != 0) {
                return 1;
            }
        }
    }
    return 0;
}


void generateMatrix() {
     int min = Readint("Digite o valor mínimo: ");
    int max = Readint("Digite o valor máximo: ");
    int rows, cols;
    const char* fileName;

    do {
        rows = Readint("Digite o número de linhas da matriz: ");
    } while (rows < 1 || rows > MAX);

    do {
        cols = Readint("Digite o número de colunas da matriz: ");
    } while (cols < 1 || cols > MAX);

    do {
        int arq = Readint("Qual arquivo deseja escrever?\n1 - DADOS.TXT\n2 - DADOS2.txt\n\nOpção: ");
        if (arq == 1) {
            fileName = "DADOS.TXT";
        } else if (arq == 2) {
            fileName = "DADOS2.txt";
        }
    } while (fileName == NULL);
    
    int matriz[MAX][MAX];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matriz[i][j] = NumeroAleatorio(min, max);
        }
    }

    FILE* arquivo = fopen(fileName, "wt");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fprintf(arquivo, "%d %d\n", rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(arquivo, "%d ", matriz[i][j]);
        }
        fprintf(arquivo, "\n");
    }

    fclose(arquivo);
    printf("\nMatriz gerada e gravada com sucesso em %s.\n", fileName);
}

#include <stdio.h>
#include <stdlib.h>

int** readMatrixFromFile(const char* fileName, int* numRows, int* numCols) {
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        *numRows = 0;
        *numCols = 0;
        return NULL;
    }

    int** matriz = NULL;
    int rows, cols;
    int count = 0;

    if (fscanf(file, "%d %d", &rows, &cols) != 2) {
        printf("Erro ao ler as dimensões da matriz no arquivo.\n");
        *numRows = 0;
        *numCols = 0;
        return NULL;
    }

    matriz = (int**)malloc(rows * sizeof(int*));

    for (int i = 0; i < rows; i++) {
        matriz[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            if (fscanf(file, "%d", &matriz[i][j]) != 1) {
                printf("Erro ao ler os elementos da matriz no arquivo.\n");
                *numRows = 0;
                *numCols = 0;
                return NULL;
            }
        }
    }

    fclose(file);
    *numRows = rows;
    *numCols = cols;

    return matriz;
}

int matrixCompare(int** matriz1, int** matriz2, int numRows1, int numCols1, int numRows2, int numCols2) {
    if (numRows1 != numRows2 || numCols1 != numCols2) {
        return 0;
    }

    for (int i = 0; i < numRows1; i++) {
        for (int j = 0; j < numCols1; j++) {
            if (matriz1[i][j] != matriz2[i][j]) {
                return 0; 
            }
        }
    }

    return 1;
}

void freeMatrix(int** matriz, int numRows) {
    for (int i = 0; i < numRows; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

void Method_01(){
    int min = Readint("Digite o valor mínimo: ");
    int max = Readint("Digite o valor máximo: ");
    int numeros[MAX];
    int quantidade, arq;
    FILE *arquivo;
    
    do{
        quantidade = Readint("Quantos números quer gerar? ");
    } while (quantidade > 100 || quantidade < 1);
        
    for(int i = 0; i < quantidade; i++){
        numeros[i] = NumeroAleatorio(min, max);
    }
    do{
      arq = Readint("Qual arquivo deseja escrever? \n 1 - DADOS.txt \n 2 - DADOS2.txt\n\n Opção: ");
    } while (arq < 1 || arq > 2);
    if(arq == 1){
         arquivo = fopen("DADOS.TXT", "wt");
    } else {
         arquivo = fopen("DADOS2.txt", "wt");
    }
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    
    fprintf(arquivo, "%d\n", quantidade);
    
    for(int i = 0; i < quantidade; i++){
        fprintf(arquivo, "%d\n", numeros[i]);
    }
    fclose(arquivo);
    printf("\nNúmeros gerados e gravados com sucesso em DADOS.TXT.\n");
    
}

void Method_02(){
     int tamanho;
    int* arranjo = readArrayFromFile("DADOS.TXT", &tamanho);
    if (arranjo == NULL) {
        return;
    }
    int valor = Readint("Digite um valor para procurar no arranjo: ");
    int resposta = arraySearch(valor, arranjo, tamanho);
    
    free(arranjo);
}

void Method_03(){
    int tamanho, tamanho2;
    int* arranjo = readArrayFromFile("DADOS.TXT", &tamanho);
    int* arranjo2 = readArrayFromFile("DADOS2.txt", &tamanho2);
    
    if (arranjo == NULL || arranjo2 == NULL) {
        return;
    }

    arrayCompare(arranjo, arranjo2, tamanho, tamanho2);
    free(arranjo);
    free(arranjo2);
}

void Method_04() {
    int tamanho, tamanho2;
    int* arranjo = readArrayFromFile("DADOS.TXT", &tamanho);
    int* arranjo2 = readArrayFromFile("DADOS2.txt", &tamanho2);
    int constante = 1;

    if (arranjo == NULL || arranjo2 == NULL) {
        return;
    }

    int compativel = arrayCompare(arranjo, arranjo2, tamanho, tamanho2);

    if (compativel == 1 || compativel == 2) {
        int* resultado = arrayAdd(arranjo, constante, arranjo2, tamanho);
        printf("\nNovo array:\n");
        for (int i = 0; i < tamanho; i++) {
            printf("%d\n", resultado[i]);
        }

        free(resultado);
    }
}

void Method_05(){
    int arq, tamanho;
    int *arquivo;
    
    do{
      arq = Readint("Qual arquivo deseja escrever? \n 1 - DADOS.txt \n 2 - DADOS2.txt\n\n Opção: ");
    } while (arq < 1 || arq > 2);
    if(arq == 1){
        arquivo = readArrayFromFile("DADOS.TXT", &tamanho);
    } else {
        arquivo = readArrayFromFile("DADOS2.txt", &tamanho);
    }
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    
    int decrescente = isArrayDecrescent(arquivo, tamanho);
    
    if (decrescente == 0) {
        printf("O arranjo está em ordem decrescente.\n");
    } else {
        printf("O arranjo NÃO está em ordem decrescente.\n");
    }

    
}


void Method_07(){
  
    int arq, numRows, numCols;
    int **arquivo;
    
    do{
      arq = Readint("Qual arquivo deseja ler? \n 1 - DADOS.txt \n 2 - DADOS2.txt\n\n Opção: ");
    } while (arq < 1 || arq > 2);
    if(arq == 1){
        arquivo = readMatrixFromFile("DADOS.TXT", &numRows, &numCols);
    } else {
        arquivo = readMatrixFromFile("DADOS2.txt", &numRows, &numCols);
    }
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
   
    int resultado = matrixZero(arquivo, numRows, numCols);
    
    if (resultado == 0) {
        printf("A matriz só contém zeros.\n");
    } else {
        printf("A matriz contém números diversos.\n");
    }   
}

int Method_08() {
    int numRows1, numCols1;
    int numRows2, numCols2;

    int** matriz1 = readMatrixFromFile("DADOS.TXT", &numRows1, &numCols1);
    int** matriz2 = readMatrixFromFile("DADOS2.txt", &numRows2, &numCols2);

    if (matriz1 == NULL || matriz2 == NULL) {
        printf("Erro ao ler as matrizes do arquivo.\n");
        return 1;
    }

    int igualdade = matrixCompare(matriz1, matriz2, numRows1, numCols1, numRows2, numCols2);

    if (igualdade) {
        printf("As matrizes são iguais.\n");
    } else {
        printf("As matrizes são diferentes.\n");
    }

    freeMatrix(matriz1, numRows1);
    freeMatrix(matriz2, numRows2);

    return 0;
}

int main()
{
    int escolha;
    do
    {
        Print("\nEscolha uma opção:\n");
        Print("1. Gerar numeros aleatorios e gravar num arquivo\n");
        Print("2. Ler numeros do arquivo por retorno de array\n");
        Print("3. Comparar os arrays\n");
        Print("4. Somar dois arrays\n");
        Print("5. Ver se o array está em ordem decrescente\n");
        Print("6. Gerar matriz e salvar num arquivo\n");
        Print("7. Ver se a matrix só contém zeros\n");
        Print("8. Comparar matrizes\n");
        Print("\n0. Sair\n");
        escolha = Readint("Escolha uma opção: ");

        switch (escolha)
        {
        case 1:
            Method_01();
            Encerrar();
            break;
        case 2:
            Method_02();
            Encerrar();
            break;
        case 3:
            Method_03();
            Encerrar();
            break;
        case 4:
            Method_04();
            Encerrar();
            break;
        case 5:
            Method_05();
            Encerrar();
        case 6:
            generateMatrix();
            Encerrar();
            break;
        case 7:
            Method_07();
            Encerrar();
            break;
        case 8:
            Method_08();
            Encerrar();
            break;
        case 0:
            break;
        default:
            Print("Opção inválida. Tente novamente.\n");
        }
    } while (escolha != 0);

    Encerrar();

    return 0;
}
