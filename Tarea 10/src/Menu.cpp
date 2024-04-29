#include "Menu.hpp"
#include "List.hpp"

using namespace std;

Menu::Menu() {}

void Menu::show()
{
    setlocale(LC_CTYPE, "spanish");

    cout << "\t\t\t\t\tPLAYLIST" << endl << "-----------------------------------------------------------------------------------------------------------------" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
    cout << " 1.- A�adir nueva canci�n." << endl;
    cout << " 2.- Buscar canci�n." << endl;
    cout << " 3.- Eliminar canci�n." << endl;
    cout << " 4.- Eliminar lista completa." << endl;
    cout << " 5.- Salir." << endl << "-----------------------------------------------------------------------------------------------------------------" << endl;
    cout << " Seleccione una opcion: ";
}

void Menu::execute()
{
    int op1(0), op2(0), pos, ranking;
    Node<Song> *position;
    List<Song> repertory;
    Song auxSong, searcher;
    string data;

    while (op1 != 5)
    {
        system("cls");
        if (repertory.isEmpty() == false)
        {
            cout << repertory.toString() << endl;
        }
        this->show();
        cin >> op1;

        switch (op1)
        {
            case 1:
                cout << endl << "===== A�ADIR CANCI�N ===== " << endl;
                cout << "\nRanking: "; cin >> ranking;
                auxSong.setRanking(ranking);
                cout << "Canci�n: "; getline(cin, data); getline(cin, data);
                auxSong.setName(data);
                cout << "Archivo: "; getline(cin, data);
                auxSong.setMP3Name(data);
                cout << "Autor: "; getline(cin, data);
                auxSong.setAuthor(data);
                cout << "Inteprete: "; getline(cin, data);
                auxSong.setInterpreter(data);

                if (repertory.isEmpty() == false)
                {
                    cout << "�Despu�s de cual canci�n desea insertar?: ";
                    getline(cin, data);
                    searcher.setName(data);

                if (repertory.findData(searcher, Song::compareBySongName) != nullptr)
                {
                    position = repertory.findData(searcher, Song::compareBySongName);
                    repertory.insertData(position, auxSong);
                } else {
                    cout << "Error, no se reconoce esa canci�n." << endl;
                }
            } else {
                position = nullptr;
                repertory.insertData(position, auxSong);
            }
            break;

            case 2:
                if (!repertory.isEmpty())
                {
                    cout << endl << "------------------------------------------" << endl << "1.- Buscar por nombre de la canci�n." << endl;
                    cout << "2.- Buscar por nombre del interprete." << endl << "------------------------------------------" << endl;
                    cout << " Seleccione una opci�n: "; cin >> op2;

                if (op2 == 1)
                {
                    cout << "Ingrese el nombre de la canci�n: " << endl;
                    getline(cin, data);
                    getline(cin, data);
                    auxSong.setName(data);

                    position = repertory.findData(auxSong, Song::compareBySongName);

                    if (position != nullptr)
                    {
                        cout << "Canci�n encontrada en el archivo: " << position->getData().getMP3Name() << endl;
                    }
                    else {
                        cout << "La canci�n no est� en la playlist." << endl;
                    }

                } else if (op2 == 2)
                {
                    cout << "Ingrese el nombre del interprete: " << endl;
                    getline(cin, data);
                    getline(cin, data);
                    auxSong.setInterpreter(data);

                    position = repertory.findData(auxSong, Song::compareByInterpreter);

                    if (position != nullptr)
                    {
                        cout << "Canci�n encontrada en el archivo: " << position->getData().getMP3Name() << endl;
                    } else {
                        cout << "La canci�n no est� en la playlist." << endl;
                    }
                }
                cout << "Presione enter para continuar." << endl;
                getline(cin, data);

            }
            else {
                cout << "Playlist vac�a." << endl;
                cout << "Presione enter para continuar." << endl;
                break;
            }

            break;

            case 3:
                cout << "\nNombre: ";
                getline(cin, data);
                getline(cin, data);
                auxSong.setName(data);

            if (repertory.findData(auxSong, Song::compareBySongName) != nullptr)
            {
                position = repertory.findData(auxSong, Song::compareBySongName);
                string songName = position->getData().getMP3Name();
                repertory.deleteData(position);
                cout << "Canci�n a eliminar: " << songName << endl;
            } else {
                cout << "Canci�n no encontrada." << endl;
            }
            cout << "Presione enter para continuar." << endl;
            getline(cin, data);

            break;

            case 4:
                cout << "La lista se eliminara completamente..." << endl;
                cout << " 1.- Confirmar. \n 2.. Cancelar." << endl;
                cin >> op2;

                if (op2 == 1)
                {
                    repertory.deleteAll();
                    cout << "La playlist se eliminar� completamente..." << endl;
                    getline(cin, data); getline(cin, data);
                }
                else if (op2 == 2)
                {
                    cout << "Operaci�n cancelada." << endl;
                    getline(cin, data); getline(cin, data);
                }
                break;

            case 5:
                cout << "Saliendo del programa..." << endl;
                break;

            default:
                cout << " Seleccione una opcion valida . . ." << endl;
        }
    }
}
