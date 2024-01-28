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
        cout << "a. Tamaño y rangos de los Tipos de Dato Primitivos" << endl;
        cout << "b. Ejemplo de uso de Tipo de dato Estructurado" << endl;
        cout << "c. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> option;

        switch (option) {
            case 'a':
                cout << "Tamaño y rangos de los Tipos de Dato Primitivos:" << endl;
                DataType::showData();
                break;
            case 'b':
                cout << "Ejemplo de uso de Tipo de dato Estructurado:" << endl;
                break;
            case 'c':
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción no válida. Por favor, seleccione una opción válida." << endl;
        }
    } while (option != 'c');

    return 0;
}
