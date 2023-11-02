/**
   JMRL - Biblioteca de funcoes para uso geral
   @author  José Minelli
   @version 1.0 23/10/2023

 */
// ---------------------- lista de dependencias

#include <stdio.h>   // para entradas e saidas
#include <stddef.h>  // para definicoes basicas
#include <stdlib.h>  // para a biblioteca padrao
#include <string.h>  // para cadeias de caracteres
#include <stdarg.h>  // para tratar argumentos
#include <stdbool.h> // para definicoes logicas
#include <ctype.h>   // para tipos padroes
#include <math.h>    // para definicoes matematicas
#include <time.h>    // para medir tempo
#include <wchar.h>   // para 16-bit characters
#include <iso646.h>  // para and, or, xor, not alternatives

// ---------------------- redefinicoes para apontamentos

#ifndef __IO_REFS__
#define __IO_REFS__

#define nullptr NULL // para compatibilizar com C++
#define null NULL    // para generalizar

#define COLORS_H

#define addr(p) (&(p))  // para obter endereco
#define deref(p) (*(p)) // para obter conteudo de endereco
#define val(p) (*(p))   // para obter conteudo apontado

#define ref * // para passar parametro por referencia
              // (na assinatura)
#define var & // para passar parametro por referencia
              // (na chamada)

#endif

// ---------------------- redefinicoes uteis

#ifndef _IO_H_
#define _IO_H_
// alternativas mais seguras, se disponiveis
#define IO_printf printf   // melhor: printf_s
#define IO_scanf scanf     // melhor: scanf_s
#define IO_fprintf fprintf // melhor: fprintf_s
#define IO_fscanf fscanf   // melhor: fscanf_s

// ---------------------- definicoes de constantes

const char EOS = '\0';    // definir fim de cadeia de caracteres
const char EOL = '\n';    // definir mudanca de linha
const char ENDL[] = "\n"; // definir mudanca de linha

const char STR_EMPTY[] = ""; // definir cadeia de caracteres vazia
const int STR_SIZE = 80;     // definir tamanho padrao para caracteres

// ---------------------- definicoes de tipos

typedef char *chars;     // definir cadeia  de caracteres
typedef int *ints;       // definir arranjo de inteiros
typedef double *doubles; // definir arranjo de reais
typedef bool *bools;     // definir arranjo de logicos

// ---------------------- definicoes de variaveis globais

int IO_error = 0;     // inicialmente sem erros
bool IO_trace = true; // inicialmente habilitado

// ---------------------- definicoes de funcoes e procedimentos

// ---------------------- para tratamento de erros#ifndef COLORS_H

// Color.h (para uso em C++)
#ifdef __cplusplus
#include <iostream>
/**
 * Função para colorir o texto no terminal.
 * @param text texto a ser colorido
 * @param color_code código da cor a ser usada(colocada em Defines)
*/
void ColorText(const std::string& text, const std::string& color_code) {
    std::cout << color_code << text << "\e[m";
}
#endif

// Color.h (para uso em C)
#ifndef COLOR_H
#define COLOR_H

// Define macros for ANSI color codes
#define COLOR_OFF "\x1b[0m"

#define COLOR_GRAY "\x1b[30m"
#define COLOR_GRAYBG "\x1b[30;7m"
#define COLOR_GRAYSUB "\x1b[30;4m"

#define COLOR_RED "\x1b[31m"
#define COLOR_REDBG "\x1b[31;7m"
#define COLOR_REDSUB "\x1b[31;4m"

#define COLOR_GREEN "\x1b[32m"
#define COLOR_GREENBG "\x1b[32;7m"
#define COLOR_GREENSUB "\x1b[32;4m"

#define COLOR_YELLOW "\x1b[33m"
#define COLOR_YELLOWBG "\x1b[33;7m"
#define COLOR_YELLOWSUB "\x1b[33;4m"

