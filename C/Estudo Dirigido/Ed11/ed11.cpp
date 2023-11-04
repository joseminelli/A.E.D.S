#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <climits>

class ArrayOperations {
private:
    std::vector<int> arr;

public:
    // Gera números inteiros aleatórios
    void randomIntGenerate(int N, int inferior, int superior) {
        arr.clear();
        arr.reserve(N);
        std::srand(static_cast<unsigned int>(std::time(nullptr))); // Define a semente para números aleatórios
        for (int i = 0; i < N; i++) {
            int valor = inferior + std::rand() % (superior - inferior + 1);
            arr.push_back(valor);
        }
    }

    // Encontra o maior valor par no arranjo
    int findLargestEven() {
        int largestEven = INT_MIN;
        for (int value : arr) {
            if (value % 2 == 0 && value > largestEven) {
                largestEven = value;
            }
        }
        return (largestEven == INT_MIN) ? -1 : largestEven;
    }

    // Encontra o menor valor ímpar no arranjo
    int findSmallestOdd() {
        int smallestOdd = INT_MAX;
        for (int value : arr) {
            if (value % 2 != 0 && value < smallestOdd) {
                smallestOdd = value;
            }
        }
        return (smallestOdd == INT_MAX) ? -1 : smallestOdd;
    }

    // Soma valores em um intervalo do arranjo
    int addInterval(int inicio, int fim) {
        int soma = 0;
        for (int i = inicio; i <= fim && i < arr.size(); i++) {
            soma += arr[i];
        }
        return soma;
    }

    // Grava o arranjo em um arquivo
    void writeArrayToFile(const char* fileName) {
        std::ofstream file(fileName);
        if (!file.is_open()) {
            std::cerr << "Erro ao abrir o arquivo." << std::endl;
            return;
        }
        file << arr.size() << std::endl;
        for (int value : arr) {
            file << value << std::endl;
        }
        file.close();
        std::cout << "Números gerados e gravados com sucesso em " << fileName << "." << std::endl;
    }

    // Calcula a média dos valores em um intervalo do arranjo
    int averageInterval(int inicio, int fim) {
        int soma = 0;
        int count = 0;
        for (int i = inicio; i <= fim && i < arr.size(); i++) {
            soma += arr[i];
            count++;
        }
        return (count > 0) ? (soma / count) : 0;
    }

    // Verifica se todos os valores no arranjo são positivos
    bool positives() {
        for (int value : arr) {
            if (value < 0) {
                return false;
            }
        }
        return true;
    }

    // Verifica se o arranjo está ordenado em ordem crescente
    bool isCrescent() {
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] < arr[i - 1]) {
                return false;
            }
        }
        return true;
    }

    // Procura um valor em um intervalo do arranjo
    bool searchInterval(int procurado, int inicio, int fim) {
        for (int i = inicio; i <= fim && i < arr.size(); i++) {
            if (arr[i] == procurado) {
                return true;
            }
        }
        return false;
    }

    // Escala valores em um intervalo do arranjo
    void scalar(int constante, int inicio, int fim) {
        for (int i = inicio; i <= fim && i < arr.size(); i++) {
            arr[i] *= constante;
        }
    }
};

// Função para gerar números aleatórios
void generateRandomNumbers(ArrayOperations& arr) {
    int N, inferior, superior;
    char fileName[] = "DADOS.TXT";

    std::cout << "Digite a quantidade de elementos a serem gerados: ";
    std::cin >> N;
    std::cout << "Digite o valor inferior do intervalo: ";
    std::cin >> inferior;
    std::cout << "Digite o valor superior do intervalo: ";
    std::cin >> superior;

    arr.randomIntGenerate(N, inferior, superior);
    arr.writeArrayToFile(fileName);
}

// Função para encontrar o maior valor par
void findLargestEven(ArrayOperations& arr) {
    int maior_par = arr.findLargestEven();
    std::cout << "Maior valor par: " << maior_par << std::endl;
}

// Função para encontrar o menor valor ímpar
void findSmallestOdd(ArrayOperations& arr) {
    int menor_impar = arr.findSmallestOdd();
    std::cout << "Menor valor ímpar: " << menor_impar << std::endl;
}

