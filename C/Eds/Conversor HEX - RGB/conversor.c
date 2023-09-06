#include <stdio.h>
#include <stdlib.h>

void Encerrar() {
    printf("\nPressione ENTER para continuar...");
    char x = '0';
    do { x = getchar( ); } while ( '\n' != x );
    getchar();
}

void HextoRgb() {
    char hexColor[7];  
    int vermelho, verde, azul;

    printf("\nDigite o codigo hexadecimal da cor (RRGGBB): ");
    scanf("%6s", hexColor);

    // sscanf converte o valor hexadecimal em decimal
    if (sscanf(hexColor, "%2x%2x%2x", &vermelho, &verde, &azul) == 3) {
        if (vermelho >= 0 && vermelho <= 255 && verde >= 0 && verde <= 255 && azul >= 0 && azul <= 255) {
            printf("\nCor RGB: (%d, %d, %d)\n", vermelho, verde, azul);
        } else {
            printf("Valores de cor fora do intervalo.\n");
        }
    } else {
        printf("Entrada invalida. Forneca um codigo hexadecimal valido (RRGGBB).\n");
    }

    Encerrar();
    return 0;
}

void RgbtoHex(){
    int vermelho, verde, azul;
    char hexColor[7];

    printf("\nDigite os valores RGB (0 a 255):\n");
    printf("Vermelho: ");
    scanf("%d", &vermelho);
    printf("Verde: ");
    scanf("%d", &verde);
    printf("Azul: ");
    scanf("%d", &azul);

    if (vermelho >= 0 && vermelho <= 255 && verde >= 0 && verde <= 255 && azul >= 0 && azul <= 255) {
        sprintf(hexColor, "%02x%02x%02x", vermelho, verde, azul);
        printf("\nCor HEX: %s\n", hexColor);
    } else {
        printf("Valores de cor fora do intervalo.\n");
    }

    Encerrar();
    return 0;
}

int main() {
    int opcao;
    do
    {
    printf("\n=========Conversor de cores =========\n");
    printf("1 - HEX -> RGB\n");
    printf("2 - RGB -> HEX\n");
    printf("0 - Sair\n");
    printf("Escolha uma opcao: ");
    scanf(" %d", &opcao);

    switch (opcao)
    {
        case 0: 
        Encerrar();
        exit(0);
    case 1:
        HextoRgb();
        break;
    case 2: 
        RgbtoHex();
        break;
    default:
        printf("Opcao invalida.\n");
    }
    } while (opcao != 0);
    return 0;
}
