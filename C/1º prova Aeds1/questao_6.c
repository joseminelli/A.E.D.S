/*
Definir uma função inteira para verificar se uma palavra possui letras sem repetições;
Ler palavras, uma de cada vez, até encontrar duas delas sem letras repetidas.
ex: alcance, alce, celas, lance, realce, relance
*/

#include <stdio.h>
#include <string.h>

int tem_letras_sem_repeticao(const char *palavra) {
    int i, j;
    int tamanho = strlen(palavra);

    for (i = 0; i < tamanho; i++) {
        for (j = i + 1; j < tamanho; j++) {
            if (palavra[i] == palavra[j]) {
                return 0;
            }
        }
    }

    return 1; 
}

int main() {
    char palavra[100];
    int palavras_sem_repeticao = 0;

    while (palavras_sem_repeticao < 2) {
        printf("Digite uma palavra: ");
        scanf("%s", palavra);

        if (tem_letras_sem_repeticao(palavra)) {
            palavras_sem_repeticao++;
            if(palavras_sem_repeticao == 1 ){
            printf("A palavra não possui repetições.\nQtd encontrada: %d\n\n", palavras_sem_repeticao);
            }
        } else {
            printf("A palavra possui letras repetidas. Tente novamente.\n");
        }
    }

    printf("Duas palavras sem letras repetidas foram encontradas.\n\n Encerrando...\n");

    return 0;
}
