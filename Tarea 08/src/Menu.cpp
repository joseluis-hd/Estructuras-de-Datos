#include "Menu.hpp"
#include "List.hpp"
#include "Song.hpp"

using namespace std;

Menu::Menu() { }

void Menu::showMenu()
{
    setlocale(LC_CTYPE, "spanish");

    cout << "\t\t\t\t\tPLAYLIST" << endl
    << "-----------------------------------------------------------------------------------------------------------------" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
    cout << "1.- Añadir nueva canción." << endl;
    cout << "2.- Añadir nueva canción en un lugar especifico." << endl;
    cout << "3.- Buscar canción." << endl;
    cout << "4.- Eliminar canción." << endl;
    cout << "5.- Ordenar lista." << endl;
    cout << "6.- Eliminar lista completa." << endl;
    cout << "7.- Salir." << endl << "-----------------------------------------------------------------------------------------------------------------" << endl;
}

void Menu::executeMenu()
{
    bool deleted = false;
    int op1(0), op2(0), op3(0), pos, ranking;
    List<Song> repertory;
    Song newSong, auxSearcher;
    string data;

    while (op1 != 7)
    {
        system("cls");
        if (repertory.isEmpty() == false)
        {
            cout << repertory.toString() << endl;
        }
        this->showMenu();
        cin >> op1;

        switch (op1)
        {
            case 1:
                cout << endl << "===== AÑADIR CANCIÓN ===== " << endl;
                cout << "\nRanking: "; cin >> ranking;
                cout << "Canción: "; getline(cin, data); getline(cin, data);
                newSong.setName(data);
                cout << "Autor: "; getline(cin, data);
                newSong.setAuthor(data);
                cout << "Intérprete: "; getline(cin, data);
                newSong.setInterpreter(data);
                cout << "Archivo: "; getline(cin, data);
                newSong.setMP3Name(data);
                newSong.setRanking(ranking);
                cout << "Posición a insertar: "; cin >> pos;
                repertory.insertData(pos, newSong);
                break;

            case 2:
                cout << "\nAñadir nueva canción en un lugar específico:" << endl;
                cout << "Ranking: "; cin >> ranking;
                cout << "Canción: "; getline(cin, data); getline(cin, data);
                newSong.setName(data);
                cout << "Autor: "; getline(cin, data);
                newSong.setAuthor(data);
                cout << "Intérprete: "; getline(cin, data);
                newSong.setInterpreter(data);
                cout << "Archivo: "; getline(cin, data);
                newSong.setMP3Name(data);
                newSong.setRanking(ranking);
                cout << "Posición a insertar: "; cin >> pos;
                try {
                    repertory.insertData(pos, newSong);
                    cout << "Canción agregada exitosamente en la posición " << pos << endl;
                } catch (const ListException& e) {
                    cout << "Error: " << e.what() << endl;
                }
                break;


            case 3:
                if (!repertory.isEmpty())
                {
                    cout << endl << "------------------------------------------" << endl << "1.- Buscar por nombre de la canción" << endl;
                    cout << "2.- Buscar por nombre del interprete" << endl << "------------------------------------------" << endl;
                    cout << " Seleccione una opcion: "; cin >> op2;

                    if (op2 == 1)
                    {
                        cout << " Ingrese el nombre de la canción: " << endl;
                        getline(cin, data);
                        getline(cin, data);
                        auxSearcher.setName(data);

                        if (repertory.findData(auxSearcher, Song::compareBySongName) != -1)
                        {
                            cout << "La canción se encuentra en el ranking: "
                                 << repertory.retrieve(repertory.findData(auxSearcher, Song::compareBySongName)).getRanking() << endl;
                        } else
                        {
                            cout << "La canción no está en la playlist." << endl;
                        }

                    } else if (op2 == 2)
                    {
                        cout << "Ingrese el nombre del intérprete: " << endl;
                        getline(cin, data);
                        getline(cin, data);
                        auxSearcher.setInterpreter(data);

                        if (repertory.findData(auxSearcher, Song::compareByInterpreter) != -1)
                        {
                            cout << "La canción se encuentra en el ranking: "
                                 << repertory.retrieve(repertory.findData(auxSearcher, Song::compareByInterpreter)).getRanking() << endl;
                        } else
                        {
                            cout << "La canción no está en la playlist." << endl;
                        }
                    }
                    cout << "Presione enter para continuar." << endl;
                    getline(cin, data);

                } else
                {
                    cout << "Playlist vacía." << endl;
                    cout << "Presione enter para continuar." << endl;
                    break;
                }
                break;

            case 4:
                cout << "\nNombre: ";
                getline(cin, data);
                getline(cin, data);
                auxSearcher.setName(data);

                for (int i(0); i < repertory.getLastPos(); i++)
                {
                    if (auxSearcher.getName() == repertory.retrieve(i).getName())
                    {
                        cout << "Canción a eliminar:" << repertory.retrieve(i).getName();
                        repertory.deleteData(i);
                        deleted = true;
                    }
                }
                if (deleted == false)
                {
                    cout << "Canción no encontrada.";
                    cout << "Presione enter para continuar.";
                    getline(cin, data);
                }
                break;

            case 5:
                if (!repertory.isEmpty())
                {
                    cout << " 1.- Ordenar por nombre de la canción " << endl;
                    cout << " 2.- Ordenar por nombre del intérprete " << endl;
                    cout << "Seleccione una opción: "; cin >> op2;

                    switch (op2)
                    {
                        case 1:
                            cout << "1.- BubbleSort." << endl;
                            cout << "2.- InsertSort." << endl;
                            cout << "3.- SelectSort." << endl;
                            cout << "4.- ShellSort." << endl;
                            cout << "Seleccione una opción: "; cin >> op3;

                            if (op3 == 1)
                            {
                                repertory.bubbleSort(Song::compareBySongName);
                            } else if (op3 == 2)
                            {
                                repertory.insertSort(Song::compareBySongName);
                            } else if (op3 == 3)
                            {
                                repertory.selectSort(Song::compareBySongName);
                            } else if (op3 == 4)
                            {
                                repertory.shellSort(Song::compareBySongName);
                            }
                            cout << "Lista ordenada, presione enter para continuar." << endl;
                            getline(cin, data);
                            break;

                        case 2:
                            cout << "1.- BubbleSort." << endl;
                            cout << "2.- InsertSort." << endl;
                            cout << "3.- SelectSort." << endl;
                            cout << "4.- ShellSort." << endl;
                            cout << "Seleccione una opción: "; cin >> op3;

                            if (op3 == 1)
                            {
                                repertory.bubbleSort(Song::compareByInterpreter);
                            } else if (op3 == 2)
                            {
                                repertory.insertSort(Song::compareByInterpreter);
                            } else if (op3 == 3)
                            {
                                repertory.selectSort(Song::compareByInterpreter);
                            } else if (op3 == 4)
                            {
                                repertory.shellSort(Song::compareByInterpreter);
                            }
                            cout << "Lista ordenada, presione enter para continuar." << endl;
                            getline(cin, data);
                            break;
                    }
                } else
                {
                    cout << "Playlist vacía." << endl;
                    cout << "Presione enter para continuar." << endl;
                    break;
                }
                break;

            case 6:
                cout << "La playlist se eliminará completamente..." << endl;
                cout << "1.- Confirmar \n2.- Cancelar" << endl;
                cin  >> op3;

                if (op3 == 1)
                {
                    repertory.deleteAll();
                    cout << " Lista eliminada correctamente." << endl;
                    getline(cin, data); getline(cin, data);
                } else if (op3 == 2)
                {
                    cout << "Operación cancelada." << endl;
                    getline(cin, data); getline(cin, data);
                }

                break;

            case 7:
                cout << "Saliendo del programa..." << endl;
                break;

            default:
                cout << " Seleccione una opción válida . . ." << endl;
        }
    }
}

