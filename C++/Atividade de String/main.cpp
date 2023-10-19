#include <iostream>
#include <string>
using namespace std;
int main()
{
    
    string s1 = "ola mundo";
    cout << "string 1: " << s1 << endl;
    cout << "tamanho da string 1: " << s1.size() << endl;
    
    string s2;
    cout << "Digite um texto: ";
    getline(cin, s2);
    cout << "string 2: " << s2 << endl;
    cout << "tamanho da string 2: " << s2.length() << endl;
    
    string s3 = s1 + " " + s2;
    cout << "string resultante: " << s3 << endl;
    cout << "tamanho da string resultante: " << s3.size()
         << endl;
    return 0;
}
