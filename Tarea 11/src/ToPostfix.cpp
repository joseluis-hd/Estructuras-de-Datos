#include <iostream>
#include <cstdlib>

#include "ToPostfix.hpp"

using namespace std;

ToPostfix::ToPostfix() { }

ToPostfix::ToPostfix(const ToPostfix&) { }

void ToPostfix::showMenu()
{
    char choice;

    do {
        string expression;
        cout << "===== CONVERSIONES DE INFIJO A POSFIJO =====" << endl;
        cout << "Ingrese la expresión infija a convertir: ";
        getline(cin, expression);

        Queue<char> infixExpression;
        for (int i = 0; i < expression.length(); i++)
        {
            infixExpression.enqueue(expression[i]);
        }

        string postfixExpression = infixToPostfix(infixExpression);

        cout << "La expresión convertida a posfijo es: " << postfixExpression << endl;

        cout << "¿Desea ingresar otra expresión? (S/N): ";
        cin >> choice;
        cin.ignore();

        if (choice == 'S' || choice == 's')
        {
            system("cls");
        }

    } while (choice == 'S' || choice == 's');
}

string ToPostfix::infixToPostfix(Queue<char>& e)
{
    char ch;
    string result = "";

    while (!e.isEmpty())
    {
        ch = e.dequeue();
        if (operation(ch))
        {
            try
            {
                if (!myStack.isEmpty() && myStack.getTop() != '(')
                {
                    while (!myStack.isEmpty() && priority(myStack.getTop()) >= priority(ch))
                    {
                        result += myStack.pop();
                    }
                }
            }
            catch (Stack<char>::Exception& se) { }
            myStack.push(ch);
        }
        else if (grouper(ch))
        {
            if (ch == '(')
            {
                myStack.push(ch);
            }
            else
            {
                try
                {
                    while (!myStack.isEmpty() && myStack.getTop() != '(')
                    {
                        result += myStack.pop();
                    }
                    myStack.pop();
                }
                catch (Stack<char>::Exception& se) { }
            }
        }
        else
        {
            result += ch;
        }
    }
    while (!myStack.isEmpty())
    {
        result += myStack.pop();
    }
    return result;
}

int ToPostfix::priority(const char& a)
{
    int imp = 0;
    if (a == '-' || a == '+')
    {
        imp = 1;
    }
    if (a == '*' || a == '/')
    {
        imp = 2;
    }
    if (a == '^')
    {
        imp = 3;
    }
    return imp;
}

bool ToPostfix::operation(const char& b)
{
    return (b == '-' || b == '+' || b == '*' || b == '/' || b == '^');
}

bool ToPostfix::grouper(const char& ch)
{
    return (ch == '(' || ch == ')');
}
