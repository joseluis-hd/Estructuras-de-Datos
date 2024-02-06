#ifndef MENU_HPP
#define MENU_HPP

#include "Product.hpp"
#include "Date.hpp"

class Menu
{
    public:
        static void showMenu();
        static void AddProduct(int&);
        static void AddExistance();
        static void RemoveProduct();
        static void Collection(int);

    private:
        static Product coleccion[500];
        static Date fecha2;
};

#endif // MENU_HPP
