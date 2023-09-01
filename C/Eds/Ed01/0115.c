
/**
   0115.c - v0.1 - 27 / 08 / 2021
   author  801617 - José Carlos Ribeiro Minelli
 **/
#include <stdio.h>

int main() {

    double base, h, area;

    printf("fale o numero corespondente a base\n");
    scanf("%d", &base);
    getchar();

    if (base>0)
    {
        
        printf("fale o numero corespondente a h\n");
        scanf("%d", &h);
        getchar();
        if (h>0)
        {
            area = (base * h)/2;

            printf("a area e %.2lf\n", area);
        }else{
        printf("o valor e negativo ou igual a 0\n");
        }   
        
    }else{
        printf("o valor e negativo ou igual a 0\n");
    }
    

    printf("\n\n--------- | FIM DO PROGRAMA | ---------\n\n");
    return 0;
}