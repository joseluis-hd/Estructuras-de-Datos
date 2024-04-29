#ifndef TOPOSTFIX_HPP
#define TOPOSTFIX_HPP

#include "StackLinked.hpp"
#include "QueueDynamic.hpp"

class ToPostfix
{
    public:
        ToPostfix();
        ToPostfix(const ToPostfix&);

        void showMenu();

    private:
        Stack<char> myStack;

        std::string infixToPostfix(Queue<char>& e);
        int priority(const char& a);
        bool operation(const char& b);
        bool grouper(const char& ch);
};

#endif // TOPOSTFIX_HPP