#define COLOR_BLUE "\x1b[34m"
#define COLOR_BLUEBG "\x1b[34;7m"
#define COLOR_BLUESUB "\x1b[34;4m"

#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_MAGENTABG "\x1b[35;7m"
#define COLOR_MAGENTASUB "\x1b[35;4m"

#define COLOR_CYAN "\x1b[36m"
#define COLOR_CYANBG "\x1b[36;7m"
#define COLOR_CYANSUB "\x1b[36;4m"

#define COLOR_WHITE "\x1b[37m"
#define COLOR_WHITEBG "\x1b[37;7m"
#define COLOR_WHITESUB "\x1b[37;4m"

#define COLOR_ORANGE "\x1b[33m"
#define COLOR_ORANGEBG "\x1b[33;7m"
#define COLOR_ORANGESUB "\x1b[33;4m"

#define COLOR_PINK "\x1b[35m"
#define COLOR_PINKBG "\x1b[35;7m"
#define COLOR_PINKSUB "\x1b[35;4m"

/**
 * Função para colorir o texto no terminal.
 * @param text texto a ser colorido
 * @param color_code código da cor a ser usada(colocada em Defines)
*/
void ColorText(const char *text, const char *color_code) {
    printf("%s%s%s", color_code, text, COLOR_OFF);
}
#endif
//------------ para entradas e saidas

/**
    Metodo para limpar a entrada de dados padrao.
 */
void IO_flush()
{
    //  fflush ( stdin );   // para Windows - OBS: NAO RECOMENDADO !
    // para Linux   - OBS: NAO FUNCIONA    !
    int x = 0; // compat�vel com o retorno de getchar()
    do
    {
        x = getchar();
    } while (x != EOF && x != '\n');
    clearerr(stdin); // reiniciar o estado de EOF
} // end IO_flush ( )

/**
    Funcao para ler valor inteiro do teclado.
    @return valor lido
    @param  text - mensagem a ser exibida antes da leitura
 */
int Readint(const char *const text)
{
    int x = 0;
    if (IO_trace)
        IO_printf("%s", text);
    IO_scanf("%d", &x);
    IO_flush();
    return (x);
} // end IO_readint ( )

/**
    Funcao para ler valor real de precisao dupla do teclado.
    @return valor lido
    @param  text - mensagem a ser exibida antes da leitura
 */
double Readdouble(const char *const text)
{
    double x = 0.0;
    if (IO_trace)
        IO_printf("%s", text);
    IO_scanf("%lf", &x);
    IO_flush();
    return (x);
} // end IO_readdouble ( )

/**
    Funcao para ler valor real de precisao simples do teclado.
    @return valor lido
    @param  text - mensagem a ser exibida antes da leitura
 */
float Readfloat(const char *const text)
{
    float x = 0.0;
    if (IO_trace)
        IO_printf("%s", text);
    IO_scanf("%f", &x);
    IO_flush();
    return (x);
} // end IO_readfloat ( )

/**
    Funcao para ler valor logico do teclado.
    @return valor lido
    @param  text - mensagem a ser exibida antes da leitura
    OBS.:   Usar zero (0) para falso e
            diferente de zero para verdadeiro
 */
bool Readbool(const char *const text)
{
    int x = 0;
    if (IO_trace)
        IO_printf("%s", text);
    IO_scanf("%d", &x);
    IO_flush();
    return (x != 0);
} // end IO_readbool ( )

/**
    Funcao para ler caractere do teclado.
    @return valor lido
    @param  text - mensagem a ser exibida antes da leitura
 */
char Readchar(const char *const text)
{
    char x = '0';
    if (IO_trace)
        IO_printf("%s", text);
    do
    {
        x = getchar();
    } while ('\n' == x);
    IO_flush();
    //  getchar ( );
    return (x);
} // end IO_readchar ( )

