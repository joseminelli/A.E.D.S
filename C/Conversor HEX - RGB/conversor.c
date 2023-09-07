#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Encerrar()
{
    printf("\nPressione ENTER para continuar...");
    char x = '0';
    do
    {
        x = getchar();
    } while ('\n' != x);
    getchar();
}

void RgbText(red, green, blue, texto){
    printf("\x1b[38;2;%d;%d;%dm%s\x1b[0m", red, green, blue, texto);
}

void HextoRgb()
{
    char hexColor[7];
    int vermelho, verde, azul;

    printf("\nDigite o codigo hexadecimal da cor (");
    RgbText(255, 0, 0, "RR");
    RgbText(0, 255, 0, "GG");
    RgbText(0, 0, 255, "BB");
    printf(") \n");
    scanf("%6s", hexColor);

    if (sscanf(hexColor, "%2x%2x%2x", &vermelho, &verde, &azul) == 3)
    {
        if (vermelho >= 0 && vermelho <= 255 && verde >= 0 && verde <= 255 && azul >= 0 && azul <= 255)
        {
            printf("\nCor RGB: \x1b[38;2;%d;%d;%dm(%d , %d, %d)\x1b[0m\n", vermelho, verde, azul, vermelho, verde, azul);
        }
        else
        {
            printf("Valores de cor fora do intervalo.\n");
        }
    }
    else
    {
        printf("Entrada invalida. Forneca um codigo hexadecimal valido (RRGGBB).\n");
    }

    Encerrar();
}

void RgbtoHex()
{
    int vermelho, verde, azul;
    char hexColor[7];

    printf("\nDigite os valores RGB (0 a 255):\n\n");
    RgbText(255, 0, 0, "Vermelho: ");
    scanf("%d", &vermelho);
    RgbText(0, 255, 0, "Verde: ");
    scanf("%d", &verde);
    RgbText(0, 0, 255, "Azul: ");
    scanf("%d", &azul);

    if (vermelho >= 0 && vermelho <= 255 && verde >= 0 && verde <= 255 && azul >= 0 && azul <= 255)
    {
        
        sprintf(hexColor, "%02x%02x%02x", vermelho, verde, azul);
        printf("\nCor HEX: \x1b[38;2;%d;%d;%dm%s\x1b[0m\n", vermelho, verde, azul, hexColor);
    }
    else
    {
        printf("Valores de cor fora do intervalo.\n");
    }

    Encerrar();
}

int main()
{
    int opcao;
    do
    {
        RgbText(0, 155, 255, "\n========= ");
        printf(" Conversor de cores ");
        RgbText(0, 155, 255, " =========\n");

        printf("2 - RGB -> HEX\n");
        printf("1 - HEX -> RGB\n");
        printf("0 - Sair\n");
        printf("\nEscolha uma opcao: ");
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
