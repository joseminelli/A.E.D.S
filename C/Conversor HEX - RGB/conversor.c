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

void RgbText(red, green, blue, texto)
{
    printf("\x1b[38;2;%d;%d;%dm%s\x1b[0m", red, green, blue, texto);
}
typedef struct
{
    char nome[20];
    char hex[7];
    int r, g, b;
} Color;

int findColorByName(const char *name, const Color colors[], int numColors, Color *result)
{
    for (int i = 0; i < numColors; i++)
    {
        if (strcmp(name, colors[i].nome) == 0)
        {
            if (result != NULL)
            {
                strcpy(result->nome, colors[i].nome);
                strcpy(result->hex, colors[i].hex);
                result->r = colors[i].r;
                result->g = colors[i].g;
                result->b = colors[i].b;
            }
            return 1;
        }
    }
    return 0;
}

void TexttoRgb(const Color colors[], int numColors)
{
    int opcao;
    char userInput[20];
    do
    {
        RgbText(138, 43, 226, "\n========= ");
        printf(" Menu das cores ");
        RgbText(138, 43, 226, " =========\n");
        printf("0 - Voltar\n");
        printf("1- Escolha uma cor\n");
        printf("2- Lista das cores\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("\nDigite o nome da cor: ");
            scanf("%s", userInput);

            Color result;
            if (findColorByName(userInput, colors, numColors, &result))
            {
                printf("\nCor escolhida: ");
                RgbText(result.r, result.g, result.b, result.nome);
                printf("\nHEX: %s\n", result.hex);
                printf("RGB: (%d, %d, %d)\n", result.r, result.g, result.b);
            }
            else
            {
                printf("Cor nao encontrada.\n");
            }
            Encerrar();
            break;
        case 2:
            printf("\n");
            printf("Lista de cores:\n\n");
            for (int i = 0; i < numColors; i++)
            {
                RgbText(colors[i].r, colors[i].g, colors[i].b, colors[i].nome);
                printf("\n");
            }
            Encerrar();
            break;
        case 0:
            break;
        default:
            break;
        }
    } while (opcao != 0);
    return 0;

    Encerrar();
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
    Color colors[] = {
        {"azul", "0000FF", 0, 0, 255},
        {"vermelho", "FF0000", 255, 0, 0},
        {"verde", "00FF00", 0, 255, 0},
        {"amarelo", "FFFF00", 255, 255, 0},
        {"roxo", "800080", 128, 0, 128},
        {"laranja", "FFA500", 255, 165, 0},
        {"rosa", "FFC0CB", 255, 192, 203},
        {"cinza", "808080", 128, 128, 128},
        {"marrom", "A52A2A", 165, 42, 42},
        {"turquesa", "40E0D0", 64, 224, 208},
        {"preto", "000000", 0, 0, 0},
        {"branco", "FFFFFF", 255, 255, 255},
        {"azul_claro", "ADD8E6", 173, 216, 230},
        {"verde_claro", "90EE90", 144, 238, 144},
        {"rosa_claro", "FFB6C1", 255, 182, 193},
        {"violeta", "8A2BE2", 138, 43, 226},
        {"dourado", "FFD700", 255, 215, 0},
        {"prateado", "C0C0C0", 192, 192, 192},
        {"ciano", "00FFFF", 0, 255, 255},
        {"laranja_escuro", "FF8C00", 255, 140, 0},
        {"verde_escuro", "006400", 0, 100, 0},
        {"rosa_escuro", "8B0000", 139, 0, 0},
        {"amarelo_escuro", "FFD700", 255, 215, 0},
        {"azul_escuro", "00008B", 0, 0, 139},
        {"verde_oliva", "556B2F", 85, 107, 47},
        {"azul_marinho", "000080", 0, 0, 128},
        {"verde_musgo", "ADFF2F", 173, 255, 47},
        {"ouro_rosa", "B76E79", 183, 110, 121},
        {"turquesa_escura", "00CED1", 0, 206, 209},
        {"cinza_perola", "F5F5F5", 245, 245, 245},
        {"marrom_claro", "D2B48C", 210, 180, 140},

    };
    int numColors = sizeof(colors) / sizeof(colors[0]);

    int opcao;
    do
    {
        RgbText(0, 155, 255, "\n========= ");
        printf(" Conversor de cores ");
        RgbText(0, 155, 255, " =========\n");

        printf("3 - Cor por nome\n");
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
        case 3:
            TexttoRgb(colors, numColors);
            break;
        default:
            printf("Opcao invalida.\n");
        }
    } while (opcao != 0);
    return 0;
}
