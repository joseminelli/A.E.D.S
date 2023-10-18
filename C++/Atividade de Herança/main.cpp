#include <iostream>
#include <string>
using namespace std;

class Forma
{

public:
    double perimetro(double lado1, double lado2)
    {
        double peri = (lado1 * 2) + (lado2 * 2);

        return peri;
    }
    double area(double lado1, double lado2)
    {
        double area = lado1 * lado2;

        return area;
    }
};

class Retangulo : public Forma
{
private:
    double base;
    double altura;

public:
    void print()
    {
        printf("\nQual o tamanho da base do retangulo? ");
        scanf("%lf", &base);
        printf("Qual a altura do retangulo? ");
        scanf("%lf", &altura);

        double perir = perimetro(altura, base);
        double arear = area(altura, base);
        printf("\nSeu retangulo:");
        printf("\nArea: %0.3lf\nPerimetro: %0.3lf\n", arear, perir);
    }
};

class Quadrado : public Retangulo
{
private:
    double ladoq;

public:
    void print()
    {
        printf("\nQual o tamanho do lado do quadrado? ");
        scanf("%lf", &ladoq);

        double periq = perimetro(ladoq, ladoq);
        double areaq = area(ladoq, ladoq);
        printf("\nSeu quadrado:");
        printf("\nArea: %0.3lf\nPerimetro: %0.3lf\n\n", areaq, periq);
    }
};

int main()
{
    Quadrado quadrado;
    Retangulo retangulo;

    quadrado.print();
    retangulo.print();
}