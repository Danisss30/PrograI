#include <iostream>
using namespace std;

int main() {
    string password;

    cout << "Ingrese la contraseña: ";
    cin >> password;

    if (password == "1234") {
        cout << "Correcto" << endl;
    } else {
        cout << "Incorrecto" << endl;
    }

    return 0;
}