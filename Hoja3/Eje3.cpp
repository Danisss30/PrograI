//Daniela Nohemy Divas Carrillo

#include <iostream>
using namespace std;

int main() {
    string password;

    cout << "Ingrese la contraseña: ";
    cin >> password;

    while (password != "1234") {
        cout << "Error: contraseña incorrecta" << endl;
        cout << "Intente nuevamente: ";
        cin >> password;
    }

    cout << "Acceso permitido" << endl;

    return 0;
}
