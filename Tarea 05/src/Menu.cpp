#include "Menu.hpp"

using namespace std;

Menu::Menu(List<Song>* lista) : myList(lista), opc(0) {}

int Menu::interfaz()
{
    setlocale(LC_CTYPE, "spanish");
    do
    {
        showMenu();
        if (opc == 1)
        {
            anadirCancion();

        }
        else if (opc == 2)
        {
            especificoAnadir();
        }
        else if (opc == 3)
        {
            buscarCancion();
        }
        else if (opc == 4)
        {
            eliminarCancion();
        }

    }
    while (opc != 5);
    return 0;
}

void Menu::showMenu()
{
    int op;
    cout << "\t\t\t\tLISTA DE EXITOS" << endl
         << "-------------------------------------------------------------------------------------------------------" << endl;
    myList->print();
    cout << "-------------------------------------------------------------------------------------------------------" << endl;
    cout << "1.- A�adir nueva canci�n." << endl;
    cout << "2.- A�adir nueva canci�n en un lugar especifico." << endl;
    cout << "3.- Buscar canci�n." << endl;
    cout << "4.- Eliminar canci�n." << endl;
    cout << "5.- Salir." << endl << "-------------------------------------------------------------------------------------------------------" << endl;
    cin >> op;
    setOpc(op);
}

void Menu::anadirCancion()
{
    string str;
    char op;
    cout << endl << "===== A�ADIR CANCI�N ===== " << endl;
    cin.ignore();
    do
    {
        Song canc;

        cout << "Ranking: ";
        getline(cin, str);
        canc.setPosition(atoi(str.c_str()));

        cout << "Canci�n: ";
        getline(cin, str);
        canc.setName(str);

        cout << "Autor: ";
        getline(cin, str);
        canc.setAuthor(str);

        cout << "Interprete: ";
        getline(cin, str);
        canc.setInterpreter(str);

        cout << "Archivo: ";
        getline(cin, str);
        canc.setFileName(str);

        myList->insertData(canc, -1);
        cout << "�Insertar otro? (s/n): ";
        cin >> op;

        cin.ignore();

    }
    while (op == 's');
}

void Menu::especificoAnadir()
{
    char op;
    string str;
    int posi;
    cout << endl << "===== A�ADIR CANCI�N ===== " << endl;
    cin.ignore();
    do
    {
        Song s;

        cout << "Ranking: ";
        getline(cin, str);
        s.setPosition(atoi(str.c_str()));

        cout << "Canci�n: ";
        getline(cin, str);
        s.setName(str);

        cout << "Autor: ";
        getline(cin, str);
        s.setAuthor(str);

        cout << "Interprete: ";
        getline(cin, str);
        s.setInterpreter(str);

        cout << "Archivo: ";
        getline(cin, str);
        s.setFileName(str);

        do
        {
            cout << "Posici�n especifica (0-" << myList->getLastPos() + 1 << "): ";
            cin >> posi;
            if (posi < 0 || posi > myList->getLastPos() + 1)
            {
                cout << "Posici�n invalida, intente de nuevo." << endl;
            }
        }
        while (posi < 0 || posi > myList->getLastPos() + 1);

        myList->insertData(s, posi - 1);

        cout << "�Insertar otro? (s/n): ";
        cin >> op;
        cin.ignore();
    }
    while (op == 's');
}

void Menu::buscarCancion()
{
    int dec, pos;
    string str;
    cout << endl << "------------------------------------------" << endl << "1.- Buscar por nombre de la canci�n" << endl;
    cout << "2.- Buscar por nombre del interprete" << endl << "------------------------------------------" << endl;
    cin >> dec;
    cin.ignore();
    if (dec == 1)
    {
        cout << "Ingrese el nombre de la canci�n " << endl;

        getline(cin, str);
        Song s;
        s.setName(str);
        pos = myList->findDataBinary(s);
        cout << endl << "------------------------------------------------------------------------------------------------" << endl;
        cout << "EN BUSQUEDA BINARIA" << endl << "La canci�n " << str;
        if (pos == -1)
        {
            cout << " no se encuentra en el listado" << endl;
            cout << "------------------------------------------------------------------------------------------------" << endl;
        }
        else
        {
            cout << " se encuentra en la posici�n " << pos << endl;
            cout << myList->retrieve(pos) << endl;
            cout << "------------------------------------------------------------------------------------------------" << endl;
        }
        pos = myList->findDataLinear(s);
        cout << endl << "------------------------------------------------------------------------------------------------" << endl;
        cout << "EN BUSQUEDA LINEAL" << endl << "La canci�n " << str;
        if (pos == -1)
        {
            cout << " no se encuentra en el listado" << endl;
            cout << "------------------------------------------------------------------------------------------------" << endl;
        }
        else
        {
            cout << "se encuentra en la posici�n " << pos << endl;
            cout << myList->retrieve(pos) << endl;
            cout << "------------------------------------------------------------------------------------------------" << endl;
        }
    }
    else if (dec == 2)
    {
        cout << "Ingrese el nombre del interprete " << endl;
        getline(cin, str);
        Song s;
        s.setInterpreter(str);
        pos = myList->findDataBinary(s);
        cout << endl << "------------------------------------------------------------------------------------------------" << endl;
        cout << "EN BUSQUEDA BINARIA" << endl << "El interprete " << str;

        if (pos == -1)
        {
            cout << " no se encuentra en el listado" << endl;
            cout << "------------------------------------------------------------------------------------------------" << endl;
        }
        else
        {
            cout << " se encuentra en la posici�n " << pos << endl;
            cout << myList->retrieve(pos) << endl;
            cout << "------------------------------------------------------------------------------------------------" << endl;
        }

        pos = myList->findDataLinear(s);
        cout << endl << "------------------------------------------------------------------------------------------------" << endl;
        cout << "EN BUSQUEDA LINEAL" << endl << "El interprete " << str;

        if (pos == -1)
        {
            cout << " no se encuentra en el listado" << endl;
            cout << "------------------------------------------------------------------------------------------------" << endl;
        }
        else
        {
            cout << " se encuentra en la posici�n " << pos << endl;
            cout << myList->retrieve(pos) << endl;
            cout << "------------------------------------------------------------------------------------------------" << endl;
        }
    }
}

void Menu::eliminarCancion()
{
    int pos;
    cout << endl << "===== ELIMINAR CANCI�N =====" << endl;
    cout << "�Posici�n a eliminar?" << endl;
    cin >> pos;

    myList->deleteData(pos - 1);

}
