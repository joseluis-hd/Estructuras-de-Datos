#include <iostream>
#include <conio.h>

#include "Menu.hpp"

int main()
{
    int opc, add = 0;

    do
        {
            setlocale(LC_CTYPE, "spanish");
            Menu::showMenu();
            std::cin >> opc;

    switch (opc)
    {
        case 1:
            Menu::AddProduct(add);
            break;
        case 2:
            Menu::AddExistance();
            break;
        case 3:
            Menu::RemoveProduct();
            break;
        case 4:
            Menu::Collection(add);
            break;
    }
        }
        while (opc != 5);

    std::cout << std::endl << "Hasta luego..." << std::endl;
    getch();
    return 0;
}
