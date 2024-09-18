#include <iostream>
#include <string>
using namespace std;

const int MAX_PRODUCTOS = 10;

struct Producto {
    string nombre;
    double importe;
};

void crearEncabezadoFactura(string& nombreCliente, string& ruc, string& fecha) {
    
    cout << "--------------------------------------------" << endl;
    cout << "                FACTURA                     " << endl;
    cout << "--------------------------------------------" << endl;
    cout << "                   " << endl;
    cout << "Numero de Factura: " << "0001" << endl;
    cout << "Fecha de Emision: " << fecha << endl;
    cout << "                   " << endl;
    cout << "--------------------------------------------" << endl;
    cout << "DATOS DEL CLIENTE" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "Nombre del Cliente: " << nombreCliente << endl;
    cout << "RUC: " << ruc << endl;
	cout << "                   " << endl;

}

void calcularFactura(Producto productos[], int cantidad, double tasaIVA) {
    double subtotal = 0.0;
    double iva = 0.0;
    double total = 0.0;

    for (int i = 0; i < cantidad; ++i) {
        subtotal += productos[i].importe;
    }

    iva = subtotal * tasaIVA;
    total = subtotal + iva;
    
    

    cout << "--------------------------------------------" << endl;
    cout << "DETALLES DE LOS PRODUCTOS" << endl;
    cout << "--------------------------------------------" << endl;
    for (int i = 0; i < cantidad; ++i) {
        cout << "Producto " << i + 1 << ": " << productos[i].nombre << " - Precio: $" << productos[i].importe << endl;
    }
    cout << "                   " << endl;
    cout << "--------------------------------------------" << endl;
    cout << "DETALLES DE LA FACTURA " << endl;
    cout << "--------------------------------------------" << endl;
    cout << "Subtotal: $" << subtotal << endl;
    cout << "IVA(15%): $" << iva << endl;
    cout << "                   " << endl;
    cout << "Total a pagar: $" << total << endl;
    cout << "                   " << endl;
    cout << "--------------------------------------------" << endl;
    cout << "Gracias por su compra." << endl;
}

int main() {
    string nombreCliente;
    string ruc;
    string fecha;
    Producto productos[MAX_PRODUCTOS];
    int cantidadProductos = 0;
    double tasaIVA = 0.15;
   
    cout << "Ingrese el nombre del cliente: ";
    cin >> nombreCliente;
 
    
    cout << "Ingrese el RUC: ";
    cin >> ruc;
    
    cout << "Ingrese la fecha: ";
    cin >> fecha;
    
    cout << "Ingrese la cantidad de productos: ";
    cin >> cantidadProductos;
    cin.ignore(); 

    if(cantidadProductos > MAX_PRODUCTOS) {
        cout << "La cantidad de productos no puede exceder de " << MAX_PRODUCTOS << "." << endl;
        return 1;
    }

    for(int i = 0; i < cantidadProductos; ++i) {
        cout << "Ingrese el nombre del producto " << i + 1 << ": ";
        getline(cin, productos[i].nombre);
        cout << "Ingrese el precio del producto " << i + 1 << ": ";
        cin >> productos[i].importe;
        cin.ignore();
    }

    crearEncabezadoFactura(nombreCliente, ruc, fecha);
    calcularFactura(productos, cantidadProductos, tasaIVA);

    return 0;
}

