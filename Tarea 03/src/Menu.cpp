#include "Menu.hpp"

Menu::Menu() {}

void Menu::chooseOption()
{
    do
        {
            std::cout << "=====LISTA DE EXITOS=====" << std::endl << std::endl;
            playlist.print();
            std::cout << "1.- Insertar canción" << std::endl;
            std::cout << "2.- Eliminar canción" << std::endl;
            std::cout << "3.- Salir" << std::endl << std::endl;
            std::cout << "Opción: ";
            std::cin >> option;
            if (option != 3)
            {
                callMethod(option);
                getchar();
                system("cls");
            }
        }
    while (option != 3);
        std::cout << "Hasta luego..." << std::endl;
}

void Menu::callMethod(const int& option)
{
    int position;
    switch (option)
    {
        case 1:
            if (playlist.isFull())
                {
                    std::cout << "La lista está llena..." << std::endl;
            break;
            }
            std::cin.ignore();
            std::cout << "Canción: ";
            std::getline(std::cin, stringVal);
            songData.setName(stringVal);
            std::cout << "Autor: ";
            std::getline(std::cin, stringVal);
            songData.setAuthor(stringVal);
            std::cout << "Intérprete: ";
            std::getline(std::cin, stringVal);
            songData.setInterpreter(stringVal);
            std::cout << "Posición: ";
            std::cin >> intVal;
            songData.setPosition(intVal);
            playlist.insert(songData, songData.getPosition());
            break;
        case 2:
            std::cout << "Posición: ";
            std::cin >> position;
            playlist.remove(position);
            break;
        default:
            break;
    }
}
