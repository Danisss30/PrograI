#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void mostrarMenu();
void guardarUsuario();
void mostrarUsuarios();

int main() {
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;

        if (opcion == 1) {
            guardarUsuario();
        } else if (opcion == 2) {
            mostrarUsuarios();
        }

    } while (opcion != 3);

    cout << "Programa finalizado" << endl;

    return 0;
}

void mostrarMenu() {
    cout << "MENU" << endl;
    cout << "1. Guardar usuario" << endl;
    cout << "2. Mostrar usuarios" << endl;
    cout << "3. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

void guardarUsuario() {
    ofstream archivo;
    archivo.open("usuarios.txt", ios::app);

    string nombre;
    string puesto;
    int edad;

    cin.ignore();

    cout << "Ingrese nombre completo: ";
    getline(cin, nombre);

    cout << "Ingrese puesto: ";
    getline(cin, puesto);

    cout << "Ingrese edad: ";
    cin >> edad;

    archivo << nombre << "," << puesto << "," << edad << endl;

    archivo.close();

    cout << "Usuario guardado correctamente" << endl;
}

void mostrarUsuarios() {
    ifstream archivo;
    archivo.open("usuarios.txt");

    string linea;

    cout << "Lista de usuarios:" << endl;

    while (getline(archivo, linea)) {
        cout << linea << endl;
    }

    archivo.close();
}