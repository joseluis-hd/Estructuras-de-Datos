#ifndef SIMPLELINKEDLIST_HPP
#define SIMPLELINKEDLIST_HPP

///Definicion
template <class T>
class SimpleLinkedList
{
    class Node;

public:
    typedef Node* Position;

    class Exception : public std::exception
    {
        private:
            std::string msg;

        public:
            Exception() noexcept : msg("Error indefinido") {}
            Exception(const Exception& ex) noexcept : msg(ex.msg) {}
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

    SimpleLinkedList();
    SimpleLinkedList(const SimpleLinkedList&);

    ~SimpleLinkedList();

    void initialize();

    bool isEmpty() const;

    void insertData(Position* p, const T& e);

    void deleteData(Position&);

    Position getFirstPos() const;
    Position getLastPos() const;
    Position getPrevPos(Position&) const;
    Position getNextPos(Position&) const;

    Position findData(const T&) const;

    T retrieve(Position&) const;

    std::string toString() const;

    void deleteAll();

    SimpleLinkedList<T>& operator = (const SimpleLinkedList&);

    void bubbleSort(int(const T&, const T&));

private:
    class Node {
    public:
        class Exception : public SimpleLinkedList::Exception {
        public:
            using SimpleLinkedList::Exception::Exception;
        };

        Node();
        Node(const T&);

        T* getDataPtr();
        T& getData() const;
        Position& getNext();

        void setDataPtr(T*);
        void setData(const T&);
        void setNext(const Position&);

    private:
        T* dataPtr;
        Position next;
    };

    Position anchor;

    void copyAll(const SimpleLinkedList&);

