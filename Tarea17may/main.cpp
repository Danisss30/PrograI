//Daniela Nohemy Divas Carrillo

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Producto {

    int codigo;
    char nombre[40];
    char categoria[30];
    int stock;
    float precio;
    bool activo;
};

void menu();
void registrarProducto();
void listarProductos();
void pausarSistema();

int main() {

    int opcion;

    do {

        menu();
        cin >> opcion;

        switch(opcion) {

            case 1:

                registrarProducto();
                break;

            case 2:

                listarProductos();
                break;

            case 3:

                cout << endl;
                cout << "Saliendo del sistema..." << endl;
                break;

            default:

                cout << endl;
                cout << "Opcion invalida" << endl;
        }

    } while(opcion != 3);

    return 0;
}

void menu() {

    cout << endl;
    cout << "===============================" << endl;
    cout << " SISTEMA DE VENTAS E INVENTARIO" << endl;
    cout << "===============================" << endl;

    cout << endl;
    cout << "1. Registrar producto" << endl;
    cout << "2. Listar productos" << endl;
    cout << "3. Salir" << endl;

    cout << endl;
    cout << "Seleccione una opcion: ";
}

void registrarProducto() {

    Producto producto;

    ofstream archivo("productos.dat", ios::binary | ios::app);

    if(archivo.fail()) {

        cout << endl;
        cout << "Error al abrir el archivo" << endl;
        return;
    }

    cout << endl;
    cout << "REGISTRO DE PRODUCTO" << endl;

    cout << endl;
    cout << "Ingrese el codigo: ";
    cin >> producto.codigo;

    cin.ignore();

    cout << "Ingrese el nombre: ";
    cin.getline(producto.nombre, 40);

    cout << "Ingrese la categoria: ";
    cin.getline(producto.categoria, 30);

    cout << "Ingrese el stock: ";
    cin >> producto.stock;

    cout << "Ingrese el precio: ";
    cin >> producto.precio;

    producto.activo = true;

    archivo.write((char*)&producto, sizeof(Producto));

    archivo.close();

    cout << endl;
    cout << "Producto guardado correctamente" << endl;

    pausarSistema();
}

void listarProductos() {

    Producto producto;

    ifstream archivo("productos.dat", ios::binary);

    if(archivo.fail()) {

        cout << endl;
        cout << "No hay productos registrados" << endl;

        pausarSistema();
        return;
    }

    cout << endl;
    cout << "LISTA DE PRODUCTOS" << endl;

    while(archivo.read((char*)&producto, sizeof(Producto))) {

        cout << endl;
        cout << "Codigo: " << producto.codigo << endl;
        cout << "Nombre: " << producto.nombre << endl;
        cout << "Categoria: " << producto.categoria << endl;
        cout << "Stock: " << producto.stock << endl;
        cout << "Precio: Q" << producto.precio << endl;

        if(producto.activo == true) {

            cout << "Activo: Si" << endl;
        }
        else {

            cout << "Activo: No" << endl;
        }

        cout << "--------------------------------" << endl;
    }

    archivo.close();

    pausarSistema();
}

void pausarSistema() {

    cin.ignore();

    cout << endl;
    cout << "Presione Enter para continuar...";
    cin.get();
}