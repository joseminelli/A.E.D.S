// ? Qual chamada da função abaixo está correta?

// ! A formatação está do jeito que estava na prova.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int f5a(int x, int y, int z)
{  if(x>0)
    { z=z+y; y=y+2; x=x-1; z=f5a(x,y,z); }
    return (z);}


// ?        Alternativas:
// ?        a) f5a(2,1,0) = 3
// ?        b) f5a(3,1,0) = 8
// ?        c) f5a(4,1,0) =18
// ?        d) f5a(5,1,0) = 25 CORRETA
// ?        e) OUTRA