#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <iomanip>
#include <string>
#include <Windows.h>
#include "JMRL.h"

using namespace std;

string SortearFrase()
{
    srand(time(0));

    FILE *arquivo = fopen("../frases.txt", "r");

    if (arquivo == nullptr)
    {
        cerr << "Erro ao abrir o arquivo frases.txt." << endl;
        return "";
    }

    int numeroDeLinhas = 0;
    char linha[256];
    while (fgets(linha, sizeof(linha), arquivo) != nullptr)
    {
        numeroDeLinhas++;
    }

    int linhaEscolhida = rand() % numeroDeLinhas;
    rewind(arquivo);

    for (int i = 0; i < linhaEscolhida; ++i)
    {
        fgets(linha, sizeof(linha), arquivo);
    }

    fclose(arquivo);

    linha[strlen(linha) - 1] = '\0';

    return linha;
}

void CadastrarPalavra(){
    LimparTela();
    string palavra;
    ColorText("AVISO: Lembre de nao usar acentos, o jogo so suporta a tabela ASCII padrao\n", COLOR_RED);
    ColorText("(para voltar ao menu, digite 'menu')\n", COLOR_GRAY);
    cout << "Digite a frase que deseja cadastrar: ";
    getline(cin, palavra);
    if (palavra == "menu")
    {
        return;
    }
    FILE *arquivo = fopen("../frases.txt", "a");
    if (arquivo == nullptr)
    {
        cerr << "Erro ao abrir o arquivo frases.txt." << endl;
        return;
    }
    fprintf(arquivo, "%s\n", palavra.c_str());
    ColorText("Frase cadastrada com sucesso!\n", COLOR_GREEN);
    fclose(arquivo);
}

void ClearCurrentLine()
{
    std::cout << '\r'; // Retorna ao início da linha
    for (int i = 0; i < 80; ++i) // Limpa a linha com espaços em branco
        std::cout << ' ';
    std::cout << '\r'; // Retorna ao início da linha novamente
}

void jogo(){
    int acertos = 0, erros = 0, naoDigitados = 0;
    LimparTela();
    string frase = SortearFrase();

    clock_t start, end;
    double elapsed_seconds;

    start = clock();

    Print("Sua frase: ");
    ColorText(frase, COLOR_GREEN);
    Println("");
      for (int i = 5; i >= 1; --i)
    {
        ClearCurrentLine(); // Limpa a linha atual
        std::cout << i << "..." << std::flush;
        Sleep(1000);
    }
    
    ClearCurrentLine();
    std::cout << "Vai!" << std::endl;
    Sleep(300);
    
    string input;
    getline(cin, input);
    LimparTela();
    cout << "Frase digitada: " << input << endl;
    Print("Sua tentativa: ");
    for (int i = 0; i < frase.length() && i < input.length(); ++i)
    {
        if (frase[i] == input[i])
        {
            ColorText(string(1, frase[i]), COLOR_GREEN);
            acertos++;
        }
        else
        {
            ColorText(string(1, frase[i]), COLOR_RED);
            erros++;
        }
    }

    for (int i = input.length(); i < frase.length(); ++i)
    {
        ColorText(string(1, frase[i]), COLOR_GRAY);
        naoDigitados++;
    }

    end = clock();
    elapsed_seconds = double(end - start) / CLOCKS_PER_SEC;
    ColorText("\n\nSuas estatisticas: ", COLOR_BLUE);
    cout << "\nTempo decorrido: " << elapsed_seconds << " segundos." << endl;
    double caracteresCorretos = 0;

    for (int i = 0; i < frase.length() && i < input.length(); ++i)
    {
        if (frase[i] == input[i])
        {
            caracteresCorretos++;
        }
    }

    double velocidadeRealista = caracteresCorretos / elapsed_seconds;
    cout << "Velocidade: " << fixed << setprecision(2) << velocidadeRealista << " caracteres por segundo." << endl;

    double precisaotot = (static_cast<double>(acertos) / (acertos + erros + naoDigitados)) * 100;
    double precisao = (static_cast<double>(acertos) / (acertos + erros)) * 100;
    cout << "Precisao total: " << fixed << setprecision(2) << precisaotot << "%" << endl;
    cout << "Precisao digitada: " << fixed << setprecision(2) << precisao << "%" << endl;
}

int main()
{
    LimparTela();
    int opcao;
    do
    {
        ColorText("Bem vindo ao jogo de digitacao!\n", COLOR_BLUE);
        printf("2 - Cadastrar-frase\n");
        printf("1 - Jogar\n");
        printf("0 - Sair\n");
        printf("\nEscolha uma opcao: ");
        scanf(" %d", &opcao);

        switch (opcao)
        {
        case 0:
            Encerrar();
            exit(0);
        case 1:
            cin.ignore();
            jogo();
            Encerrar();
            LimparTela();
            break;
        case 2:
            cin.ignore();
            CadastrarPalavra();
            Encerrar();
            LimparTela();
            break;
        default:
            printf("Opcao invalida.\n");
            Sleep(2000);
            LimparTela();
        }
    } while (opcao != 0);
    return 0;
}
