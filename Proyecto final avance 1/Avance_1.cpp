//Daniela Nohemy Divas Carrillo

#include <iostream>
#include <fstream>
#include <cstring>
#include <stdexcept>
#include <cmath>

using namespace std;

struct Producto
{
    int codigo;
    char nombre[50];
    float precio;
    int stock;
    bool activo;
    int vendidos;
};

struct DetalleVenta
{
    int codigoProducto;
    int cantidad;
    float precioUnitario;
    float subtotal;
};

struct Venta
{
    int numeroVenta;
    char fecha[20];

    int cantidadProductos;

    DetalleVenta detalles[20];

    float subtotal;
    float iva;
    float descuento;
    float total;
};

void registrarProducto();
void listarProductos();
void buscarPorCodigo();
void buscarPorNombre();
void actualizarStock();
void modificarPrecio();
void desactivarProducto();

void crearVenta();

int main()
{
    int opcion;

    do
    {
        cout << endl;
        cout << "====================================" << endl;
        cout << " SISTEMA DE VENTAS E INVENTARIO " << endl;
        cout << "====================================" << endl;
        cout << endl;

        cout << "1. Registrar producto" << endl;
        cout << "2. Listar productos" << endl;
        cout << "3. Buscar por codigo" << endl;
        cout << "4. Buscar por nombre" << endl;
        cout << "5. Actualizar stock" << endl;
        cout << "6. Modificar precio" << endl;
        cout << "7. Desactivar producto" << endl;
        cout << "8. Crear venta" << endl;
        cout << "9. Salir" << endl;

        cout << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion)
        {
            case 1:
                registrarProducto();
                break;

            case 2:
                listarProductos();
                break;

            case 3:
                buscarPorCodigo();
                break;

            case 4:
                buscarPorNombre();
                break;

            case 5:
                actualizarStock();
                break;

            case 6:
                modificarPrecio();
                break;

            case 7:
                desactivarProducto();
                break;

            case 8:
                crearVenta();
                break;

            case 9:
                cout << "Programa finalizado." << endl;
                break;

           
            default:
                cout << "Opcion invalida." << endl;
        }

    }
    while(opcion != 9);

    return 0;
}


void registrarProducto()
{
    Producto p;

    try
    {
        ofstream archivo(
        "productos.dat",
        ios::binary | ios::app);

        if(!archivo)
        {
            throw runtime_error(
            "Error al abrir archivo");
        }

        cout << "Codigo: ";
        cin >> p.codigo;

        cin.ignore();

        cout << "Nombre: ";
        cin.getline(p.nombre,50);

        cout << "Precio: ";
        cin >> p.precio;

        cout << "Stock: ";
        cin >> p.stock;

        p.activo = true;
        p.vendidos = 0;

        archivo.write(
        (char*)&p,
        sizeof(Producto));

        archivo.close();

        cout << "Producto registrado." << endl;
    }
    catch(exception& e)
    {
        cout << e.what() << endl;
    }
}


void listarProductos()
{
    Producto p;

    ifstream archivo(
    "productos.dat",
    ios::binary);

    if(!archivo)
    {
        cout << "No existe archivo." << endl;
        return;
    }

    cout << endl;
    cout << "LISTA DE PRODUCTOS" << endl;

    while(
    archivo.read(
    (char*)&p,
    sizeof(Producto)))
    {
        if(p.activo)
        {
            cout << endl;
            cout << "Codigo: ";
            cout << p.codigo << endl;

            cout << "Nombre: ";
            cout << p.nombre << endl;

            cout << "Precio: Q";
            cout << p.precio << endl;

            cout << "Stock: ";
            cout << p.stock << endl;

            cout << "Vendidos: ";
            cout << p.vendidos << endl;
        }
    }

    archivo.close();
}


void buscarPorCodigo()
{
    Producto p;

    int codigo;

    bool encontrado = false;

    cout << "Codigo a buscar: ";
    cin >> codigo;

    ifstream archivo(
    "productos.dat",
    ios::binary);

    while(
    archivo.read(
    (char*)&p,
    sizeof(Producto)))
    {
        if(p.codigo == codigo &&
           p.activo)
        {
            encontrado = true;

            cout << endl;
            cout << "Nombre: ";
            cout << p.nombre << endl;

            cout << "Precio: ";
            cout << p.precio << endl;

            cout << "Stock: ";
            cout << p.stock << endl;
        }
    }

    archivo.close();

    if(!encontrado)
    {
        cout << "Producto no encontrado." << endl;
    }
}


void buscarPorNombre()
{
    Producto p;

    char nombre[50];

    bool encontrado = false;

    cin.ignore();

    cout << "Nombre: ";
    cin.getline(nombre,50);

    ifstream archivo(
    "productos.dat",
    ios::binary);

    while(
    archivo.read(
    (char*)&p,
    sizeof(Producto)))
    {
        if(strcmp(p.nombre,nombre)==0
        && p.activo)
        {
            encontrado = true;

            cout << endl;
            cout << "Codigo: ";
            cout << p.codigo << endl;

            cout << "Precio: ";
            cout << p.precio << endl;

            cout << "Stock: ";
            cout << p.stock << endl;
        }
    }

    archivo.close();

    if(!encontrado)
    {
        cout << "Producto no encontrado." << endl;
    }
}


