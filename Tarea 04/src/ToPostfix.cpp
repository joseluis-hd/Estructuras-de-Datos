#include "ToPostfix.hpp"
#include <iostream>

using namespace std;

ToPostfix::ToPostfix() { }

ToPostfix::ToPostfix(const ToPostfix&) { }

void ToPostfix::showMenu()
{
    string expression;
    cout << "===== CONVERSIONES DE INFIJO A POSFIJO =====" << endl;
    cout << "Ingrese la expresión infija a convertir: " << endl;
    getline(cin, expression);

    Queue<char> infixExpression;
    for (int i = 0; i < expression.length(); i++)
    {
        infixExpression.enqueue(expression[i]);
    }

    ToPostfix converter;
    expression = converter.infixToPostfix(infixExpression);

    Queue<char> postfixExpression;
    for (int i = 0; i < expression.length(); i++)
    {
        postfixExpression.enqueue(expression[i]);
    }

    cout << "La expresión convertida a posfijo es: " << endl;
    for (int i = 0; i < expression.length(); i++)
    {
        cout << postfixExpression.dequeue();
    }
    cout << endl;
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
                if (myStack.getTop() != '(')
                {
                    while (priority(myStack.getTop()) >= priority(ch))
                    {
                        result += myStack.pop();
                    }
                }
            }
            catch (StackException& se) { }
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
                    while (myStack.getTop() != '(')
                    {
                        result += myStack.pop();
                    }
                    myStack.pop();
                }
                catch (StackException& se) { }
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
