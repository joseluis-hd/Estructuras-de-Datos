#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <cstdlib>

#include "Song.hpp"
#include "List.hpp"

class Menu
{
    private:
        List<Song>* myList;
        int opc;

        void showMenu();
        void anadirCancion();
        void especificoAnadir();
        void buscarCancion();
        void eliminarCancion();
        void textos();

    public:
        Menu(List<Song>*);
        int interfaz();
        void setOpc(int value)
        {
            opc = value;
        }
};

#endif // MENU_HPP
