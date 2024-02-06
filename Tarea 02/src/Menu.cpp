#include "Menu.hpp"

#include <iostream>
#include <conio.h>

using namespace std;

Product Menu::coleccion[500];
Date Menu::fecha2;

void Menu::showMenu()
{
    system("cls");
    cout << "\t-----Inventario de la tienda-----" << endl << endl;
    cout << "1- Añadir producto" << endl;
    cout << "2- Agregar producto existente" << endl;
    cout << "3- Retirar producto" << endl;
    cout << "4- Ver productos" << endl;
    cout << "5- Salir" << endl;
}

void Menu::AddProduct(int& add)
{
    string porc, n, c;
    int exi;
    float men, may, p;
    cout << "Agrega el producto" << endl;
    cout << "Código de barras: " << endl;
    cin >> c;
    coleccion[add].setBarCode(c);
    cout << "Nombre: " << endl;
    cin >> n;
    coleccion[add].setName(n);
    cout << "Peso: " << endl;
    cin >> p;
    coleccion[add].setWeight(p);
    cout << "Día de entrada: " << endl;
    cin >> porc;
    fecha2.setDay(stoi(porc));
    coleccion[add].setFecha(fecha2);
    cout << "Mes de entrada: " << endl;
    cin >> porc;
    fecha2.setMonth(stoi(porc));
    coleccion[add].setFecha(fecha2);
    cout << "Año de entrada: " << endl;
    cin >> porc;
    fecha2.setYear(stoi(porc));
    coleccion[add].setFecha(fecha2);
    cout << "Precio mayoreo: " << endl;
    cin >> may;
    coleccion[add].setMayoreo(may);
    cout << "Precio de menudeo: " << endl;
    cin >> men;
    coleccion[add].setMenudeo(men);
    cout << "Cantidad de exitencias: " << endl;
    cin >> exi;
    coleccion[add].setExistence(exi);
    add++;
}

void Menu::RemoveProduct()
{
    string barcode;
    cout << "Código barra del producto " << endl;
    cin >> barcode;
    int total = 0;
    for (int i = 0; i < 500; i++)
        {
        if (coleccion[i].getBarCode() == barcode)
        {
            cout << "Producto encontrado " << endl;
            int sum;
            cout << "Cantidad del producto que desea quitar " << endl;
            cin >> sum;
            coleccion[i].setExistence(-sum);
            total = 1;
            break;
        }
    }
    if (total == 0)
    {
        cout << "Producto no encontrado" << endl;
    }
    getch();
}

void Menu::AddExistance()
{
    string barcode;
    cout << "Código barra del producto " << endl;
    cin >> barcode;
    int total = 0;
    for (int i = 0; i < 500; i++)
        {
            if (coleccion[i].getBarCode() == barcode)
            {
                cout << "Producto encontrado " << endl;
                int sum;
                cout << "Cantidad del producto que desea agregar " << endl;
                cin >> sum;
                coleccion[i].setExistence(sum);
                total = 1;
                break;
            }
        }
    if (total == 0)
    {
        cout << "Producto no encontrado" << endl;
    }
    getch();
}
void Menu::Collection(int add)
{
    for (int i = 0; i < add; i++)
        {
            cout << "Codigo: " << coleccion[i].getBarCode() << endl;
            cout << "Nombre: " << coleccion[i].getName() << endl;
            cout << "Peso: " << coleccion[i].getWeight() << endl;
            cout << "Fecha de entrada: " << coleccion[i].getFecha().getDay() << "/" << coleccion[i].getFecha().getMonth() << "/" << coleccion[i].getFecha().getYear() << endl;
            cout << "Precio Mayoreo: " << coleccion[i].getMayoreo() << endl;
            cout << "Precio Menudeo: " << coleccion[i].getMenudeo() << endl;
            cout << "Existencias: " << coleccion[i].getExistence() << endl;
            cout << endl;
        }
    getch();
}
