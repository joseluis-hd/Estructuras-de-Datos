#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <cstring>
#include "List.hpp"

class Menu
{
    private:
        int option;
        int intVal;
        std::string stringVal;
        Song songData;
        List playlist;

    public:
        Menu();
        void chooseOption();
        void callMethod(const int&);
};
#endif // MENU_HPP
