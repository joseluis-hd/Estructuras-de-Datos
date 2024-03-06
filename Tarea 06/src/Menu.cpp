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
            addSong();
        }
        else if (opc == 2)
        {
            specificAdd();
        }
        else if (opc == 3)
        {
            searchSong();
        }
        else if (opc == 4)
        {
            deleteSong();
        }
        else if (opc == 5)
        {
            ordList();
        }

    } while (opc != 6);
    return 0;
}

void Menu::showMenu()
{
    int op;
    cout << "\t\t\t\tPLAYLIST" << endl
         << "-----------------------------------------------------------------------------------------------------------------" << endl;
    myList->print();
    cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
    cout << "1.- Añadir nueva canción." << endl;
    cout << "2.- Añadir nueva canción en un lugar especifico." << endl;
    cout << "3.- Buscar canción." << endl;
    cout << "4.- Eliminar canción." << endl;
    cout << "5.- Ordenar lista." << endl;
    cout << "6.- Salir." << endl << "-----------------------------------------------------------------------------------------------------------------" << endl;
    cin >> op;
    setOpc(op);
}

void Menu::addSong()
{
    string str;
    char op;
    cout << endl << "===== AÑADIR CANCIÓN ===== " << endl;
    cin.ignore();
    do
    {
        Song canc;

        cout << "Ranking: ";
        getline(cin, str);
        canc.setPosition(atoi(str.c_str()));

        cout << "Canción: ";
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
        cout << "¿Insertar otro? (s/n): ";
        cin >> op;

        cin.ignore();

    } while (op == 's');
}

void Menu::specificAdd()
{
    char op;
    string str;
    int posi;
    cout << endl << "===== AÑADIR CANCIÓN ===== " << endl;
    cin.ignore();
    do
    {
        Song s;

        cout << "Ranking: ";
        getline(cin, str);
        s.setPosition(atoi(str.c_str()));

        cout << "Canción: ";
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
            cout << "Posición especifica (0-" << myList->getLastPos() + 1 << "): ";
            cin >> posi;
            if (posi < 0 || posi > myList->getLastPos() + 1)
            {
                cout << "Posición invalida, intente de nuevo." << endl;
            }
        } while (posi < 0 || posi > myList->getLastPos() + 1);

        myList->insertData(s, posi - 1);

        cout << "¿Insertar otro? (s/n): ";
        cin >> op;
        cin.ignore();
    } while (op == 's');
}

void Menu::searchSong()
{
    int dec, pos;
    string str;
    cout << endl << "------------------------------------------" << endl << "1.- Buscar por nombre de la canción" << endl;
    cout << "2.- Buscar por nombre del interprete" << endl << "------------------------------------------" << endl;
    cin >> dec;
    cin.ignore();
    if (dec == 1)
    {
        cout << "Ingrese el nombre de la canción " << endl;

        getline(cin, str);
        Song s;
        s.setName(str);
        pos = myList->findDataBinary(s);
        cout << endl << "------------------------------------------------------------------------------------------------" << endl;
        cout << "EN BUSQUEDA BINARIA" << endl << "La canción " << str;
        if (pos == -1)
        {
            cout << " no se encuentra en el listado" << endl;
            cout << "------------------------------------------------------------------------------------------------" << endl;
        }
        else
        {
            cout << " se encuentra en la posición " << pos << endl;
            cout << myList->retrieve(pos) << endl;
            cout << "------------------------------------------------------------------------------------------------" << endl;
        }
        pos = myList->findDataLinear(s);
        cout << endl << "------------------------------------------------------------------------------------------------" << endl;
        cout << "EN BUSQUEDA LINEAL" << endl << "La canción " << str;
        if (pos == -1)
        {
            cout << " no se encuentra en el listado" << endl;
            cout << "------------------------------------------------------------------------------------------------" << endl;
        }
        else
        {
            cout << "se encuentra en la posición " << pos << endl;
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
            cout << " se encuentra en la posición " << pos << endl;
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
            cout << " se encuentra en la posición " << pos << endl;
            cout << myList->retrieve(pos) << endl;
            cout << "------------------------------------------------------------------------------------------------" << endl;
        }
    }
}

void Menu::deleteSong()
{
    int pos;
    cout << endl << "===== ELIMINAR CANCIÓN =====" << endl;
    cout << "¿Posición a eliminar?" << endl;
    cin >> pos;

    myList->deleteData(pos - 1);
}

void Menu::ordList()
{
    int option;
    cout << endl << "------------------------------------------" << endl << "Seleccione el criterio de ordenamiento:" << endl;
    cout << "1.- Ordenar por nombre de la canción" << endl;
    cout << "2.- Ordenar por nombre del intérprete" << endl;
    cout << "------------------------------------------" << endl;
    cin >> option;

    cout << endl << "------------------------------------------" << endl << "Seleccione el método de ordenamiento:" << endl;
    cout << "1.- BubbleSort" << endl;
    cout << "2.- InsertSort" << endl;
    cout << "3.- SelectSort" << endl;
    cout << "4.- ShellSort" << endl;
    cout << "------------------------------------------" << endl;
    int sortOption;
    cin >> sortOption;

    switch (option)
    {
    case 1:
        switch (sortOption)
        {
        case 1:
            myList->bubbleSort();
            break;
        case 2:
            myList->insertSort();
            break;
        case 3:
            myList->selectSort();
            break;
        case 4:
            myList->shellSort();
            break;
        default:
            cout << "Opción inválida." << endl;
            break;
        }
        break;
    case 2:
        switch (sortOption)
        {
        case 1:
            myList->bubbleSortByInterpreter();
            break;
        case 2:
            myList->insertSortByInterpreter();
            break;
        case 3:
            myList->selectSortByInterpreter();
            break;
        case 4:
            myList->shellSortByInterpreter();
            break;
        default:
            cout << "Opción inválida." << endl;
            break;
        }
        break;
    default:
        cout << "Opción inválida." << endl;
        break;
    }
}
