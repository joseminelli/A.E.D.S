// ? Qual saída esperada da função abaixo?

// ! A formatação está do jeito que estava na prova.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int f4a(int x)
{  int w = 6;
    while (x-1>0)
    { w=w+1;
    if(w%7==0){ if(w%10%2!=0)
    printf("%d ", w); w=w+13;} x=x-1;}
    return (w+1);
}

int main()
{
   printf(">%d", f4a(5));
}

// ?        Alternativas:
// ?        a) 7 21 35 49 >63 CORRETA
// ?        b) 7 14 21 35 >49
// ?        c) 7 21 28 35 >49
// ?        d) 7 14 21 28 >35
// ?        e) OUTRA