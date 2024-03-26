#ifndef MENU_HPP_INCLUDED
#define MENU_HPP_INCLUDED

#include <string.h>
#include <cstdlib>
#include <iostream>
#include <exception>
#include <functional>
#include <random>
#include <chrono>
#include <cstdio>
#include <conio.h>
#include <ctime>

#include "List.hpp"

class menuExcepcion: public std::exception
{
    private:
    std::string msg;
    public:
    menuExcepcion() noexcept;
    menuExcepcion(const menuExcepcion& ex) noexcept : msg(ex.msg) { }
    menuExcepcion(const std::string& m) : msg(m) { }
    menuExcepcion& operator = (const menuExcepcion& ex) noexcept
    {
        msg = ex.msg;
    }
    virtual ~menuExcepcion(){ }
    virtual const char* what() const noexcept
    {
        return msg.c_str();
    }
};

///Definicion

class Menu
{
    private:
        int opc;

    public:
        Menu();
        int interfaz();
        int getOpc();
        void setOpc(const int&);
        void MostrarMenu();

        void linea();
        void addData();
        void add();
        void ordData();
        void isSorted();
};

#endif // MENU_HPP_INCLUDED
