#include <iostream>
using namespace std;
class Quadrado { 

 private:
    int lado;

 public:
    Quadrado(int l) : lado(l) {}
    int getLado()
    {
        return lado;
    }
    int perimetro()
    {
        return 4 * lado;
    }
    int area()
    {
        return lado * lado;
    }
    void print()
    {
        cout << "[Quadrado, lado=" << this->lado << "]" << "\n" << endl;
    }
};

int main()
{       
    int lado1;
    cout << "Digite o lado do quadrado: ";
    cin >> lado1;

    Quadrado q(lado1);

    cout << "\n---------------- Seu quadrado ----------------" << endl;
    cout << "lado do quadrado = " << q.getLado() << endl;
    cout << "perimetro do quadrado = " << q.perimetro() << endl;
    cout << "area do quadrado = " << q.area() << endl;

    q.print();
    return 0;
}