    bool isValidPos(Position&) const;
};

///Implementacion
using namespace std;

template<class T>
SimpleLinkedList<T>::Node::Node(): dataPtr(nullptr), next(nullptr) { }

template<class T>
SimpleLinkedList<T>::Node::Node(const T& e) : dataPtr(new T(e)), next(nullptr)
{
    if (dataPtr == nullptr)
    {
        throw Exception("Memoria no disponible");
    }
}

template<class T>
T* SimpleLinkedList<T>::Node::getDataPtr()
{
    return dataPtr;
}

template<class T>
T& SimpleLinkedList<T>::Node::getData() const
{
    return *dataPtr;
}

template<class T>
typename SimpleLinkedList<T>::Position& SimpleLinkedList<T>::Node::getNext()
{
    return next;
}

template<class T>
void SimpleLinkedList<T>::Node::setDataPtr(T* p)
{
    dataPtr = p;
}

template<class T>
void SimpleLinkedList<T>::Node::setData(const T& e)
{
    if (dataPtr == nullptr)
    {
        dataPtr = new T(e);
        if (dataPtr == nullptr)
        {
            throw Exception("Memoria no disponible");
        }
    } else {
        *dataPtr = e;
    }
}

template<class T>
void SimpleLinkedList<T>::Node::setNext(const Position& p)
{
    next = p;
}

template <class T>
void SimpleLinkedList<T>::copyAll(const SimpleLinkedList& s)
{
    Node* aux;
    Position p;

    initialize();

    if (s.isEmpty())
    {
        return;
    }

    try {
        p = s.getFirstPos();
        while (true) {
            aux = new Node(s.retrieve(p));
            if (aux == nullptr)
            {
                throw Exception("Memoria no disponible al copiar");
            }
            if (isEmpty())
            {
                anchor = aux;
            } else {
                getLastPos()->setNext(aux);
            }

            if (p == s.getLastPos())
            {
                break;
            }

            p = s.getNextPos(p);
        }
    } catch (typename Node::Exception ex)
    {
        initialize();
        throw Exception(ex);
    }
}

template <class T>
bool SimpleLinkedList<T>::isValidPos(Position& p) const
{
    Position aux(anchor);

    while(aux != nullptr)
    {
        if(aux == p)
        {
            return true;
        }
        aux = aux->getNext();
    }
    return false;
}

template <class T>
SimpleLinkedList<T>::SimpleLinkedList() : anchor(nullptr) { }

template <class T>
SimpleLinkedList<T>::SimpleLinkedList(const SimpleLinkedList& l) : SimpleLinkedList()
{
    copyAll(l);
}

template <class T>
SimpleLinkedList<T>::~SimpleLinkedList()
{
    deleteAll();
    delete anchor;
}

template <class T>
void SimpleLinkedList<T>::initialize()
{
    anchor == nullptr;
}

template <class T>
bool SimpleLinkedList<T>::isEmpty() const
{
    return this->anchor == nullptr;
}

template <class T>
void SimpleLinkedList<T>::insertData(Position* p, const T& e)
{
    Node* aux;

    try {
        if ((aux = new Node(e)) == nullptr)
        {
            throw Exception("Memoria no disponible, insertData");
        }
    } catch (typename Node::Exception ex)
    {
        throw Exception(ex);
    }

    if (p == nullptr || *p == nullptr)
    {
        aux->setNext(anchor);
        anchor = aux;
        if (p != nullptr)
        {
            *p = aux;
        }
    } else {
        aux->setNext((*p)->getNext());
        (*p)->setNext(aux);
        *p = aux;
    }
}

template <class T>
void SimpleLinkedList<T>::deleteData(Position& p)
{

    if(!isValidPos(p))
    {
        throw Exception("Posicion invalida, deleteData");
    }
    if(p == anchor)
    {
        anchor = p->getNext();
    } else {
        getPrevPos(p)->setNext(p->getNext());
    }
}

template <class T>
typename SimpleLinkedList<T>::Position SimpleLinkedList<T>::getFirstPos() const
{
    return anchor;
}

template <class T>
typename SimpleLinkedList<T>::Position SimpleLinkedList<T>::getLastPos() const
{
    if(isEmpty())
    {
        return nullptr;
    }

    Position aux(anchor);

    while(aux->getNext() != nullptr)
    {
        aux = aux->getNext();
    }
    return aux;
}

template <class T>
typename SimpleLinkedList<T>::Position SimpleLinkedList<T>::getPrevPos(Position& p) const
{
    if(isEmpty() or p == anchor)
    {
        return nullptr;
    }

    Position aux(anchor);

    while(aux != nullptr and aux->getNext() != p)
    {
        aux = aux->getNext();
    }
    return aux;
}

template <class T>
typename SimpleLinkedList<T>::Position SimpleLinkedList<T>::getNextPos(Position& p) const
{
    if(!isValidPos(p))
    {
        return nullptr;
    }
    return p->getNext();
}

template <class T>
typename SimpleLinkedList<T>::Position SimpleLinkedList<T>::findData(const T& e) const
{
    Position aux(anchor);

    while(aux != nullptr and aux->getData() != e)
    {
        aux = aux->getNext();
    }
    return aux;
}

template <class T>
T SimpleLinkedList<T>::retrieve(Position& p) const
{
    if(!isValidPos(p))
    {
        throw Exception("Posicion invalida, retrieve");
    }
    return p->getData();
}

template <class T>
string SimpleLinkedList<T>::toString() const
{
    string result;

    Position aux(anchor);

    while(aux != nullptr)
    {
        result += aux->getData().toString();
        aux = aux->getNext();
    }
    return result;
}

template <class T>
void SimpleLinkedList<T>::deleteAll()
{
    Position aux;
    while(anchor != nullptr)
    {
        aux = anchor;
        anchor = anchor->getNext();
        delete aux;
    }
}

template <class T>
SimpleLinkedList<T>& SimpleLinkedList<T>::operator = (const SimpleLinkedList& l)
{
    deleteAll();
    copyAll(l);
    return *this;
}

template <class T>
void SimpleLinkedList<T>::bubbleSort(int comp(const T&, const T&))
{
    if (isEmpty()) return;
    bool swapped;
    Position ptr1;
    Position lptr = NULL;

    do {
        swapped = false;
        ptr1 = getFirstPos();

        while (getNextPos(ptr1) != lptr)
        {
            if (comp(ptr1->getData(), getNextPos(ptr1)->getData()) > 0)
            {
                T temp = ptr1->getData();
                ptr1->setData(getNextPos(ptr1)->getData());
                getNextPos(ptr1)->setData(temp);
                swapped = true;
            }
            ptr1 = getNextPos(ptr1);
        }
        lptr = ptr1;
    }
    while (swapped);
}

#endif // SIMPLELINKEDLIST_HPP
