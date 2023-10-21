
/**
   0116.c - v0.1 - 27 / 08 / 2021
   author  801617 - José Carlos Ribeiro Minelli
 **/#include "io.h"

double calcular_h(double x) {
    double h = x * sqrt(3) / 2;
    return h;
}

int main() {

    double lado, altura, perimetro, area;
    printf("fale o numero corespondente a lado\n");
    scanf("%d", &lado); 
    getchar();

    if (lado>0){
        altura = calcular_h(lado);
        area = (lado*altura)/2;

        perimetro = lado * 3;

        printf("area: %lf\n", area);
        printf("perimetro: %lf\n", perimetro);
    }else{
        printf("o valor e negativo ou igual a 0\n");
    }
    

    

    printf("\n\n--------- | FIM DO PROGRAMA | ---------\n\n");
    return 0;
}