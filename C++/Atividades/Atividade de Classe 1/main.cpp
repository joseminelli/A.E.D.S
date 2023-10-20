#include <iostream>
#include <string>
using namespace std;

class Pessoa {
private:
    string nome;
    int idade;
    float altura;

public:
    void getNome() {
        getline(cin, nome);
    }

    void getIdade() {
        cin >> idade;
        cin.ignore();
    }

    void getAltura() {
        cin >> altura;
        cin.ignore();
    }

    void print() {
        cout << "\n------------------------\n" << endl;
        cout << "Sua nova pessoa: \n" << endl;
        cout << "Nome: " << nome << ", Idade: " << idade << " anos" << ", Altura: " << altura << " metros" << endl;
        cout << "\n------------------------\n" << endl;
    }
};

int main() {
    Pessoa p1;
    cout << "Digite o nome da pessoa: ";
    p1.getNome();
    cout << "Digite a idade da pessoa: ";
    p1.getIdade();
    cout << "Digite a altura da pessoa (em metros): ";
    p1.getAltura();
    p1.print();
    return 0;
}
