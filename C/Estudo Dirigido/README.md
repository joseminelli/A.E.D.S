# Estudo dirigido (Ed)

## Funcionamento
O Estudo Dirigido (ED) é uma coleção de atividades estruturadas, cada uma com um arquivo PDF contendo as instruções detalhadas. Cada ED consiste em 10 exemplos e 10 questões. Para facilitar futuras revisões e compreensão, recomenda-se que os exemplos e questões sejam incorporados diretamente no código, identificados como "Method_?" (onde "?" representa o número da atividade).

## Incorporando Atividades no Código
Para garantir uma compreensão fácil e revisões futuras, cada atividade foi incorporada diretamente no código com o seguinte padrão:

```
int Method_1() {
    # Instruções da atividade 1
}

int Method_2() {
    # Instruções da atividade 2
}

int main() {
    int escolha;
    do {
        printf("\nEscolha uma opção:\n");
        printf("1. Method_1\n");
        printf("2. Method_2\n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
        case 1:
            Method_1();
            break;
        case 2:
            Method_2();
            break;
        case 0:
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
        }
    } while (escolha != 0);
    return 0;
}
```

 ... e assim por diante para os demais métodos
Dentro de cada método, você encontrará as instruções específicas da atividade correspondente.

## Observações
Revisão Simples: Os exemplos e questões estão incorporados diretamente no código para facilitar revisões. Recomenda-se revisar os métodos periodicamente para manter a familiaridade com os conceitos ensinados.

Nomenclatura Padrão: Cada método é nomeado de acordo com o número da atividade correspondente para facilitar a identificação e referência.

Organização de Pastas: Para manter a organização, os arquivos estão divididos em pastas específicas para cada ED, incluindo subpastas para exemplos e questões.
