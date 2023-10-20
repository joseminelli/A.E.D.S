// ? Qual saída esperada da função abaixo?

// ! A formatação está do jeito que estava na prova.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int f3a(int x)
{  int y=0; int z=0;
    while (x>0)
    { z=x%10; if(z%2!=0) y=y*10+x%10; x=x/10; }
    return (y);
}

int main()
{
   printf("%d", f3a(123456));
}

// ?        Alternativas:
// ?        a) 123
// ?        b) 135
// ?        c) 321
// ?        d) 531 CORRETA
// ?        e) OUTRA