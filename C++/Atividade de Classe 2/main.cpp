#include <iostream>
#include <string>
using namespace std;

class Relogio {
private:
    int hora;
    int minuto;
    int segundo;

public:
    void setHora(int h, int m, int s) {
        hora = h;
        minuto = m;
        segundo = s;
    }

    string getHora() {
        string horaFormatada = to_string(hora);
        string minutoFormatado = to_string(minuto);
        string segundoFormatado = to_string(segundo);

        if (hora < 10) {
            horaFormatada = "0" + horaFormatada;
        }
        if (minuto < 10) {
            minutoFormatado = "0" + minutoFormatado;
        }
        if (segundo < 10) {
            segundoFormatado = "0" + segundoFormatado;
        }

        return horaFormatada + ":" + minutoFormatado + ":" + segundoFormatado;
    }

    void avancarSegundo() {
        segundo++;
        if (segundo >= 60) {
            segundo = 0;
            minuto++;
            if (minuto >= 60) {
                minuto = 0;
                hora++;
                if (hora >= 24) {
                    hora = 0;
                }
            }
        }
    }
};

int main() {
    Relogio relogio;
    relogio.setHora(23, 59, 59);

    cout << "Hora atual: " << relogio.getHora() << endl;

    relogio.avancarSegundo();

    cout << "Proximo segundo: " << relogio.getHora() << endl;

    return 0;
}
