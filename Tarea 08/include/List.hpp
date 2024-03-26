#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>

class ListException : public std::exception {
private:
    std::string msg;

public:
    explicit ListException(const char* message) : msg(message) { }
    explicit ListException(const std::string& message) : msg(message) { }
    virtual ~ListException() throw () {}
    virtual const char* what() const throw ()
    {
        return msg.c_str();
    }
};

template <class T, int ARRAYSIZE = 5000>
class List
{
    private:
        T* data[ARRAYSIZE];
        int last = -1;

        bool isValidPos(const int&) const;

    public:
        void initialize();

        bool isEmpty() const;
        bool isFull() const;

        void insertData(const int&, T);
        void deleteData(const int&);

        int getFirstPos();
        int getLastPos();
        int getPrevPos(const int&) const;
        int getNextPos(const int&) const;

        T retrieve(const int&) const;

        void deleteAll();

        std::string toString();

        int findData(T, int comp(const T&, const T&));

        void bubbleSort(int comp(const T&, const T&));
        void insertSort(int comp(const T&, const T&));
        void selectSort(int comp(const T&, const T&));
        void shellSort(int comp(const T&, const T&));
};

template <class T, int ARRAYSIZE>
bool List<T, ARRAYSIZE>::isValidPos(const int& p) const
{
    return p >= 0 && p < ARRAYSIZE;
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::initialize()
{
    last = -1;
}

template <class T, int ARRAYSIZE>
bool List<T, ARRAYSIZE>::isEmpty() const
{
    return last == -1;
}

template <class T, int ARRAYSIZE>
bool List<T, ARRAYSIZE>::isFull() const
{
    return last == ARRAYSIZE - 1;
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::insertData(const int& p, T e)
{
    if (isFull())
    {
        throw ListException("Lista llena, insertData");
    }

    if (!isValidPos(p))
    {
        throw ListException("Posicion invalida, insertData");
    }
    T* temp = new T;
    *temp = e;
    int i = last + 1;
    while (i > p)
    {
        data[i] = data[i - 1];
        i--;
    }
    data[p] = temp;
    last++;
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::deleteData(const int& p)
{
    if (!isValidPos(p))
    {
        throw ListException("Posicion invalida, deleteData");
    }
    delete data[p];
    int i = p;
    while (i < last)
    {
        data[i] = data[i + 1];
        i++;
    }

    last--;
}

template <class T, int ARRAYSIZE>
int List<T, ARRAYSIZE>::getFirstPos()
{
    return isEmpty() ? -1 : 0;
}

template <class T, int ARRAYSIZE>
int List<T, ARRAYSIZE>::getLastPos()
{
    return last;
}

template <class T, int ARRAYSIZE>
int List<T, ARRAYSIZE>::getNextPos(const int& p) const
{
    return (p == 0 || !isValidPos(p)) ? -1 : p - 1;
}

template <class T, int ARRAYSIZE>
int List<T, ARRAYSIZE>::getPrevPos(const int& p) const
{
    return (p == last || !isValidPos(p)) ? -1 : p + 1;
}

template <class T, int ARRAYSIZE>
T List<T, ARRAYSIZE>::retrieve(const int& p) const
{
    if (!isValidPos(p))
    {
        throw ListException("Posicion invalida, retrieve");
    }
    return *data[p];
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::deleteAll()
{
    for (int i = 0; i <= last; i++)
    {
        delete data[i];
    }
    last = -1;
}

template <class T, int ARRAYSIZE>
std::string List<T, ARRAYSIZE>::toString()
{
    if (isEmpty())
    {
        throw ListException("Insuficiencia de datos, toString");
    }
    std::stringstream writtenList;
    for (int i = 0; i <= last; i++)
    {
        writtenList << data[i]->toString();
    }
    return writtenList.str();
}

template <class T, int ARRAYSIZE>
int List<T, ARRAYSIZE>::findData(T e, int comp(const T&, const T&))
{
    int i = 0, j = last, midPos;
    if (!isEmpty())
    {
        while (i <= j)
        {
            midPos = (i + j) / 2;
            if (comp(*data[midPos], e) == 0)
            {
                return midPos;
            }

            if (comp(e, *data[midPos]) == -1)
            {
                j = midPos - 1;
            } else
            {
                i = midPos + 1;
            }
        }
        return -1;
    } else
    {
        return -1;
    }
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::bubbleSort(int comp(const T&, const T&))
{
    int i = last;
    bool flag;
    T aux;
    do
    {
        flag = false;
        int j = 0;

        while (j < i)
        {
            if (comp(*data[j], *data[j + 1]) > 0)
            {
                aux = *data[j + 1];
                *data[j + 1] = *data[j];
                *data[j] = aux;
                flag = true;
            }
            j++;
        }
        i--;
    } while (flag);
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::insertSort(int comp(const T&, const T&))
{
    int i = 1, j;
    T aux;
    while (i <= last)
    {
        aux = *data[i];
        j = i;
        while (j > 0 && comp(aux, *data[j - 1]) < 0)
        {
            *data[j] = *data[j - 1];
            j--;
        }
        if (i != j)
        {
            *data[j] = aux;
        }
        i++;
    }
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::selectSort(int comp(const T&, const T&))
{
    int i = 0, j, m;
    T aux;
    while (i < last)
    {
        m = i;
        j = i + 1;
        while (j <= last)
        {
            if (comp(*data[j], *data[m]) < 0)
            {
                m = j;
            }
            j++;
        }
        if (i != m)
        {
            aux = *data[m];
            *data[m] = *data[i];
            *data[i] = aux;
        }
        i++;
    }
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::shellSort(int comp(const T&, const T&))
{
    float factor = 0.5;
    int dif = (last + 1) * factor, i, j;
    T aux;
    while (dif > 0)
        {
            i = dif;
            while (i <= last)
            {
                j = i;
                while (j >= dif && comp(*data[j - dif], *data[j]) > 0)
                {
                    aux = *data[j];
                    *data[j] = *data[j - dif];
                    *data[j - dif] = aux;
                    j -= dif;
                }
                i++;
            }
            dif *= factor;
        }
}

#endif // LIST_HPP
