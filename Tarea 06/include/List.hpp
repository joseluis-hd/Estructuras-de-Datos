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

    void bubbleSort();
    void insertSort();
    void selectSort();
    void shellSort();

    int findDataLinear(T&);
    int findDataBinary(T&);

    T retrieve(const int &);

    void sort();
    void print();
    void reset();

    void bubbleSortByInterpreter();
    void insertSortByInterpreter();
    void selectSortByInterpreter();
    void shellSortByInterpreter();
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
void List<T, ARRAYSIZE>::bubbleSort()
{
    for (int i = 0; i < last; i++)
    {
        for (int j = 0; j < last - i - 1; j++)
        {
            if (data[j].getName() > data[j + 1].getName())
            {
                T temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::insertSort()
{
    for (int i = 1; i <= last; i++)
    {
        T temp = data[i];
        int j = i - 1;
        while (j >= 0 && data[j].getName() > temp.getName())
        {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = temp;
    }
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::selectSort()
{
    for (int i = 0; i < last; i++)
    {
        int min = i;
        for (int j = i + 1; j <= last; j++)
        {
            if (data[j].getName() < data[min].getName())
            {
                min = j;
            }
        }
        T temp = data[min];
        data[min] = data[i];
        data[i] = temp;
    }
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::shellSort()
{
    for (int gap = last / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i <= last; i++)
        {
            T temp = data[i];
            int j = i;
            while (j >= gap && data[j - gap].getName() > temp.getName())
            {
                data[j] = data[j - gap];
                j -= gap;
            }
            data[j] = temp;
        }
    }
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

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::bubbleSortByInterpreter()
{
    for (int i = 0; i < last; i++)
    {
        for (int j = 0; j < last - i - 1; j++)
        {
            if (data[j].getInterpreter() > data[j + 1].getInterpreter())
            {
                T temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::insertSortByInterpreter()
{
    for (int i = 1; i <= last; i++)
    {
        T temp = data[i];
        int j = i - 1;
        while (j >= 0 && data[j].getInterpreter() > temp.getInterpreter())
        {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = temp;
    }
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::selectSortByInterpreter()
{
    for (int i = 0; i < last; i++)
    {
        int min = i;
        for (int j = i + 1; j <= last; j++)
        {
            if (data[j].getInterpreter() < data[min].getInterpreter())
            {
                min = j;
            }
        }
        T temp = data[min];
        data[min] = data[i];
        data[i] = temp;
    }
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::shellSortByInterpreter()
{
    for (int gap = last / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i <= last; i++)
        {
            T temp = data[i];
            int j = i;
            while (j >= gap && data[j - gap].getInterpreter() > temp.getInterpreter())
            {
                data[j] = data[j - gap];
                j -= gap;
            }
            data[j] = temp;
        }
    }
}

#endif // LIST_HPP
