#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

#include <exception>
#include <iostream>
#include <string>

///Definicion
template <class T>
class BiTree
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
                T* dataPtr;
                Position left;
                Position right;

            public:
                class Exception : public BiTree::Exception
                {
                    public:
                        using BiTree::Exception::Exception;
                };

                Node();
                Node(const T&);

                T* getDataPtr();
                T& getData() const;
                Position& getLeft();
                Position& getRight();

                void setDataPtr(T*);
                void setData(const T&);
                void setLeft(const Position&);
                void setRight(const Position&);
        };

        Position root;

        void copyAll(Position&, Position&);
        void insert(Position&, const T&);
        void deleteData(Position&, const T&);
        Position& findData(Position&, const T&);
        void deleteAll(Position&);
        void parsePreOrder(const Position&);
        void parseInOrder(const Position&);
        void parsePostOrder(const Position&);

    public:
        BiTree();
        BiTree(const BiTree&);

        ~BiTree();

        bool isEmpty() const;
        void insert(const T&);
        void deleteData(const T&);

        Position& findData(const T&);

        bool isLeaf(const Position&) const;

        Position& getLowest(Position&);
        Position& getHighest(Position&);

        int getHeight() const;

        T retrieve(const Position&);

        void deleteAll();

        int getHeight(const Position&) const;

        BiTree& operator=(const BiTree&);

        void parsePreOrder();
        void parseInOrder();
        void parsePostOrder();

        Position& getRoot();
};

///Implementacion
using namespace std;
template <class T>
BiTree<T>::Node::Node() : dataPtr(nullptr), left(nullptr), right(nullptr) { }

template <class T>
BiTree<T>::Node::Node(const T& e) : dataPtr(new T(e)), left(nullptr), right(nullptr)
{
    if (dataPtr == nullptr)
    {
        throw Exception("Memoria no disponible");
    }
}

template <class T>
T* BiTree<T>::Node::getDataPtr()
{
    return dataPtr;
}

template <class T>
T& BiTree<T>::Node::getData() const
{
    return *dataPtr;
}

template <class T>
typename BiTree<T>::Position& BiTree<T>::Node::getLeft()
{
    return left;
}

template <class T>
typename BiTree<T>::Position& BiTree<T>::Node::getRight()
{
    return right;
}

template <class T>
void BiTree<T>::Node::setDataPtr(T* p)
{
    dataPtr = p;
}

template <class T>
void BiTree<T>::Node::setData(const T& e)
{
    if (dataPtr == nullptr)
    {
        if (dataPtr = new T(e) == nullptr)
        {
            throw Exception("Memoria no disponible");
        }
    } else
    {
        *dataPtr = e;
    }
}

template <class T>
void BiTree<T>::Node::setLeft(const Position& p)
{
    left = p;
}

template <class T>
void BiTree<T>::Node::setRight(const Position& p)
{
    right = p;
}

/// Private
template <class T>
void BiTree<T>::copyAll(Position&, Position&) { }

template <class T>
void BiTree<T>::insert(Position& r, const T& e)
{
    if (r == nullptr)
    {
        try
        {
            if ((r = new Node(e)) == nullptr)
            {
                throw Exception("Memoria no disponible");
            }
        } catch (const typename Node::Exception& ex)
        {
            throw Exception(ex.what());
        }

    } else {
        if (e < r->getData())
        {
            insert(r->getLeft(), e);
        } else {
            insert(r->getRight(), e);
        }
    }
}

template <class T>
void BiTree<T>::deleteData(Position& r, const T& e)
{

    if (r == nullptr)
    {
        return;
    }

    if (r->getData() == e)
    {
        Position aux = r;
        if (isLeaf(r))
        {
            r = nullptr;
        } else {
            if (r->getLeft() == nullptr)
            {
                r = r->getRight();
            }
            if (r->getRight() == nullptr)
            {
                r = r->getLeft();
            }
            delete aux;
        }
    } else {
        T replacement = getHighest(r->getLeft())->getData();
        deleteData(r->getLeft(), replacement);
    }
}

