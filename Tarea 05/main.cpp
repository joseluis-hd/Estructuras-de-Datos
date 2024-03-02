#include <iostream>
#include <cstdlib>

#include "Menu.hpp"

using namespace std;

int main()
{
    List<Song> list;
    Menu menu(&list);
    menu.interfaz();
    return 0;
}
