#include <iostream>
using namespace std;

int main() {

    char letra;

    cout << "Ingrese una letra: ";
    cin >> letra;

    cout << "Letra ingresada: " << letra << endl;
    cout << "La letra 3 veces: " << letra << letra << letra << endl;
    cout << "Valor numerico interno: " << int(letra) << endl;

    return 0;
}
