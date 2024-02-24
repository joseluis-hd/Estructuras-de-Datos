#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <exception>
#include <string>

class QueueException : public std::exception
{
    private:
        std::string msg;

    public:
        explicit QueueException(const char* message) : msg(message) { }

        explicit QueueException(const std::string& message) : msg(message) { }

        virtual ~QueueException() throw () { }

        virtual const char* what() const throw ()
        {
            return msg.c_str();
        }
};

//Definicion
template <class T, int ARRAYSIZE = 1024>
class Queue
{
    private:
        T data[ARRAYSIZE];
        int frontPos;
        int endPos;

        bool full = false;
        int firstPos;
        int lastPos;

        void copyAll(const Queue<T, ARRAYSIZE>&);

    public:
        Queue();
        Queue(const Queue<T, ARRAYSIZE>&);

        bool isEmpty();
        bool isFull();

        void enqueue(const T&);

        T dequeue();

        T getFront();

        Queue<T, ARRAYSIZE>& operator = (const Queue<T,ARRAYSIZE>&);
};

///Implementacion
using namespace std;

template <class T, int ARRAYSIZE>
void Queue<T, ARRAYSIZE>::copyAll(const Queue<T, ARRAYSIZE>& q)
{
    this->firstPos = q.firstPos;
    this-> lastPos = q.lastPos;
    this->full = q.full;
    int i = q.frontPos;
    if(isEmpty()) return;
    while((i != q.lastPos + 1) and full)
    {
        this->data[i] = q.data[i];
        i++;
        if((lastPos == ARRAYSIZE and firstPos != 0) or lastPos == ARRAYSIZE + 1) i = 0;
    }
}

template <class T, int ARRAYSIZE>
Queue<T, ARRAYSIZE>::Queue() : frontPos(0), endPos(ARRAYSIZE - 1) {}

template <class T, int ARRAYSIZE>
Queue<T, ARRAYSIZE>::Queue(const Queue<T, ARRAYSIZE>& q)
{
    copyAll(q);
}

template <class T, int ARRAYSIZE>
bool Queue<T, ARRAYSIZE>::isEmpty()
{
    return frontPos == endPos + 1 or (frontPos == 0 and endPos == ARRAYSIZE - 1);
}

template <class T, int ARRAYSIZE>
bool Queue<T, ARRAYSIZE>::isFull()
{
    return frontPos == endPos + 2 or (frontPos == 0 and endPos == ARRAYSIZE - 2) or (frontPos == 1 and endPos == ARRAYSIZE - 1);
}

template <class T, int ARRAYSIZE>
void Queue<T, ARRAYSIZE>::enqueue(const T& e)
{
    if(isFull())
    {
        throw QueueException("Desbordamiento de datos, enqueue");
    }

    if(++endPos == ARRAYSIZE)
    {
        endPos = 0;
    }

    data[endPos] = e;
}

template <class T, int ARRAYSIZE>
T Queue<T, ARRAYSIZE>::dequeue()
{
    if(isEmpty())
    {
        throw QueueException("Insuficiencia de datos, dequeue");
    }

    T result(data[frontPos]);

    if(++frontPos == ARRAYSIZE)
    {
        frontPos = 0;
    }

    return result;
}

template <class T, int ARRAYSIZE>
T Queue<T, ARRAYSIZE>::getFront()
{
    if(isEmpty())
    {
        throw QueueException("Insuficiencia de datos, getFront");
    }

    return data[frontPos];
}

template <class T, int ARRAYSIZE>
Queue<T, ARRAYSIZE>& Queue<T, ARRAYSIZE>::operator=(const Queue<T, ARRAYSIZE>& q)
{
    copyAll(q);

    return *this;
}

#endif // QUEUE_HPP