void Encerrar(void)
{
    printf("\nPressione ENTER para continuar...");
    char x = '0';
    do
    {
        x = getchar();
    } while ('\n' != x);
    getchar();
}
void LimparTela()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

/**
    Funcao para reservar espaco para guardar cadeia de caracteres.
    @return area reservada, se houver; NULL, caso contrario
    @param size - quantidade de dados
 */
chars New_chars(int size)
{
    return ((chars)malloc((size + 1) * sizeof(char)));
} // fim New_chars ( )

/**
    Funcao para reservar espaco para guardar inteiros.
    @return area reservada, se houver; NULL, caso contrario
    @param size - quantidade de dados
 */
ints New_ints(int size)
{
    return ((ints)malloc((size) * sizeof(int)));
} // fim IO_new_ints ( )

/**
    Funcao para reservar espaco para guardar reais.
    @return area reservada, se houver; NULL, caso contrario
    @param size - quantidade de dados
 */
doubles New_doubles(int size)
{
    return ((doubles)malloc((size) * sizeof(double)));
} // fim IO_new_doubles ( )

/**
    Funcao para reservar espaco para guardar logicos.
    @return area reservada, se houver; NULL, caso contrario
    @param size - quantidade de dados
 */
bool New_bools(int size)
{
    return ((bools)malloc((size) * sizeof(bool)));
} // fim IO_new_bools ( )

/**
    Funcao para concatenar cadeias de caracteres.
    @return cadeia com o resultado
    @param text1 - primeira cadeia
    @param text2 - segunda  cadeia
 */
#ifdef __cplusplus
#include <locale>
void SetLocale(const std::string local)
{
    std::locale::global(std::locale(local));
}
void Print(const std::string &text)
{
    std::cout << text;
}
void Println(const std::string &text)
{
    std::cout << text << std::endl;
    //  puts ( text ); putchar ( '\n' );
} // fim IO_println ( )
int Length(const std::string &text)
{
    return (text.length());
} // fim IO_length ( )

std::string Substring(const std::string& text, int start, unsigned int size) {
    if (start >= 0 && static_cast<size_t>(start + size) <= text.length()) {
        return text.substr(start, size);
    } else {
        return "";
    }
}
/**
    Funcao para juntar 2 textos.
    @return juncao das cadeias de caracteres ou
    @param  text1  - cadeia de caracteres 1
    @param  text2 - cadeia de caracteres 2
 */
std::string Concat(const std::string& text1, const std::string& text2) {
    return text1 + text2;
}

/*
    Funcao para ler uma cadeia de caracteres do teclado.
    @return cadeia de caracteres lida
    @param  text - mensagem a ser exibida antes da leitura
*/
std::string ReadString(const std::string& text) {
    std::string buffer;
    std::cout << text;
    std::cin >> buffer;
    return buffer;
}
#else
/*
    Funcao para ler uma cadeia de caracteres do teclado.
    @return cadeia de caracteres lida
    @param  text - mensagem a ser exibida antes da leitura
*/
char *ReadString(const char *text) {
    char *buffer = (char *)malloc(STR_SIZE);
    if (buffer == NULL) {
        printf("Erro ao alocar memória para buffer.\n");
        exit(1);
    }
    printf("%s", text);
    scanf("%s", buffer);
    fflush(stdin);
    return buffer;
}
/**
    Funcao para juntar 2 textos.
    @return juncao das cadeias de caracteres ou
    @param  text1  - cadeia de caracteres 1
    @param  text2 - cadeia de caracteres 2
 */
chars Concat(const char *const text1, const char *const text2)
{ // reservar area
    chars buffer = New_chars(strlen(text1) + strlen(text2) + 1);
    strcpy(buffer, text1);
    strcat(buffer, text2);
    return (buffer);
} // fim IO_concat ( )

