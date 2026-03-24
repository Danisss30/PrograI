//Daniela Nohemy Divas Carrillo 
#include <iostream>
using namespace std;

int main() {
    int opcion;

    do {
        cout << "\nMENU\n";
        cout << "1. Mostrar numeros del 1 al 5\n";
        cout << "2. Mostrar numeros pares del 1 al 10\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            int i = 1;
            while (i <= 5) {
                cout << i << endl;
                i++;
            }
        } 
        else if (opcion == 2) {
            int i = 2;
            while (i <= 10) {
                cout << i << endl;
                i += 2;
            }
        } 
        else if (opcion == 3) {
            cout << "Saliendo del programa..." << endl;
        } 
        else {
            cout << "Opcion invalida" << endl;
        }

    } while (opcion != 3);

    return 0;
}
