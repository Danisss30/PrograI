#include <iostream>
using namespace std;

int main() {
    int opcion;

    cout << "1. Mostrar 1 al 3\n";
    cout << "2. Mostrar pares hasta 6\n";
    cout << "Elija una opcion: ";
    cin >> opcion;

    if (opcion == 1) {
        int i = 1;
        while (i <= 3) {
            cout << i << endl;
            i++;
        }
    } else if (opcion == 2) {
        int i = 2;
        while (i <= 6) {
            cout << i << endl;
            i += 2;
        }
    }

    return 0;
}