/**
    Funcao para copiar parte de uma cadeia de caracteres.
    @return parte de cadeia de caracteres ou
            NULL, caso houver parametros invalidos
    @param  text  - cadeia de caracteres
    @param  start - onde comecar
    @param  size  - quantos caracteres copiar
 */
char *Substring(char *text, int start, unsigned int size)
{
    chars buffer = NULL;
    if (start >= 0 && (start + size) < (int)strlen(text))
    {
        buffer = New_chars(size + 1);
        memcpy(buffer, text + start, size);
        buffer[size] = '\0';
    }
    return (buffer);
} // fim IO_substring ( )

void Print(const char *const text)
{
    IO_printf("%s", text);
    //      puts ( text );
}
void Println(const char *const text)
{
    IO_printf("%s\n", text);
    //  puts ( text ); putchar ( '\n' );
} // fim IO_println ( )
int Length(char *text)
{
    int x = 0;
    if (text)
    {
        x = strlen(text);
    }
    return (x);
} // fim IO_length ( )
#endif
/**
    Funcao para ler uma cadeia de caracteres de arquivo.
    @return palavra lida
    @param arquivo - referencia para arquivo aberto
 */
chars Fileread(FILE *filePtr)
{
    chars buffer = New_chars(STR_SIZE + 1);

    IO_fscanf(filePtr, "%s", buffer); // ler uma cadeia
    return (buffer);
} // fim IO_fread ( )

/**
    Funcao para ler uma linha inteira.
    @return linha lida
    @param filePtr - referencia para arquivo aberto
 */
chars Filereadln(FILE *filePtr)
{
    chars buffer = New_chars(STR_SIZE + 1);

    fgets(buffer, STR_SIZE, filePtr); // ler uma linha
    buffer[strlen(buffer) - 1] = EOS; // reposicionar o fim de linha
    return (buffer);
} // fim IO_freadln ( )

/*
    Funcao pra determinar se o caractere é um simbolo.
    @return 1 se for um letra, 2 se for dígito, 3 se for espaço em branco e 4 se for outro símbolo
    @param c - caractere a ser analisado
*/

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
/**
 * Função para calcular a potência de um número.
 * @param base - base da potência
 * @param expoente - expoente da potência
 * 
*/
double Potencia(double base, int expoente) {
    if (expoente == 0) {
        return 1.0;
    } else if (expoente > 0) {
        return base * Potencia(base, expoente - 1);
    } else {
        return 1.0 / (base * Potencia(base, -expoente - 1));
    }
}

/*
    Funcao pra determinar se o número é primo.
    @return retorna se for primo
    @param numero - número a ser analisado
*/
int ehPrimo(int numero) {
    int divisores = 0;
    for (int i = 1; i <= numero; i++) {
        if (numero % i == 0) {
            divisores++;
        }
    }
    return divisores == 2;
}
/*
    Funcao pra determinar se a letra é maiúscula.
    @return 1 se for um maiuscula, 2 se for minuscula, 3 se não for letra
    @param c - caractere a ser analisado
*/

int detectaMaiuscula(char c) {
    if (isalpha(c)) {
        if(isupper(c)) {
            return 1; // Maiúscula
        } else {
            return 2; // Minúscula
        }
    } else {
        return 3; // outro símbolo 
    } 
}

/**
    Funcao para ler uma linha inteira.
    @return linha lida
    @param text - mensagem a ser exibida antes da leitura
 */
chars Readln(const char *const text)
{
    if (IO_trace)
        IO_printf("%s", text);
    return (Filereadln(stdin));
} // fim IO_readln ( )

/**
    Funcao para gerar numeros aleatorios
    @return numero gerado
    @param min - valor minimo 
    @param max - valor maximo 
 */
int NumeroAleatorio(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

/*
    Funcao para limpar a linha atual
*/
void ClearCurrentLine() {
    printf("\033[2K\r"); // Código de escape para limpar a linha e retornar ao início
    fflush(stdout); // Garante que a saída seja exibida imediatamente
}

#endif