//Daniela Nohemy Divas Carrillo
#include <iostream>
using namespace std;

int main() {

    float nota;
    float suma = 0;
    float promedio;
    int aprobadas = 0;
    int reprobadas = 0;

    cout << "CONTROL DE CALIFICACIONES" << endl;

    for (int i = 1; i <= 5; i++) {
        cout << "Ingrese la nota " << i << ": ";
        cin >> nota;

        suma = suma + nota;

        if (nota >= 61) {
            aprobadas = aprobadas + 1;
        } else {
            reprobadas = reprobadas + 1;
        }
    }

    promedio = suma / 5;

    cout << "Suma total: " << suma << endl;
    cout << "Promedio: " << promedio << endl;
    cout << "Notas aprobadas: " << aprobadas << endl;
    cout << "Notas reprobadas: " << reprobadas << endl;

    if (promedio >= 61) {
        cout << "Resultado final: Aprueba" << endl;
    } else {
        cout << "Resultado final: Reprueba" << endl;
    }

    return 0;
}