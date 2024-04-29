#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <sstream>

#include "Song.hpp"
#include "List.hpp"

class Menu
{
    private:
        void show();

    public:
        Menu();
        void execute();
};

#endif // MENU_HPP
