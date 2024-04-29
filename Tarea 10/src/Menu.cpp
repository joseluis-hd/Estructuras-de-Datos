#include "Menu.hpp"
#include "List.hpp"

using namespace std;

Menu::Menu() {}

void Menu::show()
{
    setlocale(LC_CTYPE, "spanish");

    cout << "\t\t\t\t\tPLAYLIST" << endl << "-----------------------------------------------------------------------------------------------------------------" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
    cout << " 1.- Añadir nueva canción." << endl;
    cout << " 2.- Buscar canción." << endl;
    cout << " 3.- Eliminar canción." << endl;
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
                cout << endl << "===== AÑADIR CANCIÓN ===== " << endl;
                cout << "\nRanking: "; cin >> ranking;
                auxSong.setRanking(ranking);
                cout << "Canción: "; getline(cin, data); getline(cin, data);
                auxSong.setName(data);
                cout << "Archivo: "; getline(cin, data);
                auxSong.setMP3Name(data);
                cout << "Autor: "; getline(cin, data);
                auxSong.setAuthor(data);
                cout << "Inteprete: "; getline(cin, data);
                auxSong.setInterpreter(data);

                if (repertory.isEmpty() == false)
                {
                    cout << "¿Después de cual canción desea insertar?: ";
                    getline(cin, data);
                    searcher.setName(data);

                if (repertory.findData(searcher, Song::compareBySongName) != nullptr)
                {
                    position = repertory.findData(searcher, Song::compareBySongName);
                    repertory.insertData(position, auxSong);
                } else {
                    cout << "Error, no se reconoce esa canción." << endl;
                }
            } else {
                position = nullptr;
                repertory.insertData(position, auxSong);
            }
            break;

            case 2:
                if (!repertory.isEmpty())
                {
                    cout << endl << "------------------------------------------" << endl << "1.- Buscar por nombre de la canción." << endl;
                    cout << "2.- Buscar por nombre del interprete." << endl << "------------------------------------------" << endl;
                    cout << " Seleccione una opción: "; cin >> op2;

                if (op2 == 1)
                {
                    cout << "Ingrese el nombre de la canción: " << endl;
                    getline(cin, data);
                    getline(cin, data);
                    auxSong.setName(data);

                    position = repertory.findData(auxSong, Song::compareBySongName);

                    if (position != nullptr)
                    {
                        cout << "Canción encontrada en el archivo: " << position->getData().getMP3Name() << endl;
                    }
                    else {
                        cout << "La canción no está en la playlist." << endl;
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
                        cout << "Canción encontrada en el archivo: " << position->getData().getMP3Name() << endl;
                    } else {
                        cout << "La canción no está en la playlist." << endl;
                    }
                }
                cout << "Presione enter para continuar." << endl;
                getline(cin, data);

            }
            else {
                cout << "Playlist vacía." << endl;
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
                cout << "Canción a eliminar: " << songName << endl;
            } else {
                cout << "Canción no encontrada." << endl;
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
                    cout << "La playlist se eliminará completamente..." << endl;
                    getline(cin, data); getline(cin, data);
                }
                else if (op2 == 2)
                {
                    cout << "Operación cancelada." << endl;
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
