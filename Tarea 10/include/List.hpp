#ifndef LIST_H
#define LIST_H

#include "Node.hpp"

#include <iostream>
#include <sstream>
#include <string>

///Definicion
template <class T>
class List
{
    private:
        Node<T>* anchor;

        void copyAll(const List&);
        bool isValidPos(Node<T>*) const;

    class Exception : public std::exception {
    private:
        std::string msg;
    public:
        Exception() noexcept : msg("Error indefinido") { }
        Exception(const Exception& ex) noexcept : msg(ex.msg) { }
        Exception(const std::string& m) : msg(m) { }
        Exception& operator = (const Exception& ex) noexcept
        {
            msg = ex.msg;
            return *this;
        }
        virtual ~Exception() { }
        virtual const char* what() const noexcept
        {
            return msg.c_str();
        }
    };

public:
    List();
    List(const List&);

    ~List();

    bool isEmpty() const;

    void insertData(Node<T>*, const T&);

    void deleteData(Node<T>*);

    Node<T>* getFirstPos();
    Node<T>* getLastPos();
    Node<T>* getPrevPos(Node<T>*);
    Node<T>* getNextPos(Node<T>*);

    Node<T>* getIndex(int);

    Node<T>* findData(const T&, int comp (const T&, const T&));

    T retrieve(Node<T>*) const;

    std::string toString() const;

    void deleteAll();

    List<T>& operator = (const List&);
};

///Implementacion
using namespace std;

template <class T>
void List<T>::copyAll(const List& l)
{
    Node<T>* aux(l.anchor);
    Node<T>* lastInserted(nullptr);
    Node<T>* newNode;
    while (aux != nullptr)
    {
        newNode = new Node(aux->getData());
        if (newNode == nullptr)
        {
            throw Exception("Memoria no disponible");
        }
        if (lastInserted == nullptr)
        {
            anchor = newNode;
        } else
        {
            lastInserted->setNext(newNode);
        }
        newNode->setPrev(lastInserted);
        lastInserted = newNode;
        aux = aux->getNext();
    }
}

template <class T>
bool List<T>::isValidPos(Node<T>* p) const
{
    Node<T>* aux(anchor);
    while (aux != nullptr)
    {
        if (aux == p)
        {
            return true;
        }
        aux = aux->getNext();
    }
    return false;
}

template <class T>
List<T>::List() : anchor(nullptr) { }

template <class T>
List<T>::List(const List& l) : List()
{
    copyAll(l);
}

template <class T>
List<T>::~List()
{
    deleteAll();
}

template <class T>
bool List<T>::isEmpty() const
{
    return this->anchor == nullptr;
}

template <class T>
void List<T>::insertData(Node<T>* p, const T& e)
{
    if (p != nullptr and !isValidPos(p))
    {
        throw Exception("Posicion invalida, insertData");
    }
    Node<T>* aux(new Node<T>(e));
    if (aux == nullptr)
    {
        throw Exception("Memoria no disponible, insertData");
    }

    if (p == nullptr)
    {
        aux->setPrev(nullptr);
        aux->setNext(anchor);

        if (anchor != nullptr)
        {
            anchor->setPrev(aux);
        }
        anchor = aux;
    } else {
        aux->setPrev(p);
        aux->setNext(p->getNext());
        if (p->getNext() != nullptr)
        {
            p->getNext()->setPrev(aux);
        }
        p->setNext(aux);
    }
}

template <class T>
void List<T>::deleteData(Node<T>* p)
{
    if (!isValidPos(p))
    {
        throw Exception("Posicion invalida, deleteData");
    }
    if (p->getPrev() != nullptr)
    {
        p->getPrev()->setNext(p->getNext());
    }
    if (p->getNext() != nullptr)
    {
        p->getNext()->setPrev(p->getPrev());
    }
    if (p == anchor)
    {
        anchor = anchor->getNext();
    }
    delete p;
}

template <class T>
Node<T>* List<T>::getFirstPos()
{
    return anchor;
}

template <class T>
Node<T>* List<T>::getLastPos()
{
    if (isEmpty())
    {
        return nullptr;
    }
    Node<T>* aux(anchor);
    while (aux->getNext() != nullptr)
    {
        aux = aux->getNext();
    }
    return aux;
}

template <class T>
Node<T>* List<T>::getPrevPos(Node<T>* p)
{
    if (isValidPos())
    {
        return nullptr;
    }
    return p->getPrev();
}

template <class T>
Node<T>* List<T>::getNextPos(Node<T>* p)
{
    if (!isValidPos())
    {
        return nullptr;
    }
    return p->getNext();
}

template <class T>
Node<T>* List<T>::getIndex(int index)
{
    if (index < 0)
    {
        throw Exception("Indice invalido, getPos");
    }
    Node<T>* aux = anchor;
    int i = 0;
    while (aux != nullptr && i < index)
    {
        aux = aux->getNext();
        i++;
    }
    if (i != index)
    {
        throw Exception("Indice invalido, getPos");
    }
    return aux;
}

template <class T>
Node<T>* List<T>::findData(const T& e, int comp(const T&, const T&))
{
    Node<T>* aux(anchor);
    while (aux != nullptr)
    {
        if (comp(aux->getData(), e) == 0)
        {
            return aux;
        } else {
            aux = aux->getNext();
        }
    }
    return aux;
}

template <class T>
T List<T>::retrieve(Node<T>* p) const
{
    if (!isValidPos())
    {
        throw Exception("Posicion invalida, retrieve");
    }
    return p->getData();
}

template <class T>
string List<T>::toString() const
{
    string result;
    Node<T>* aux(anchor);
    while (aux != nullptr)
    {
        result += aux->getData().toString();
        aux = aux->getNext();
    }
    return result;
}

template <class T>
void List<T>::deleteAll()
{
    Node<T>* aux;
    while (anchor != nullptr)
    {
        aux = anchor;
        anchor = anchor->getNext();
        delete aux;
    }
}

template <class T>
List<T>& List<T>::operator = (const List& l)
{
    deleteAll();
    copyAll(l);
    return *this;
}
#endif
