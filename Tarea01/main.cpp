#include <iostream>

#include "DataType.h"
#include "Matrix.h"

using namespace std;

int main()
{
    char option;

    do
        {
            setlocale(LC_CTYPE, "spanish");
            cout<<"--------------------------------------------------"<<endl;
            cout<<"\t\t\tMENU"<<endl;
            cout<<"--------------------------------------------------"<<endl;
            cout<<"a. Tamaño y rangos de los Tipos de Dato Primitivos"<<endl;
            cout<<"b. Ejemplo de uso de Tipo de dato Estructurado"<<endl;
            cout<<"c. Salir"<<endl;
            cout<<"Ingrese una opción: ";
            cin>>option;

        switch(option)
        {
            case 'a':
                cout<<"Tamaño y rangos de los Tipos de Dato Primitivos:"<<endl;
                DataType::showData();
                break;

            case 'b':
                {
                    cout<<"Ejemplo de uso de Tipo de dato Estructurado:"<<endl;
                    int N;
                    cout<<"Ingrese el tamaño de la matriz (entre 3 y 10): ";
                    cin>>N;

                    if(N < 3 || N > 10)
                        {
                            cout << "Tamaño de matriz no válido. Debe estar entre 3 y 10." << endl;
                            break;
                        }

                    Matrix A(N), B(N);
                    A.fillRandom();
                    B.fillRandom();

                    Matrix C = A * B;
                    Matrix D = A + B;

                    cout<<"Matriz A:"<<endl;
                    cout<<"------------------------------------------------------------------------------------"<<endl;
                    A.print();
                    cout<<endl;

                    cout<<"Matriz B:"<<endl;
                    cout<<"------------------------------------------------------------------------------------"<<endl;
                    B.print();
                    cout<<endl;

                    cout<<"Multiplicación: Matriz C"<<endl;
                    cout<<"------------------------------------------------------------------------------------"<<endl;
                    C.print();
                    cout<<endl;

                    cout<<"Suma: Matriz D"<<endl;
                    cout<<"------------------------------------------------------------------------------------"<<endl;
                    D.print();
                    cout<<endl;

                    break;
                }

            case 'c':
                cout<<"Programa finalizado."<<endl;
                break;
            default:
                cout<<"Opción no válida. Seleccione una opcián válida."<<endl;
        }
    }
    while (option != 'c');

    return 0;
}
