/*
 Exemplo0300 - v0.0. - __ / __ / _____
 Author: ________________________
*/
// dependencias
#include "io.h" // para definicoes proprias
#include <ctype.h>
#define STR_SIZE 100 

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

int contarLetrasMaiusculas(char sequencia[]) {
    int count = 0;
    for (int i = 0; sequencia[i] != '\0'; i++) {
        if (isalpha(sequencia[i]) && sequencia[i] > 'K') {
            count++;
        }
    }
    return count;
}

bool ehMaiuscula(char letra) {
    return letra >= 'K' && letra <= 'Z';
}

bool ehDigitoImpar(char caractere) {
    int digito = caractere - '0';
    return (digito >= 1 && digito <= 9 && digito % 2 != 0);
}

bool ehAlfanumerico(char caractere) {
    return isalnum(caractere) != 0;
}

int contarDigitosImpares(char sequencia[]) {
    int count = 0;
    for (int i = 0; sequencia[i] != '\0'; i++) {
        if (isdigit(sequencia[i]) && ehDigitoImpar(sequencia[i])) {
            count++;
        }
    }
    return count;
}

void listarSimbolos(char sequencia[], int opcao) {
    if(opcao ==1){
        IO_println("Símbolos não alfanuméricos na sequência:");
        for (int i = 0; sequencia[i] != '\0'; i++) {
            if (!ehAlfanumerico(sequencia[i])) {
                printf("%c ", sequencia[i]);
            }
        }
        printf("\n");
    } else if(opcao ==2){
        IO_println("Símbolos alfanuméricos na sequência:");
        for (int i = 0; sequencia[i] != '\0'; i++) {
            if (ehAlfanumerico(sequencia[i])) {
                printf("%c ", sequencia[i]);
            }
        }
        printf("\n");
    }
}

/**
 Method_00 - nao faz nada.
*/
void method_00(void)
{
    // nao faz nada
} // end method_00 ( )
/**
 Method_01 - Repeticao com teste no inicio.
*/
void method_01(void){
    // definir dado
    int x, y, z, dentro, fora;
    // identificar
    IO_id("Method_01 - v0.0");
    // ler do teclado o valor inicial
    printf("defina seu intervalo('10 20')\n");
    scanf("%d %d", &x, &y); 
    
    do{
        printf("Digite um numero(para parar digite 0)\n");
        scanf("%d", &z); 
        if(z != 0){
            if(z > x && z < y || z > y && z < x){
                dentro++;
            }else{
                fora++;
            }
        }
    }while(z != 0);
    
    printf("A quantidade de numeros dentro do intervalo foi de %d, e fora foi %d", dentro,fora);
    // encerrar
    Encerrar();
} // end method_01 ( )

void method_02() {
    IO_id("Method_02 - Contar letras maiusculas maiores que 'K'");
    char sequencia[STR_SIZE];
    
    printf("Digite uma sequência de caracteres: ");
    fgets(sequencia, STR_SIZE, stdin);

    int count = 0;

    for (int i = 0; sequencia[i] != '\0'; i++) {
        if (ehMaiuscula(sequencia[i])) {
            count++;
        }
    }

    printf("Quantidade de letras maiusculas maiores que 'K': %d\n", count);

    Encerrar();
}

void method_03() {
    IO_id("method_03 - Contar letras maiores que 'K' e 'k'");
    char sequencia[STR_SIZE];
    
    printf("Digite uma sequência de caracteres: ");
    fgets(sequencia, STR_SIZE, stdin);

    int count = contarLetrasMaiusculas(sequencia);

    printf("Quantidade de letras maiusculas e minusculas maiores que 'K' e 'k': %d\n", count);

    Encerrar();
}

void method_04() {
    IO_id("method_04 - Contar dígitos ímpares em uma sequência de caracteres");
    char sequencia[STR_SIZE];
    
    printf("Digite uma sequência de caracteres: ");
    fgets(sequencia, STR_SIZE, stdin);

    int count = contarDigitosImpares(sequencia);

    printf("Quantidade de dígitos ímpares na sequência: %d\n", count);

    Encerrar();
}

void method_05() {
    IO_id("method_05 - Listar símbolos não alfanuméricos em uma sequência de caracteres");
    char sequencia[STR_SIZE];
    
    printf("Digite uma sequência de caracteres: ");
    fgets(sequencia, STR_SIZE, stdin);

    listarSimbolos(sequencia, 1);

    Encerrar();
}

void method_06() {
    IO_id("method_06 - Listar símbolos alfanuméricos em uma sequência de caracteres");
    char sequencia[STR_SIZE];
    
    printf("Digite uma sequência de caracteres: ");
    fgets(sequencia, STR_SIZE, stdin);

    listarSimbolos(sequencia, 2);

    Encerrar();
}
/*
 Funcao principal.
 @return codigo de encerramento
*/
int main()
{
    IO_trace = false;
    // definir dado
    int x = 0;
    // repetir até desejar parar
    do
    {
        // identificar
        IO_id("\nEXEMPLO0300 - Programa - v0.0");
        // ler do teclado
        IO_println("Opcoes");
        IO_println("0 - parar");
        IO_println("1 - contar valores dentro e fora de um intervalo");
        IO_println("2 - contar letras maiusculas maiores que 'K'");
        IO_println("3 - contar letras maiores que 'K' e 'k'");
        IO_println("4 - contar dígitos ímpares na sequência");
        IO_println("5 - listar símbolos não alfanuméricos");
        IO_println("6 - listar símbolos alfanuméricos");

        IO_println("");
        x = IO_readint("Entrar com uma opcao: ");
        // testar valor
        switch (x)
        {
        case 0:
            method_00();
            break;
        case 1:
            method_01();
            break;
        case 2:
            method_02();
            break;
        case 3:
            method_03();
            break;
        case 4:
            method_04();
            break;
        case 5:
            method_05();
            break;
        case 6:
            method_06();
            break;
        default:
            IO_pause(IO_concat("Valor diferente das opcoes [0 ... 10] (", IO_concat(IO_toString_d(x), ")")));
        } // end switch
    } while (x != 0);
    // encerrar
    IO_pause("Apertar ENTER para terminar");
    return (0);
} // end main ( )