#ifndef QUEUEDYNAMIC_HPP
#define QUEUEDYNAMIC_HPP


///Definicion
template <class T>
class Queue
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
                Exception(const std::string& m) : msg(m) { }
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
                T* dataPtr;
                Position prev;
                Position next;

            public:
                class Exception : public Queue::Exception
                {
                    public:
                    using Queue::Exception::Exception;
                };

        Node();
        Node(const T&);

        T* getDataPtr();
        T getData() const;
        Position getPrev() const;
        Position getNext() const;

        void setDataPtr(T*);
        void setData(const T&);
        void setPrev(const Position&);
        void setNext(const Position&);
        };

    Position header;

    void copyAll(const Queue&);

    bool isValidPos(Position) const;

    public:
        Queue();
        Queue(const Queue&);
        ~Queue();

        bool isEmpty() const;

        void enqueue(const T&);

        T dequeue();

        T getFront() const;

        void deleteAll();

        Queue& operator=(const Queue&);
    };

    ///Implementacion
    using namespace std;

    ///Node
    template <class T>
    Queue<T>::Node::Node() : dataPtr(nullptr), prev(nullptr), next(nullptr) { }

    template <class T>
    Queue<T>::Node::Node(const T& e) : dataPtr(new T(e)), prev(nullptr), next(nullptr)
    {
        if (dataPtr == nullptr)
        {
            throw Exception("Memoria no disponible");
        }
    }

    template <class T>
    T* Queue<T>::Node::getDataPtr()
    {
        return dataPtr;
    }

    template <class T>
    T Queue<T>::Node::getData() const
    {
        return *dataPtr;
    }

    template <class T>
    typename Queue<T>::Position Queue<T>::Node::getPrev() const
    {
        return prev;
    }

    template <class T>
    typename Queue<T>::Position Queue<T>::Node::getNext() const
    {
        return next;
    }

    template <class T>
    void Queue<T>::Node::setDataPtr(T* p)
    {
        dataPtr = p;
    }

    template <class T>
    void Queue<T>::Node::setData(const T& e)
    {
        if (dataPtr == nullptr)
        {
            if ((dataPtr = new T(e)) == nullptr)
            {
                throw Exception("Memoria no disponible");
            };
        } else
        {
            *dataPtr = e;
        }
    }

    template <class T>
    void Queue<T>::Node::setPrev(const Position& p)
    {
        prev = p;
    }

    template <class T>
    void Queue<T>::Node::setNext(const Position& p)
    {
        next = p;
    }

    ///Cola
    template <class T>
    void Queue<T>::copyAll(const Queue& l)
    {
        Position aux(l.header->getNext()), newNode;

        while (aux != l.header)
        {
            try
            {
                if ((newNode = new Node(aux->getData())) == nullptr)
                {
                    throw Exception("Memoria no disponible");
                }
            } catch (const typename Node::Exception& ex)
            {
                throw Exception(ex.what());
            }

        newNode->setPrev(header->getPrev());
        newNode->setNext(header);

        header->getPrev()->setNext(newNode);
        header->setPrev(newNode);

        aux = aux->getNext();
        }
    }

    template <class T>
    bool Queue<T>::isValidPos(Position p) const
    {
        Position aux(header->getNext());

        while (aux != header)
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
    Queue<T>::Queue() : header(new Node)
    {
        if (header == nullptr)
        {
            throw Exception("Memoria no disponible");
        }

        header->setPrev(header);
        header->setNext(header);
    }

    template <class T>
    Queue<T>::Queue(const Queue& l) : Queue()
    {
        copyAll(l);
    }

    template <class T>
    Queue<T>::~Queue()
    {
        deleteAll();
        delete header;
    }

    template <class T>
    bool Queue<T>::isEmpty() const
    {
        return header->getNext() == header;
    }

    template <class T>
    void Queue<T>::enqueue(const T& e)
    {
        Position aux;

        try
        {
            aux = new Node(e);
        } catch (const typename Node::Exception& ex)
        {
            throw Exception(ex.what());
        }

        if (aux == nullptr)
        {
            throw Exception("Memoria no disponible, enqueue");
        }

        aux->setPrev(header->getPrev());
        aux->setNext(header);

        header->getPrev()->setNext(aux);
        header->setPrev(aux);
    }

    template <class T>
    T Queue<T>::dequeue()
    {
        if (isEmpty())
        {
            throw Exception("Insuficiencia de datos, dequeue");
        }
        Position aux = header->getNext();
        aux->getPrev()->setNext(aux->getNext());
        aux->getNext()->setPrev(aux->getPrev());
        T data = aux->getData();
        delete aux;
        return data;
    }

    template <class T>
    T Queue<T>::getFront() const
    {
        if (isEmpty())
        {
            throw Exception("Insuficiencia de datos, getFront");
        }
        return header->getNext()->getData();
    }

    template <class T>
    void Queue<T>::deleteAll()
    {
        Position aux;
        while (header->getNext() != header)
        {
            aux = header->getNext();
            header->setNext(aux->getNext());
            delete aux;
        }
        header->setPrev(header);
    }

    template <class T>
    Queue<T>& Queue<T>::operator=(const Queue& l)
    {
        deleteAll();
        copyAll(l);
        return *this;
    }

#endif // QUEUEDYNAMIC_HPP
