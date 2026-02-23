#include <iostream>
using namespace std;

int main() {

    double monto;
    double porcentaje;

    cout << "Ingrese el monto inicial: ";
    cin >> monto;

    cout << "Ingrese el porcentaje de incremento: ";
    cin >> porcentaje;

    double nuevoMonto = monto + (monto * porcentaje / 100);

    cout << "El nuevo monto es: " << nuevoMonto << endl;

    return 0;
}
