#include <iostream>
using namespace std;

int main() {
    int num, suma = 0;
    int contador = 0;

    while (contador < 3) {
        cout << "Ingrese un numero: ";
        cin >> num;
        suma += num;
        contador++;
    }

    cout << "Suma total: " << suma << endl;

    return 0;
}