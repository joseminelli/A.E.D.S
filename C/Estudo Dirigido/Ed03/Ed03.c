/*
 Exemplo0300 - v0.0. - __ / __ / _____
 Author: ________________________
*/
// dependencias
#include "io.h" // para definicoes proprias
#define STR_SIZE 20
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
void method_01(void)
{
    // definir dado
    int x = 0;
    // identificar
    IO_id("Method_01 - v0.0");
    // ler do teclado o valor inicial
    x = IO_readint("Entrar com uma quantidade: ");
    // repetir (x) vezes
    while (x > 0)
    {
        // mostrar valor atual
        IO_println(IO_toString_d(x));
        // passar ao proximo valor
        x = x - 1;
    } // end while
      // encerrar
    getchar();
    IO_pause("Apertar ENTER para continuar");
} // end method_01 ( )
/**
 Method_02 - Repeticao com teste no inicio.
*/
void method_02(void)
{
    // definir dado
    int x = 0;
    int y = 0;
    // identificar
    IO_id("Method_02 - v0.0");
    // ler do teclado
    x = IO_readint("Entrar com uma quantidade: ");
    // repetir (x) vezes
    y = x; // copiar o valor lido (e' melhor)
    while (y > 0)
    {
        // mostrar valor atual
        IO_println(IO_toString_d(y));
        // passar ao proximo valor
        y = y - 1;
    } // end while
      // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end method_02 ( )

/**
 Method_03 - Repeticao com teste no inicio.
*/
void method_03(void)
{
    // definir dado
    int x = 0;
    int y = 0;
    // identificar
    IO_id("Method_03 - v0.0");
    // ler do teclado
    x = IO_readint("Entrar com uma quantidade: ");
    // repetir (x) vezes
    y = 1; // o valor lido devera' ser preservado
    while (y <= x)
    {
        // mostrar valor atual
        IO_printf("%d\n", y);
        // passar ao proximo valor
        y = y + 1;
    } // end while
      // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end method_03 ( )

/**
 Method_04 - Repeticao com teste no inicio e variacao.
*/
void method_04(void)
{
    // definir dado
    int x = 0;
    int y = 0;
    int z = 0;
    // identificar
    IO_id("Method_04 - v0.0");
    // ler do teclado
    x = IO_readint("Entrar com uma quantidade: ");
    // repetir (x) vezes
    // inicio teste variacao
    for (y = 1; y <= x; y = y + 1)
    {
        // ler valor do teclado
        z = IO_readint("Valor = ");
        // mostrar valor atual
        IO_printf("%d. %d\n", y, z);
    } // end for
      // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end method_04 ( )

/*
Method_05 - Repeticao com teste no inicio e variacao.
 */
void method_05(void)
{
    // definir dado
    int x = 0;
    int y = 0;
    int z = 0;
    // identificar
    IO_id("Method_05 - v0.0");
    // ler do teclado
    x = IO_readint("Entrar com uma quantidade: ");
    // repetir (x) vezes
    // inicio teste variacao
    for (y = x; y >= 1; y = y - 1)
    {
        // ler valor do teclado
        z = IO_readint("Valor = ");
        // mostrar valor atual
        IO_printf("%d. %d\n", y, z);
    } // end for
      // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end method_05 ( )
/**
 Method_06 - Repeticao sobre cadeia de caracateres.
*/
void method_06(void)
{
    // definir dado
    int x = 0;
    int y = 0;

    chars palavra = IO_new_chars(STR_SIZE);
    int tamanho = 0;
    // identificar
    IO_id("Method_06 - v0.0");
    // ler do teclado
    palavra = IO_readstring("Entrar com uma palavra: ");
    // repetir para cada letra
    tamanho = strlen(palavra) - 1;
    // OBS: A cadeia de caracteres iniciam suas posições em zero.
    // inicio teste variacao
    for (y = tamanho; y >= 0; y = y - 1)
    {
        // mostrar valor atual
        IO_printf("%d: [%c]\n", y, palavra[y]);
    } // end for
      // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end method_06 ( )

/**
 Method_07 - Repeticao sobre cadeia de caracateres.
*/
void method_07(void)
{
    // definir dado
    int x = 0;
    int y = 0;

    char palavra[STR_SIZE];
    int tamanho = 0;
    // identificar
    IO_id("Method07 - v0.0");
    // ler do teclado
    IO_printf("Entrar com uma palavra: ");
    scanf("%s", palavra);
    getchar();
    // OBS: A cadeia de caracteres dispensa a indicacao de endereco (&) na leitura.
    // repetir para cada letra
    tamanho = strlen(palavra);
    // OBS: A cadeia de caracteres iniciam suas posições em zero.
    // inicio teste variacao
    for (y = 0; y < tamanho; y = y + 1)
    {
        // mostrar valor atual
        IO_printf("%d: [%c]\n", y, palavra[y]);
    } // end for
      // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end method_07 ( )

/**
 Method_08 - Repeticao com intervalos.
*/
void method_08(void)
{
    // definir dado
    int inferior = 0;
    int superior = 0;
    int x = 0;
    // identificar
    IO_id("Method08 - v0.0");
    // ler do teclado
    inferior = IO_readint("Limite inferior do intervalo: ");
    superior = IO_readint("Limite superior do intervalo : ");
    // inicio teste variacao
    for (x = inferior; x <= superior; x = x + 1)
    {
        // mostrar valor atual
        IO_printf("%d\n", x);
    } // end for
      // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end method_08 ( )

/**
 Method_09 - Repeticao com intervalos.
*/
void method_09(void)
{
    // definir dado
    double inferior = 0;
    double superior = 0;
    double passo = 0;
    double x = 0;
    // identificar
    IO_id("Method_09 - v0.0");
    // ler do teclado
    inferior = IO_readdouble("Limite inferior do intervalo : ");
    superior = IO_readdouble("Limite superior do intervalo : ");
    passo = IO_readdouble("Variacao no intervalo (passo): ");
    // inicio teste variacao
    for (x = superior; x >= inferior; x = x - passo)
    {
        // mostrar valor atual
        IO_printf("%lf\n", x);
    } // end for
      // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end method_09 ( )

/**
 Method_10 - Repeticao com confirmacao.
*/
void method_10(void)
{
    // definir dado
    double inferior = 0;
    double superior = 0;
    double passo = 0;
    double x = 0;
    // identificar
    IO_id("Method10 - v0.0");
    // ler do teclado
    inferior = IO_readdouble("Limite inferior do intervalo : ");
    // repetir ate' haver confirmacao de validade
    do
    {
        superior = IO_readdouble("Limite superior do intervalo: ");
    } while (inferior >= superior);
    // repetir ate' haver confirmacao de validade
    do
    {
        passo = IO_readdouble("Variacao no intervalo (passo): ");
    } while (passo <= 0.0);
    // inicio teste variacao
    for (x = inferior; x <= superior; x = x + passo)
    {
        // mostrar valor atual
        IO_printf("%lf\n", x);
    } // end for
      // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end method_10 ( )

/**
 Method_11 - Ler uma palavra e mostrar as letras maiúsculas.
*/
void method_11(void)
{
    // Definir uma variável para armazenar a palavra
    char palavra[STR_SIZE];

    // Identificar o método
    IO_id("Method_11 - v0.0");

    // Ler uma palavra do teclado
    IO_printf("Digite uma palavra: ");
    scanf("%s", palavra);

    // Mostrar as letras maiúsculas
    int i = 0;
    IO_printf("Letras maiusculas na palavra: ");
    while (palavra[i] != '\0')
    {
        if (palavra[i] >= 'A' && palavra[i] <= 'Z')
        {
            IO_printf("%c ", palavra[i]);
        }
        i++;
    }
    IO_printf("\n");
    // Encerrar
    getchar();
    IO_pause("Aperte ENTER para continuar");
} // end method_11()

/**
 Method_12 - Ler uma palavra e contar/mostrar as letras maiúsculas.
*/
void method_12(void)
{
    // Definir uma variável para armazenar a palavra
    char palavra[STR_SIZE];

    // Identificar o método
    IO_id("Method_12 - v0.0");

    // Ler uma palavra do teclado
    IO_printf("Digite uma palavra: ");
    scanf("%s", palavra);

    // Contar e mostrar as letras maiúsculas
    int i = 0;
    int contador = 0;
    IO_printf("Letras maiusculas na palavra: ");
    while (palavra[i] != '\0')
    {
        if (palavra[i] >= 'A' && palavra[i] <= 'Z')
        {
            IO_printf("%c ", palavra[i]);
            contador++;
        }
        i++;
    }
    IO_printf("\nTotal de letras maiusculas: %d\n", contador);

    // Encerrar
    getchar();
    IO_pause("Aperte ENTER para continuar");
} // end method_12()

/**
 Method_13 - Ler uma palavra e contar/mostrar as letras maiúsculas percorrendo do fim para o início da palavra.
*/
void method_13(void)
{
    // Definir uma variável para armazenar a palavra
    char palavra[STR_SIZE];

    // Identificar o método
    IO_id("Method_13 - v0.0");

    // Ler uma palavra do teclado
    IO_printf("Digite uma palavra: ");
    scanf("%s", palavra);

    // Contar e mostrar as letras maiúsculas
    int i = strlen(palavra) - 1;
    int contador = 0;
    IO_printf("Letras maiusculas na palavra: ");
    while (palavra[i] != '\0')
    {
        if (palavra[i] >= 'A' && palavra[i] <= 'Z')
        {
            IO_printf("%c ", palavra[i]);
            contador++;
        }
        i--;
    }
    IO_printf("\nTotal de letras maiusculas: %d\n", contador);

    // Encerrar
    getchar();
    IO_pause("Aperte ENTER para continuar");
} // end method_13()

/**
 Method_14 - Ler uma palavra e contar/mostrar todos os simboos que forem letras
*/
void method_14(void)
{
    // Definir uma variável para armazenar a palavra
    char palavra[STR_SIZE];

    // Identificar o método
    IO_id("Method_14 - v0.0");

    // Ler uma palavra do teclado
    IO_printf("Digite uma palavra: ");
    scanf("%s", palavra);

    // Contar e mostrar as letras maiúsculas
    int i = 0;
    int contador = 0;
    IO_printf("Letras na palavra: ");
    while (palavra[i] != '\0')
    {
        if (palavra[i] >= 'A' && palavra[i] <= 'Z' || palavra[i] >= 'a' && palavra[i] <= 'z')
        {
            IO_printf("%c ", palavra[i]);
            contador++;
        }
        i++;
    }
    IO_printf("\nTotal de letras: %d\n", contador);

    // Encerrar
    getchar();
    IO_pause("Aperte ENTER para continuar");
} // end method_14()

/**
 Method_15 - Ler uma palavra e contar/mostrar todos os digitos percorrendo do início para o fim da palavra.
*/
void method_15(void)
{
    // Definir uma variável para armazenar a palavra
    char palavra[STR_SIZE];

    // Identificar o método
    IO_id("Method_15 - v0.0");

    // Ler uma palavra do teclado
    IO_printf("Digite uma palavra: ");
    scanf("%s", palavra);

    // Contar e mostrar as letras maiúsculas
    int i = strlen(palavra) - 1;
    int contador = 0;
    IO_printf("digitos na palavra: ");
    while (palavra[i] != '\0')
    {
        if (palavra[i] >= '1' && palavra[i] <= '9')
        {
            IO_printf("%c ", palavra[i]);
            contador++;
        }
        i--;
    }
    IO_printf("\nTotal de letras digitos: %d\n", contador);

    // Encerrar
    getchar();
    IO_pause("Aperte ENTER para continuar");
} // end method_15()

/**
 Method_16 - Ler uma palavra e contar/mostrar tudo que não for digito ou letra percorrendo do fim para o inicio da palavra.
*/
void method_16(void)
{
    // Definir uma variável para armazenar a palavra
    char palavra[STR_SIZE];

    // Identificar o método
    IO_id("Method_15 - v0.0");

    // Ler uma palavra do teclado
    IO_printf("Digite uma palavra: ");
    scanf("%s", palavra);

    // Contar e mostrar as letras maiúsculas
    int i = strlen(palavra) - 1;
    int contador = 0;
    IO_printf("digitos na palavra: ");
    while (palavra[i] != '\0')
    {
        if (!(palavra[i] >= '1' && palavra[i] <= '9') && !(palavra[i] >= 'A' && palavra[i] <= 'Z') && !(palavra[i] >= 'a' && palavra[i] <= 'z'))
        {
            IO_printf("%c ", palavra[i]);
            contador++;
        }
        i--;
    }
    IO_printf("\nTotal de letras digitos: %d\n", contador);

    // Encerrar
    getchar();
    IO_pause("Aperte ENTER para continuar");
} // end method_1()

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
        IO_println("1 - repeticao com teste no inicio 1");
        IO_println("2 - repeticao com teste no inicio 2");
        IO_println("3 - repeticao com teste no inicio 3");
        IO_println("4 - repeticao com teste no inicio e variacao");
        IO_println("5 - repeticao com teste no inicio e variacao 2");
        IO_println("6 - repeticao sobre cadeia de caracateres.");
        IO_println("7 - repeticao sobre cadeia de caracateres 2");
        IO_println("8 - repeticao com intervalos");
        IO_println("9 - repeticao com intervalos 2");
        IO_println("10 - repeticao com confirmacao");
        IO_println("11 - ler uma palavra e mostrar as letras maiusculas");
        IO_println("12 - ler uma palavra e contar/mostrar as letras maiusculas");
        IO_println("13 - ler uma palavra e contar/mostrar as letras maiusculas 2");
        IO_println("14 - ler uma palavra e contar/mostrar as letras");
        IO_println("15 - ler uma palavra e contar/mostrar as digitos");
        IO_println("16 - ler uma palavra e contar/mostrar os caracteres que não são digitos ou letras");

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
        case 7:
            method_07();
            break;
        case 8:
            method_08();
            break;
        case 9:
            method_09();
            break;
        case 10:
            method_10();
            break;
        case 11:
            method_11();
            break;
        case 12:
            method_12();
            break;
        case 13:
            method_13();
            break;
        case 14:
            method_14();
            break;
        case 15:
            method_15();
            break;
        case 16:
            method_16();
            break;
        default:
            IO_pause(IO_concat("Valor diferente das opcoes [0 ... 3] (", IO_concat(IO_toString_d(x), ")")));
        } // end switch
    } while (x != 0);
    // encerrar
    IO_pause("Apertar ENTER para terminar");
    return (0);
} // end main ( )