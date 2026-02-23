#include <iostream>
using namespace std;

int main() {

    float estatura, peso;

    cout << "Ingrese su estatura en metros: ";
    cin >> estatura;

    cout << "Ingrese su peso en kilogramos: ";
    cin >> peso;

    float imc = peso / (estatura * estatura);

    cout << "Su IMC es: " << imc << endl;

    return 0;
}