void actualizarStock()
{
    Producto p;

    int codigo;
    int nuevoStock;

    bool encontrado = false;

    fstream archivo(
    "productos.dat",
    ios::binary | ios::in | ios::out);

    cout << "Codigo del producto: ";
    cin >> codigo;

    while(
    archivo.read(
    (char*)&p,
    sizeof(Producto)))
    {
        if(p.codigo == codigo &&
           p.activo)
        {
            cout << "Nuevo stock: ";
            cin >> nuevoStock;

            p.stock = nuevoStock;

            archivo.seekp(
            -sizeof(Producto),
            ios::cur);

            archivo.write(
            (char*)&p,
            sizeof(Producto));

            encontrado = true;

            cout << "Stock actualizado." << endl;

            break;
        }
    }

    archivo.close();

    if(!encontrado)
    {
        cout << "Producto no encontrado." << endl;
    }
}


void modificarPrecio()
{
    Producto p;

    int codigo;

    float nuevoPrecio;

    bool encontrado = false;

    fstream archivo(
    "productos.dat",
    ios::binary | ios::in | ios::out);

    cout << "Codigo del producto: ";
    cin >> codigo;

    while(
    archivo.read(
    (char*)&p,
    sizeof(Producto)))
    {
        if(p.codigo == codigo &&
           p.activo)
        {
            cout << "Nuevo precio: ";
            cin >> nuevoPrecio;

            p.precio = nuevoPrecio;

            archivo.seekp(
            -sizeof(Producto),
            ios::cur);

            archivo.write(
            (char*)&p,
            sizeof(Producto));

            encontrado = true;

            cout << "Precio actualizado." << endl;

            break;
        }
    }

    archivo.close();

    if(!encontrado)
    {
        cout << "Producto no encontrado." << endl;
    }
}


void desactivarProducto()
{
    Producto p;

    int codigo;

    bool encontrado = false;

    fstream archivo(
    "productos.dat",
    ios::binary | ios::in | ios::out);

    cout << "Codigo del producto: ";
    cin >> codigo;

    while(
    archivo.read(
    (char*)&p,
    sizeof(Producto)))
    {
        if(p.codigo == codigo &&
           p.activo)
        {
            p.activo = false;

            archivo.seekp(
            -sizeof(Producto),
            ios::cur);

            archivo.write(
            (char*)&p,
            sizeof(Producto));

            encontrado = true;

            cout << "Producto desactivado." << endl;

            break;
        }
    }

    archivo.close();

    if(!encontrado)
    {
        cout << "Producto no encontrado." << endl;
    }
}


void crearVenta()
{
    Venta venta;

    cout << "Fecha (dd/mm/aaaa): ";
    cin >> venta.fecha;

    venta.subtotal = 0;
    venta.iva = 0;
    venta.descuento = 0;
    venta.total = 0;

    int totalArticulos = 0;

    cout << "Cantidad de productos: ";
    cin >> venta.cantidadProductos;

    for(int i = 0;
        i < venta.cantidadProductos;
        i++)
    {
        int codigo;
        int cantidad;

        cout << endl;

        cout << "Codigo producto: ";
        cin >> codigo;

        cout << "Cantidad: ";
        cin >> cantidad;

        Producto p;

        bool encontrado = false;


fstream archivo("productos.dat", ios::binary | ios::in | ios::out);

if(!archivo.is_open())
{
    cout << "Error al abrir archivo de productos." << endl;
    return;
}

while(archivo.read((char*)&p, sizeof(Producto)))
{
    if(p.codigo == codigo && p.activo)
    {
        encontrado = true;

        if(cantidad > p.stock)
        {
            cout << "Stock insuficiente." << endl;
            archivo.close();
            break;
        }

        venta.detalles[i].codigoProducto = codigo;
        venta.detalles[i].cantidad = cantidad;
        venta.detalles[i].precioUnitario = p.precio;
        venta.detalles[i].subtotal = cantidad * p.precio;

        venta.subtotal += venta.detalles[i].subtotal;
        totalArticulos += cantidad;

        p.stock -= cantidad;
        p.vendidos += cantidad;

        archivo.seekp(-sizeof(Producto), ios::cur);
        archivo.write((char*)&p, sizeof(Producto));

        cout << "Producto agregado." << endl;

        break;
    }
}

        archivo.close();

        if(!encontrado)
        {
            cout << "Producto no encontrado." << endl;

        }
    }

    venta.iva =
    venta.subtotal * 0.12;

    if(venta.subtotal > 500)
    {
        venta.descuento =
        venta.descuento +
        (venta.subtotal * 0.05);
    }

    if(totalArticulos % 5 == 0)
    {
        venta.descuento =
        venta.descuento + 10;
    }

    venta.total =
    venta.subtotal +
    venta.iva -
    venta.descuento;

    venta.total =
    round(
        venta.total * 100)
    / 100;

    cout << endl;
    cout << "Subtotal: Q";
    cout << venta.subtotal << endl;

    cout << "IVA: Q";
    cout << venta.iva << endl;

    cout << "Descuento: Q";
    cout << venta.descuento << endl;

    cout << "Total: Q";
    cout << venta.total << endl;

    ofstream guardarVenta(
    "ventas.dat",
    ios::binary |
    ios::app);

    guardarVenta.write(
    (char*)&venta,
    sizeof(Venta));

    guardarVenta.close();

    cout << endl;
    cout << "Venta guardada correctamente." << endl;
}     