template <class T>
typename BiTree<T>::Position& BiTree<T>::findData(Position& r, const T& e)
{

    if (r == nullptr || r->getData() == e)
    {
        return r;
    }

    if (e < r->getData())
    {
        return findData(r->getLeft(), e);
    }

    return findData(r->getRight(), e);
}

template <class T>
void BiTree<T>::deleteAll(Position& r)
{
    if (r->getLeft() != nullptr)
    {
        deleteAll(r->getLeft());
    }
    if (r->getRight() != nullptr)
    {
        deleteAll(r->getRight());
    }
    delete r;
}

template <class T>
int BiTree<T>::getHeight(const Position& r) const
{

    if (r == nullptr)
    {
        return 0;
    }

    int leftH(getHeight(r->getLeft()));
    int rightH(getHeight(r->getRight()));

    return (leftH > rightH ? leftH : rightH) + 1;
}

template <class T>
void BiTree<T>::parsePreOrder(const Position& r)
{
    if (r == nullptr)
    {
        return;
    }

    std::cout << r->getData() << " | ";
    parsePreOrder(r->getLeft());
    parsePreOrder(r->getRight());
}

template <class T>
void BiTree<T>::parseInOrder(const Position& r)
{
    if (r == nullptr)
    {
        return;
    }

    parseInOrder(r->getLeft());
    std::cout << r->getData() << " | ";
    parseInOrder(r->getRight());
}

template <class T>
void BiTree<T>::parsePostOrder(const Position& r)
{
    if (r == nullptr)
    {
        return;
    }

    parsePostOrder(r->getLeft());
    parsePostOrder(r->getRight());
    std::cout << r->getData() << " | ";
}

/// Public
template <class T>
BiTree<T>::BiTree() : root(nullptr) { }

template <class T>
BiTree<T>::BiTree(const BiTree& t) : root(nullptr)
{
    copyAll(t.root, root);
}

template <class T>
BiTree<T>::~BiTree()
{
    deleteAll();
}

template <class T>
bool BiTree<T>::isEmpty() const
{
    return root == nullptr;
}

template <class T>
void BiTree<T>::insert(const T& e)
{
    insert(root, e);
}

template <class T>
void BiTree<T>::deleteData(const T& e)
{

    deleteData(root, e);
}

template <class T>
typename BiTree<T>::Position& BiTree<T>::findData(const T& e)
{
    return findData(root, e);
}

template <class T>
bool BiTree<T>::isLeaf(const Position& r) const
{
    return r != nullptr && r->getLeft() == r->getRight();
}

template <class T>
typename BiTree<T>::Position& BiTree<T>::getLowest(Position& r)
{

    if (r == nullptr || r->getLeft() == nullptr)
    {
        return r;
    }

    return getLowest(r->getLeft());
}

template <class T>
typename BiTree<T>::Position& BiTree<T>::getHighest(Position& r)
{

    if (r == nullptr || r->getRight() == nullptr)
    {
        return r;
    }

    return getHighest(r->getRight());
}

template <class T>
int BiTree<T>::getHeight() const
{
    return getHeight(root);
}

template <class T>
T BiTree<T>::retrieve(const Position& r)
{
    if (r == nullptr)
    {
        throw Exception("Posicion invalida, retrieve");
    }

    return r->getData();
}

template <class T>
void BiTree<T>::deleteAll()
{
    deleteAll(root);
}

template <class T>
BiTree<T>& BiTree<T>::operator = (const BiTree& t)
{
    deleteAll();
    copyAll(t.root, root);
    return *this;
}

template <class T>
void BiTree<T>::parsePreOrder()
{
    parsePreOrder(root);
}

template <class T>
void BiTree<T>::parseInOrder()
{
    parseInOrder(root);
}

template <class T>
void BiTree<T>::parsePostOrder()
{
    parsePostOrder(root);
}

template <class T>
typename BiTree<T>::Position& BiTree<T>::getRoot()
{
    return root;
}

#endif // BINARYTREE_HPP
