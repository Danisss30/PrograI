//Daniela Nohemy Divas Carrillo
#include <iostream>
using namespace std;

int main() {

    int meses;
    float ahorro;
    float total = 0;
    float promedio;
    float mayor = 0;
    int mesMayor = 0;
    int contador = 0;

    cout << "CAJERO DE AHORRO" << endl;

    cout << "Ingrese la cantidad de meses: ";
    cin >> meses;

    for (int i = 1; i <= meses; i++) {
        cout << "Ingrese el ahorro del mes " << i << ": ";
        cin >> ahorro;

        total = total + ahorro;

        if (ahorro > mayor) {
            mayor = ahorro;
            mesMayor = i;
        }

        if (ahorro >= 500) {
            contador = contador + 1;
        }
    }

    promedio = total / meses;

    cout << "Total ahorrado: Q" << total << endl;
    cout << "Promedio mensual: Q" << promedio << endl;
    cout << "Mayor ahorro en el mes: " << mesMayor << endl;
    cout << "Meses con ahorro mayor o igual a Q500: " << contador << endl;

    return 0;
}