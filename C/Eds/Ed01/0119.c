/**
   0119.c - v0.1 - 27 / 08 / 2021
   author  801617 - José Carlos Ribeiro Minelli
 **/
#include "io.h"
#define PI  3.141592653

int main() {

    double raio, metadeRaio, semiCirculo;
    printf("defina o valor do raio\n");
    scanf("%lf", &raio);
    getchar();

    if (raio>0)
    {
        metadeRaio = raio / 2;

        semiCirculo = ((PI * metadeRaio)/2)/2;
    }else{
        printf("o valor e negativo ou igual a 0\n");
    }

    puts("\n--------- | FIM DO PROGRAMA | ---------\n");
    return 0;
}