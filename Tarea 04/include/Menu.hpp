#ifndef MENU_HPP
#define MENU_HPP

#include "Stack.hpp"
#include "Queue.hpp"

class Menu
{
    private:
        Stack<char> myStack;

        int priority(const char&);
        bool operation(const char&);
        bool grouper(const char&);
};

#endif // MENU_HPP
