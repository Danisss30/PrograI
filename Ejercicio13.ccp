#include <iostream>
using namespace std;

int main() {

    string nombre;
    int edad;
    float altura;
    double precio;
    char inicial;

    cout << "Ingrese su nombre: ";
    cin >> nombre;

    cout << "Ingrese su edad: ";
    cin >> edad;

    cout << "Ingrese su altura en metros: ";
    cin >> altura;

    cout << "Ingrese el precio de un producto: ";
    cin >> precio;

    cout << "Ingrese la inicial de su apellido: ";
    cin >> inicial;

    cout << endl;
    cout << "RESUMEN DE DATOS" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
    cout << "Altura: " << altura << endl;
    cout << "Precio del producto: " << precio << endl;
    cout << "Inicial del apellido: " << inicial << endl;

    return 0;
}
