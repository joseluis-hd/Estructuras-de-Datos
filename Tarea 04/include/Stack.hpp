#ifndef STACK_HPP
#define STACK_HPP

#include <exception>
#include <string>

class StackException : public std::exception
{
    private:
        std::string msg;

    public:
        explicit StackException(const char* message) : msg(message) { }

        explicit StackException(const std::string& message) : msg(message) { }

        virtual ~StackException() throw () { }

        virtual const char* what() const throw ()
        {
            return msg.c_str();
        }
};

///Definicion
template <class T, int ARRAYSIZE = 1024>
class Stack
{
    private:
        T data[ARRAYSIZE];
        int top;

        void copyAll(const Stack<T, ARRAYSIZE>&);

    public:
        Stack();
        Stack(const Stack<T, ARRAYSIZE>&);

        bool isEmpty();

        bool isFull();

        void push(const T&);

        T pop();

        T getTop();

        Stack<T, ARRAYSIZE>& operator = (const Stack<T, ARRAYSIZE>&);
};

///Implementacion
using namespace std;

template <class T, int ARRAYSIZE>
void Stack<T, ARRAYSIZE>::copyAll(const Stack<T, ARRAYSIZE>& s)
    {
        int i(0);
        while(i <= s.top)
        {
            this->data[i] = s.data[i];

            i++;
        }

        this->top = s.top;
    }

    template <class T, int ARRAYSIZE>
    Stack<T, ARRAYSIZE>::Stack() : top(-1) {}

    template <class T, int ARRAYSIZE>
    Stack<T, ARRAYSIZE>::Stack(const Stack<T, ARRAYSIZE>&s)
    {
        copyAll(s);
    }

    template <class T, int ARRAYSIZE>
    bool Stack<T, ARRAYSIZE>::isEmpty()
    {
        return top == -1;
    }

    template <class T, int ARRAYSIZE>
    bool Stack<T, ARRAYSIZE>::isFull()
    {
        return top == ARRAYSIZE -1;
    }

    template <class T, int ARRAYSIZE>
    void Stack<T, ARRAYSIZE>::push(const T& e)
    {
        if(isFull())
        {
            throw StackException("Desbordamiento de datos, push");
        }
        data[++top] = e;
    }

    template <class T, int ARRAYSIZE>
    T Stack<T, ARRAYSIZE>::pop()
    {
        if(isEmpty())
        {
            throw StackException("Insuficiencia de datos, pop");
        }

        return data[top--];
    }

    template <class T, int ARRAYSIZE>
    T Stack<T, ARRAYSIZE>::getTop()
    {
        if(isEmpty())
        {
            throw StackException("Insuficiencia de datos, getTop");
        }

        return data[top];
    }

    template <class T, int ARRAYSIZE>
    Stack<T, ARRAYSIZE>& Stack<T, ARRAYSIZE>::operator = (const Stack<T, ARRAYSIZE>& s)
    {
        copyAll(s);

        return *this;
    }

#endif // STACK_HPP
