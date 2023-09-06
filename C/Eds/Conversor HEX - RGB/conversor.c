#include <stdio.h>
#include <stdlib.h>

int main() {
    char hexColor[7];  
    int vermelho, verde, azul;

    printf("Digite o código hexadecimal da cor (RRGGBB): ");
    scanf("%6s", hexColor);

    // sscanf converte o valor hexadecimal em decimal
    if (sscanf(hexColor, "%2x%2x%2x", &vermelho, &verde, &azul) == 3) {
        if (vermelho >= 0 && vermelho <= 255 && verde >= 0 && verde <= 255 && azul >= 0 && azul <= 255) {
            printf("Cor RGB: (%d, %d, %d)\n", vermelho, verde, azul);
        } else {
            printf("Valores de cor fora do intervalo.\n");
        }
    } else {
        printf("Entrada inválida. Forneça um código hexadecimal válido (RRGGBB).\n");
    }

    return 0;
}
