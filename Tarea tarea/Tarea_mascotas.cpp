//Daniela Nohemy Divas Carrillo
#include <iostream>
using namespace std;

struct Mascota {
    string nombre;
    string especie;
    string raza;
    int edad;
    float peso;
};

void registrarMascota(Mascota &m) {
    cin.ignore();

    cout << "Ingrese el nombre de la mascota: ";
    getline(cin, m.nombre);

    cout << "Ingrese la especie: ";
    getline(cin, m.especie);

    cout << "Ingrese la raza: ";
    getline(cin, m.raza);

    cout << "Ingrese la edad: ";
    cin >> m.edad;

    cout << "Ingrese el peso en kg: ";
    cin >> m.peso;

    cout << "Mascota registrada correctamente." << endl;
}

void mostrarMascota(Mascota m) {
    cout << "DATOS DE LA MASCOTA" << endl;
    cout << "Nombre: " << m.nombre << endl;
    cout << "Especie: " << m.especie << endl;
    cout << "Raza: " << m.raza << endl;
    cout << "Edad: " << m.edad << " años" << endl;
    cout << "Peso: " << m.peso << " kg" << endl;
}

void calcularEdadHumana(Mascota m) {
    int edadHumana;

    edadHumana = m.edad * 7;

    cout << "La edad equivalente en años humanos es: ";
    cout << edadHumana << " años" << endl;
}

void clasificarPeso(Mascota m) {
    if (m.peso < 5) {
        cout << "La mascota es pequena." << endl;
    }
    else if (m.peso >= 5 && m.peso <= 20) {
        cout << "La mascota es mediana." << endl;
    }
    else {
        cout << "La mascota es grande." << endl;
    }
}

void modificarDatos(Mascota &m) {
    int opcion;

    cout << "MODIFICAR DATOS" << endl;
    cout << "1. Nombre" << endl;
    cout << "2. Especie" << endl;
    cout << "3. Raza" << endl;
    cout << "4. Edad" << endl;
    cout << "5. Peso" << endl;
    cout << "Seleccione una opcion: ";
    cin >> opcion;

    cin.ignore();

    switch(opcion) {
        case 1:
            cout << "Nuevo nombre: ";
            getline(cin, m.nombre);
            break;

        case 2:
            cout << "Nueva especie: ";
            getline(cin, m.especie);
            break;

        case 3:
            cout << "Nueva raza: ";
            getline(cin, m.raza);
            break;

        case 4:
            cout << "Nueva edad: ";
            cin >> m.edad;
            break;

        case 5:
            cout << "Nuevo peso: ";
            cin >> m.peso;
            break;

        default:
            cout << "Opcion invalida." << endl;
    }

    cout << "Datos modificados correctamente." << endl;
}

int main() {
    Mascota mascota;
    int opcion;

    do {
        cout << "REGISTRO DE MASCOTA" << endl;
        cout << "1. Registrar mascota" << endl;
        cout << "2. Mostrar mascota" << endl;
        cout << "3. Calcular edad equivalente" << endl;
        cout << "4. Clasificar por peso" << endl;
        cout << "5. Modificar datos" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {

            case 1:
                registrarMascota(mascota);
                break;

            case 2:
                mostrarMascota(mascota);
                break;

            case 3:
                calcularEdadHumana(mascota);
                break;

            case 4:
                clasificarPeso(mascota);
                break;

            case 5:
                modificarDatos(mascota);
                break;

            case 6:
                cout << "Saliendo del programa..." << endl;
                break;

            default:
                cout << "Opcion invalida." << endl;
        }

        cout << endl;

    } while(opcion != 6);

    return 0;
}