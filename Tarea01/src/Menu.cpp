#include <iostream>
#include "DataType.h"
#include "Matrix.h"

using namespace std;

int main() {
    char option;

    do {
        cout << "--------------------------------------------------" << endl;
        cout << "\t\t\tMENU" << endl;
        cout << "--------------------------------------------------" << endl;
        cout << "a. Tama�o y rangos de los Tipos de Dato Primitivos" << endl;
        cout << "b. Ejemplo de uso de Tipo de dato Estructurado" << endl;
        cout << "c. Salir" << endl;
        cout << "Ingrese una opci�n: ";
        cin >> option;

        switch (option) {
            case 'a':
                cout << "Tama�o y rangos de los Tipos de Dato Primitivos:" << endl;
                DataType::showData();
                break;
            case 'b':
                cout << "Ejemplo de uso de Tipo de dato Estructurado:" << endl;
                break;
            case 'c':
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opci�n no v�lida. Por favor, seleccione una opci�n v�lida." << endl;
        }
    } while (option != 'c');

    return 0;
}
