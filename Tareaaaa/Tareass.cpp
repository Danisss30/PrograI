//Daniela Nohemy Divas Carrillo
#include <iostream>
#include <vector>
using namespace std;

float promedioNotas(vector<float> notas) {
    float suma = 0;

    for (int i = 0; i < notas.size(); i++) {
        suma = suma + notas[i];
    }

    float promedio = suma / notas.size();
    return promedio;
}

string estadoEstudiante(float prom) {
    if (prom >= 61) {
        return "Aprobado";
    } else {
        return "Reprobado";
    }
}

string categoriaEstudiante(float prom) {
    if (prom >= 85) {
        return "Excelente";
    } else if (prom >= 70) {
        return "Bueno";
    } else if (prom >= 61) {
        return "Regular";
    } else {
        return "Deficiente";
    }
}

void mostrar(string nombre, string curso, float prom, string estado, string categoria) {
    cout << " RESULTADO FINAL " << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Curso: " << curso << endl;
    cout << "Promedio: " << prom << endl;
    cout << "Estado: " << estado << endl;
    cout << "Categoria: " << categoria << endl;
}

int main() {
    string nombre;
    string curso;
    int cantidad;

    cout << "Ingrese el nombre del estudiante: ";
    getline(cin, nombre);

    cout << "Ingrese el curso: ";
    getline(cin, curso);

    cout << "Ingrese la cantidad de notas: ";
    cin >> cantidad;

    vector<float> notas(cantidad);

    for (int i = 0; i < cantidad; i++) {
        cout << "Ingrese la nota " << i + 1 << ": ";
        cin >> notas[i];
    }

    float prom = promedioNotas(notas);
    string estado = estadoEstudiante(prom);
    string categoria = categoriaEstudiante(prom);

    mostrar(nombre, curso, prom, estado, categoria);

    return 0;
}