#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>

template <class T>
class Node
{
    private:
        T data;
        Node* next;

    public:
        Node();
        Node(const T&);

        T getData() const;
        Node* getNext();

        void setData(const T&);
        void setNext(Node*);
};

///Implementacion
template<class T>
Node<T>::Node() : next(nullptr) { }

template<class T>
Node<T>::Node(const T& e) : data(e), next(nullptr) { }

template<class T>
T Node<T>::getData() const
{
    return data;
}

template<class T>
Node<T>* Node<T>::getNext()
{
    return next;
}

template<class T>
void Node<T>::setData(const T& e)
{
    data = e;
}

template<class T>
void Node<T>::setNext(Node* p)
{
    next = p;
}

#endif // NODE_HPP
