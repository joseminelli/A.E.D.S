#include <iostream>
#include <string>
using namespace std;

class Carro {
private:
    float tanque = 0;
    float consumo = 15;

public:
    int abastecer() {
        float litros;
        cout << "Quantos litros deseja abastecer? ";
        cin >> litros;
        tanque += litros;
    }
    int mover(){
        float distancia;
        cout << "Quantos km deseja percorrer? ";
        cin >> distancia;
        float consumoTotal = distancia / consumo;
        if (tanque >= consumoTotal) {
            tanque -= consumoTotal;
            cout << "Carro andou " << distancia << "km e ainda tem " << tanque << " litros no tanque." << endl;
        } else {
            cout << "Carro nao tem combustivel suficiente para andar " << distancia << "km." << endl;
        }
    }
};

int main(){
    Carro carro1;
    Carro carro2;
    cout << "\n Carro 1:" << endl;
    carro1.abastecer();
    carro1.mover();
    cout << "\n Carro 2:" << endl;
    cout << endl;
    carro2.abastecer();
    carro2.mover();

}