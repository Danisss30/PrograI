//Daniela Nohemy Divas Carrillo
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


double calcularSubtotal(int cantidad, double precio) {
    return cantidad * precio;
}

double calcularDescuento(double subtotal, int tipoPago) {
    double descuento = 0;

    if (subtotal >= 500) {
        descuento = descuento + subtotal * 0.05;
    }

    if (tipoPago == 1 && subtotal >= 300) {
        descuento = descuento + subtotal * 0.02;
    }

    return descuento;
}

double calcularTotal(double subtotal, double descuento) {
    return subtotal - descuento;
}


void mostrarMenu() {
    cout << endl;
    cout << "MENU" << endl;
    cout << "1. Registrar venta" << endl;
    cout << "2. Mostrar ventas" << endl;
    cout << "3. Reporte general" << endl;
    cout << "4. Buscar por monto" << endl;
    cout << "5. Salir" << endl;
    cout << "Opcion: ";
}


void registrarVenta() {
    ofstream archivo("ventas_2.txt", ios::app);

    if (!archivo) {
        cout << "Error al abrir archivo" << endl;
        return;
    }

    string cliente, producto;
    int cantidad, tipoPago;
    double precio;

    cin.ignore();

    cout << "Cliente: ";
    getline(cin, cliente);

    cout << "Producto: ";
    getline(cin, producto);

    
    while (true) {
        cout << "Cantidad: ";
        cin >> cantidad;

        if (cantidad > 0) {
            break;
        } else {
            cout << "Error, debe ser mayor a 0" << endl;
            continue;
        }
    }

    
    while (true) {
        cout << "Precio: ";
        cin >> precio;

        if (precio > 0) {
            break;
        } else {
            cout << "Error, debe ser mayor a 0" << endl;
            continue;
        }
    }

    
    while (true) {
        cout << "Tipo de pago (1=Efectivo, 2=Tarjeta, 3=Transferencia): ";
        cin >> tipoPago;

        if (tipoPago >= 1 && tipoPago <= 3) {
            break;
        } else {
            cout << "Opcion invalida" << endl;
            continue;
        }
    }

    double sub = calcularSubtotal(cantidad, precio);
    double desc = calcularDescuento(sub, tipoPago);
    double tot = calcularTotal(sub, desc);

    string pago;

    switch (tipoPago) {
        case 1: pago = "Efectivo"; break;
        case 2: pago = "Tarjeta"; break;
        case 3: pago = "Transferencia"; break;
    }

    archivo << cliente << "," << producto << "," << cantidad << ","
            << precio << "," << sub << "," << desc << ","
            << tot << "," << pago << endl;

    archivo.close();

    cout << "Venta guardada" << endl;
}


void mostrarVentas() {
    ifstream archivo("ventas_2.txt");

    if (!archivo) {
        cout << "No hay archivo" << endl;
        return;
    }

    string linea;

    cout << "VENTAS" << endl;

    while (getline(archivo, linea)) {
        cout << linea << endl;
    }

    archivo.close();
}


void reporteGeneral() {
    ifstream archivo("ventas_2.txt");

    if (!archivo) {
        cout << "No hay datos" << endl;
        return;
    }

    int totalVentas = 0;
    double suma = 0;

    int efectivo = 0;
    int tarjeta = 0;
    int transferencia = 0;
    int conDescuento = 0;

    string linea;

    while (getline(archivo, linea)) {
        totalVentas++;

        int contador = 0;
        string dato = "";
        double total = 0;
        double descuento = 0;
        string pago = "";

        for (int i = 0; i < linea.length(); i++) {

            if (linea[i] == ',') {
                contador++;
                dato = "";
                continue;
            }

            dato = dato + linea[i];

            if (contador == 5) {
                descuento = stod(dato);
            }

            if (contador == 6) {
                total = stod(dato);
            }

            if (contador == 7) {
                pago = dato;
            }
        }

        suma = suma + total;

        if (pago == "Efectivo") efectivo++;
        else if (pago == "Tarjeta") tarjeta++;
        else if (pago == "Transferencia") transferencia++;

        if (descuento > 0) conDescuento++;
    }

    archivo.close();

    if (totalVentas > 0) {
        cout << "Ventas: " << totalVentas << endl;
        cout << "Total: " << suma << endl;
        cout << "Promedio: " << suma / totalVentas << endl;
        cout << "Efectivo: " << efectivo << endl;
        cout << "Tarjeta: " << tarjeta << endl;
        cout << "Transferencia: " << transferencia << endl;
        cout << "Con descuento: " << conDescuento << endl;
    } else {
        cout << "No hay datos" << endl;
    }
}


void buscarPorMonto() {
    ifstream archivo("ventas_2.txt");

    double monto;
    cout << "Monto minimo: ";
    cin >> monto;

    string linea;
    bool encontrado = false;

    while (getline(archivo, linea)) {

        int contador = 0;
        string dato = "";
        double total = 0;

        for (int i = 0; i < linea.length(); i++) {

            if (linea[i] == ',') {
                contador++;
                dato = "";
                continue;
            }

            dato = dato + linea[i];

            if (contador == 6) {
                total = stod(dato);
            }
        }

        if (total >= monto) {
            cout << linea << endl;
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "No se encontraron resultados" << endl;
    }

    archivo.close();
}


int main() {

    cout << "Nombre: Daniela Nohemy Divas Carrillo" << endl;

    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1: registrarVenta(); break;
            case 2: mostrarVentas(); break;
            case 3: reporteGeneral(); break;
            case 4: buscarPorMonto(); break;
            case 5: cout << "Bye" << endl; break;
            default:
                cout << "Opcion invalida" << endl;
                continue;
        }

    } while (opcion != 5);

    return 0;
}                                     