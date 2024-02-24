#ifndef TOPOSTFIX_HPP
#define TOPOSTFIX_HPP

#include <iostream>
#include <string>

#include "Stack.hpp"
#include "Queue.hpp"

class ToPostfix
{
    private:
        Stack<char> myStack;

        int priority(const char&);
        bool operation(const char&);
        bool grouper(const char&);

    public:
        ToPostfix();
        ToPostfix(const ToPostfix&);

        void showMenu();
        std::string infixToPostfix(Queue<char>&);
};

#endif // TOPOSTFIX_HPP