// Função para somar valores em um intervalo
void sumInterval(ArrayOperations& arr) {
    int inicio, fim;
    std::cout << "Digite a posição inicial do intervalo: ";
    std::cin >> inicio;
    std::cout << "Digite a posição final do intervalo: ";
    std::cin >> fim;

    int soma = arr.addInterval(inicio, fim);
    std::cout << "Soma dos valores no intervalo: " << soma << std::endl;
}

// Função para calcular a média dos valores em um intervalo
void averageInterval(ArrayOperations& arr) {
    int inicio, fim;
    std::cout << "Digite a posição inicial do intervalo: ";
    std::cin >> inicio;
    std::cout << "Digite a posição final do intervalo: ";
    std::cin >> fim;

    int media = arr.averageInterval(inicio, fim);
    std::cout << "Média dos valores no intervalo: " << media << std::endl;
}

// Função para verificar se todos os valores no arranjo são positivos
void checkPositives(ArrayOperations& arr) {
    if (arr.positives()) {
        std::cout << "Todos os valores no arranjo são positivos." << std::endl;
    } else {
        std::cout << "Pelo menos um valor no arranjo não é positivo." << std::endl;
    }
}

// Função para verificar se o arranjo está ordenado em ordem crescente
void checkCrescent(ArrayOperations& arr) {
    if (arr.isCrescent()) {
        std::cout << "O arranjo está ordenado em ordem crescente." << std::endl;
    } else {
        std::cout << "O arranjo não está ordenado em ordem crescente." << std::endl;
    }
}

// Função para procurar um valor em um intervalo do arranjo
void searchInInterval(ArrayOperations& arr) {
    int procurado, inicio, fim;
    std::cout << "Digite o valor inteiro a ser procurado: ";
    std::cin >> procurado;
    std::cout << "Digite a posição inicial do intervalo: ";
    std::cin >> inicio;
    std::cout << "Digite a posição final do intervalo: ";
    std::cin >> fim;

    bool existe = arr.searchInterval(procurado, inicio, fim);
    if (existe) {
        std::cout << "O valor " << procurado << " existe no intervalo especificado." << std::endl;
    } else {
        std::cout << "O valor " << procurado << " não existe no intervalo especificado." << std::endl;
    }
}

// Função para escalar valores em um intervalo do arranjo
void scaleArray(ArrayOperations& arr) {
    int constante, inicio, fim;
    std::cout << "Digite o valor inteiro para a constante de escala: ";
    std::cin >> constante;
    std::cout << "Digite a posição inicial do intervalo: ";
    std::cin >> inicio;
    std::cout << "Digite a posição final do intervalo: ";
    std::cin >> fim;

    arr.scalar(constante, inicio, fim);
    std::cout << "Os valores no intervalo especificado foram escalados com sucesso." << std::endl;
}

int main() {
    ArrayOperations arr;

    int escolha;
    do {
        std::cout << "\nEscolha uma opção:\n";
        std::cout << "1. Gerar números aleatórios e gravar em um arquivo\n";
        std::cout << "2. Encontrar o maior valor par no arranjo\n";
        std::cout << "3. Encontrar o menor valor ímpar no arranjo\n";
        std::cout << "4. Somar valores em um intervalo do arranjo\n";
        std::cout << "5. Calcular a média dos valores em um intervalo do arranjo\n";
        std::cout << "6. Verificar se todos os valores no arranjo são positivos\n";
        std::cout << "7. Verificar se o arranjo está ordenado em ordem crescente\n";
        std::cout << "8. Procurar um valor em um intervalo do arranjo\n";
        std::cout << "9. Escalar valores em um intervalo do arranjo\n";
        std::cout << "0. Sair\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> escolha;

        switch (escolha) {
            case 1:
                generateRandomNumbers(arr);
                break;
            case 2:
                findLargestEven(arr);
                break;
            case 3:
                findSmallestOdd(arr);
                break;
            case 4:
                sumInterval(arr);
                break;
            case 5:
                averageInterval(arr);
                break;
            case 6:
                checkPositives(arr);
                break;
            case 7:
                checkCrescent(arr);
                break;
            case 8:
                searchInInterval(arr);
                break;
            case 9:
                scaleArray(arr);
                break;
            case 0:
                break;
            default:
                std::cout << "Opção inválida. Tente novamente." << std::endl;
        }
    } while (escolha != 0);

    return 0;
}
