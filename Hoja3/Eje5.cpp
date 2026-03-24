#include <iostream>
using namespace std;

int main() {
    string password;
    int intentos = 0;

    while (intentos < 2) {
        cout << "Ingrese contraseña: ";
        cin >> password;

        if (password == "1234") {
            cout << "Bienvenido" << endl;
            break;
        }

        intentos++;
    }

    return 0;
}