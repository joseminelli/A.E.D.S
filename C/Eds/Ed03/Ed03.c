/*
 Exemplo0300 - v0.0. - __ / __ / _____
 Author: ________________________
*/
// dependencias
#include "io.h" // para definicoes proprias
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

/*
 Funcao principal.
 @return codigo de encerramento
*/
int main()
{
    // definir dado
    int x = 0;
    // repetir até desejar parar
    do
    {
        // identificar
        IO_id("EXEMPLO0300 - Programa - v0.0");
        // ler do teclado
        IO_println("Opcoes");
        IO_println("0 - parar");
        IO_println("1 - repeticao com teste no inicio 1");
        IO_println("2 - repeticao com teste no inicio 2");
        IO_println("3 - repeticao com teste no inicio 3");
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
        default:
            IO_pause(IO_concat("Valor diferente das opcoes [0 ... 2] (",
                               IO_concat(IO_toString_d(x), ")")));
        } // end switch
    } while (x != 0);
    // encerrar
    IO_pause("Apertar ENTER para terminar");
    return (0);
} // end main ( )