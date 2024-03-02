#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <string>

class ListException : public std::exception
{

    private:
        std::string msg;

    public:
        explicit ListException(const char* message) : msg(message) { }
        explicit ListException(const std::string& message) : msg(message) { }
        virtual ~ListException() throw () { }
        virtual const char* what() const throw ()
        {
            return msg.c_str();
        }
};

/// Definicion
template <class T, int ARRAYSIZE = 3000>
class List
{
private:
    T data[ARRAYSIZE];
    int last;
    bool isValid(const int &);
    void copyAll(const List<T, ARRAYSIZE> &);

public:
    List();
    List(const List<T, ARRAYSIZE> &);

    bool isEmpty();
    bool isFull();

    void insertData(const T &, const int &);
    void deleteData(const int &);

    int getFirstPos();
    int getLastPos();
    int getPrevPos(const int &);
    int getNextPos(const int &);

    int findDataLinear(T&);
    int findDataBinary(T&);

    T retrieve(const int &);

    void sort();
    void print();
    void reset();
};

/// Implementacion
using namespace std;
template <class T, int ARRAYSIZE>
List<T, ARRAYSIZE>::List()
{
    last = -1;
}

template <class T, int ARRAYSIZE>
bool List<T, ARRAYSIZE>::isValid(const int &p)
{
    return (p > -1 && p <= last);
}

template <class T, int ARRAYSIZE>
bool List<T, ARRAYSIZE>::isEmpty()
{
    return last == -1;
}

template <class T, int ARRAYSIZE>
bool List<T, ARRAYSIZE>::isFull()
{
    return last == ARRAYSIZE - 1;
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::insertData(const T &e, const int &p)
{
    if (isFull())
    {
        throw ListException("Desbordamiento de datos.");
    }
    if (p != -1 && !isValid(p))
    {
        throw ListException("Posicion invalida.");
    }
    for (int i = last; i > p; i--)
    {
        data[i + 1] = data[i];
    }
    data[p + 1] = e;

    last++;
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::deleteData(const int &p)
{
    if (isEmpty())
    {
        throw ListException("Insuficiencia de datos.");
    }
    if (!isValid(p))
    {
        throw ListException("Posicion Invalida.");
    }
    else
    {
        for (int i = p; i < last; ++i)
        {
            data[i] = data[i + 1];
        }
        last--;
    }
}

template <class T, int ARRAYSIZE>
int List<T, ARRAYSIZE>::getFirstPos()
{
    return isEmpty() ? -1 : 0;
}

template <class T, int ARRAYSIZE>
int List<T, ARRAYSIZE>::getLastPos()
{
    return isEmpty() ? -1 : last;
}

template <class T, int ARRAYSIZE>
int List<T, ARRAYSIZE>::getPrevPos(const int &p)
{
    if (isEmpty() || !isValid(p) || p == 0)
    {
        return -1;
    }
    else
    {
        return p - 1;
    }

}

template <class T, int ARRAYSIZE>
int List<T, ARRAYSIZE>::getNextPos(const int &p)
{
    if (isEmpty() || !isValid(p) || p == ARRAYSIZE - 1)
        return -1;
    else
        return p + 1;
}

template <class T, int ARRAYSIZE>
int List<T, ARRAYSIZE>::findDataLinear(T& e)
{
    for (int i = 0; i <= last; ++i)
    {
        if (data[i].getName() == e.getName())
        {
            return i;
        }
    }
    return -1;
}

template <class T, int ARRAYSIZE>
int List<T, ARRAYSIZE>::findDataBinary(T& e)
{
    int low = 0;
    int high = last;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (data[mid].getName() == e.getName())
        {
            return mid;
        }
        else if (data[mid].getName() < e.getName())
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

template <class T, int ARRAYSIZE>
T List<T, ARRAYSIZE>::retrieve(const int &p)
{
    if (isEmpty())
    {

        throw ListException("Insuficiencia de datos, Recuperar");
    }
    if (!isValid(p))
    {
        throw ListException("Posicion Invalida, Recuperar");
    }

    return data[p];
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::sort()
{

}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::print()
{
    for (int i = 0; i <= last; i++)
    {
        std::cout << "Posicion: " + to_string(i) << data[i].toString() << endl;
    }
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::reset()
{
    last = -1;
}

#endif // LIST_HPP
