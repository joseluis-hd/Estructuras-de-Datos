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
    void addSong();
    void specificAdd();
    void searchSong();
    void deleteSong();
    void ordList();

public:
    Menu(List<Song>*);
    int interfaz();
    void setOpc(int value)
    {
        opc = value;
    }
};
#endif // MENU_HPP
