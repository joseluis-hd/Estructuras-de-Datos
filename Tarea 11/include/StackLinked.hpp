#ifndef STACKLINKED_HPP
#define STACKLINKED_HPP


#include <exception>
#include <string>

///Definicion
template <class T>
class Stack
{
    class Node;

    public:
        typedef Node* Position;

    class Exception : public std::exception
    {
        private:
            std::string msg;

        public:
            Exception() noexcept : msg("Error indefinido") { }
            Exception(const Exception& ex) noexcept : msg(ex.msg) { }
            Exception(const std::string& m) : msg(m) {}
            Exception& operator=(const Exception& ex) noexcept
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

    private:
        class Node
        {
            private:
                T data;
                Node* next;

            public:
                class Exception : public Stack::Exception
                {
                    public:
                        using Stack::Exception::Exception;
                };

            Node();
            Node(const T&);

            T getData() const;
            Position getNext();

            void setData(const T&);
            void setNext(Node*);
        };

    Position anchor;

    void copyAll(const Stack&);

    void deleteAll();

public:
    Stack();
    Stack(const Stack&);
    ~Stack();

    bool isEmpty() const;

    void push(const T&);

    T pop();

    T getTop() const;

    Stack& operator=(const Stack&);
};

///Implementacion
///Node
template <class T>
Stack<T>::Node::Node() : next(nullptr) { }

template <class T>
Stack<T>::Node::Node(const T& e) : data(e), next(nullptr) { }

template <class T>
T Stack<T>::Node::getData() const
{
    return data;
}

template <class T>
typename Stack<T>::Position Stack<T>::Node::getNext()
{
    return next;
}

template <class T>
void Stack<T>::Node::setData(const T& e)
{
    data = e;
}

template <class T>
void Stack<T>::Node::setNext(Node* p)
{
    next = p;
}

using namespace std;
///Pila
template <class T>
void Stack<T>::copyAll(const Stack& s)
{
    Position aux(s.anchor);
    Position lastInserted(nullptr);
    Position newNode;

    while (aux != nullptr)
    {
        if ((newNode = new Node(aux->getData())) == nullptr)
        {
            throw Exception("memoria no disponible, copyAll");
        }

        if (lastInserted == nullptr)
        {
            anchor = newNode;
        } else {
            lastInserted->setNext(newNode);
        }

        lastInserted = newNode;
        aux = aux->getNext();
    }
}

template <class T>
void Stack<T>::deleteAll()
{
    Position aux;

    while (anchor != nullptr)
    {
        aux = anchor;
        anchor = anchor->getNext();
        delete aux;
    }
}

template <class T>
Stack<T>::Stack() : anchor(nullptr) { }

template <class T>
Stack<T>::Stack(const Stack& s) : Stack()
{
    copyAll(s);
}

template <class T>
Stack<T>::~Stack()
{
    deleteAll();
}

template <class T>
bool Stack<T>::isEmpty() const
{
    return this->anchor == nullptr;
}

template <class T>
void Stack<T>::push(const T& e)
{
    Position aux(new Node(e));
    if (aux == nullptr)
    {
        throw Exception("Memoria no disponible, push");
    }
    aux->setNext(anchor);
    anchor = aux;
}

template <class T>
T Stack<T>::pop()
{
    if (isEmpty())
    {
        throw Exception("Insufuciencia de datos, pop");
    }

    T result(anchor->getData());
    Position aux(anchor);
    anchor = anchor->getNext();
    delete aux;

    return result;
}

template <class T>
T Stack<T>::getTop() const
{
    if (isEmpty())
    {
        throw Exception("Insuficiencia de datos, getTop");
    }
    return anchor->getData();
}

template <class T>
Stack<T>& Stack<T>::operator=(const Stack& s)
 {
    deleteAll();
    copyAll(s);
    return *this;
}

#endif // STACKLINKED_HPP
