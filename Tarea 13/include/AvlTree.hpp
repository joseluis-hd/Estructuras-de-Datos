#ifndef AVLTREE_HPP
#define AVLTREE_HPP


#include <exception>
#include <iostream>
#include <string>
#include <sstream>

///Definicion
template <class T>
class AvlTree
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
                Position left;
                Position right;
                unsigned height;

            public:
                class Exception : public AvlTree::Exception
                {
                    public:using AvlTree::Exception::Exception;
                };

            Node();
            Node(const T&);

            T* getDataPtr();
            T& getData() const;
            Position& getLeft();
            Position& getRight();
            unsigned getHeight() const;

            void setDataPtr(T*);
            void setData(const T&);
            void setLeft(const Position&);
            void setRight(const Position&);
            void setHeight(const unsigned&);
        };

    Position root;

        void copyAll(Position&, Position&);
        void insert(Position&, const T&);
        void deleteData(Position&, const T&);
        Position& findData(Position&, const T&);
        void deleteAll(Position&);
        void updateHeight(Position&);
        void parsePreOrder(const Position&);
        void parseInOrder(const Position&);
        void parsePostOrder(const Position&);

        void replaceParent(Position&, Position&);

        int getBalanceFactor(const Position&) const;

        void doLeftRot(Position&);
        void doRightRot(Position&);

        void doBalancing(Position&);

    public:
        AvlTree();
        AvlTree(const AvlTree&);

        bool isEmpty() const;
        void insert(const T&);
        void deleteData(const T&);
        Position& getRoot();
        Position& findData(const T&);
        bool isLeaf(const Position&) const;

        Position& getLowest(Position&);
        Position& getHighest(Position&);

        int getHeight() const;

        T retrieve(const Position&);

        void deleteAll();

        AvlTree& operator=(const AvlTree&);

        void parsePreOrder();
        void parseInOrder();
        void parsePostOrder();

        int getHeight(const Position&) const;
};

///Implementacion
using namespace std;
template <class T>
AvlTree<T>::Node::Node() : dataPtr(nullptr), left(nullptr), right(nullptr) { }

template <class T>
AvlTree<T>::Node::Node(const T& e) : dataPtr(new T(e)), left(nullptr), right(nullptr)
{
    if (dataPtr == nullptr)
    {
        throw Exception("Memoria no disponible");
    }
}

template <class T>
T* AvlTree<T>::Node::getDataPtr()
{
    return dataPtr;
}

template <class T>
T& AvlTree<T>::Node::getData() const
{
    return *dataPtr;
}

template <class T>
unsigned AvlTree<T>::Node::getHeight() const
{
  return height;
}

template <class T>
typename AvlTree<T>::Position& AvlTree<T>::Node::getLeft()
{
    return left;
}

template <class T>
typename AvlTree<T>::Position& AvlTree<T>::Node::getRight()
{
    return right;
}

template <class T>
void AvlTree<T>::Node::setDataPtr(T* p)
{
    dataPtr = p;
}

template <class T>
void AvlTree<T>::Node::setData(const T& e)
{
    if (dataPtr == nullptr)
    {
        if (dataPtr = new T(e) == nullptr)
        {
            throw Exception("Memoria no disponible");
        }
    } else {
        *dataPtr = e;
    }
}

template <class T>
void AvlTree<T>::Node::setLeft(const Position& p)
{
    left = p;
}

template <class T>
void AvlTree<T>::Node::setRight(const Position& p)
{
    right = p;
}

template <class T>
void AvlTree<T>::Node::setHeight(const unsigned& h)
{
  height = h;
}

template <class T>
void AvlTree<T>::copyAll(Position&, Position&) { }

template <class T>
void AvlTree<T>::insert(Position& r, const T& e)
{
    if (r == nullptr)
    {
        try {
            if ((r = new Node(e)) == nullptr)
            {
                throw Exception("Memoria no disponible");
            }
        } catch (const typename Node::Exception& ex)
        {
                throw Exception(ex.what());
        }
    } else
    {
        if (e < r->getData())
        {
            insert(r->getLeft(), e);
        } else {
            insert(r->getRight(), e);
        }
    }
    updateHeight(r);
    doBalancing(r);
}

template <class T>
void AvlTree<T>::deleteData(Position& r, const T& e)
{
    if (r == nullptr)
    {
        throw Exception("Inexistencia de elemento, deleteData");
    } else if (e < r->getData()) {
        deleteData(r->getLeft(), e);
    } else if (e > r->getData()) {
        deleteData(r->getRight(), e);
    } else {
        Position aux = r;
        if (r->getLeft() == nullptr)
        {
            r = r->getRight();
        } else if (r->getRight() == nullptr) {
            r = r->getLeft();
        } else {
            replaceParent(r, r->getLeft());
        }
        delete aux;
    }

    updateHeight(r);
    doBalancing(r);
}

template <class T>
typename AvlTree<T>::Position& AvlTree<T>::findData(Position& r, const T& e)
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
void AvlTree<T>::deleteAll(Position& r)
{
    if (r != nullptr)
    {
        deleteAll(r->getLeft());
        deleteAll(r->getRight());
        delete r;
        r = nullptr;
    }
}

template <class T>
int AvlTree<T>::getHeight() const
{
    return getHeight(root);
}

template <class T>
int AvlTree<T>::getHeight(const Position& r) const
{
    if (r == nullptr)
    {
        return 0;
    }

    int leftH(getHeight(r->getLeft()));
    int rightH(getHeight(r->getRight()));

    if (r->getLeft() == nullptr)
    {
        return (leftH > rightH ? leftH : rightH);
    }

    if (r->getRight() == nullptr)
    {
        return (leftH > rightH ? leftH : rightH);
    }

    return (leftH > rightH ? leftH : rightH) + 1;
}

template <class T>
void AvlTree<T>::updateHeight(Position& r)
{
    int lH(r->getLeft() == nullptr ? 0 : getHeight(r->getLeft()));
    int rH(r->getRight() == nullptr ? 0 : getHeight(r->getRight()));

    r->setHeight((lH > rH ? lH : rH) + 1);
}

template <class T>
void AvlTree<T>::parsePreOrder(const Position& r)
{
    if (r == nullptr)
    {
        return;
    }

    cout << r->getData() << " | ";
    parsePreOrder(r->getLeft());
    parsePreOrder(r->getRight());
}

template <class T>
void AvlTree<T>::parseInOrder(const Position& r)
{
    if (r == nullptr)
    {
        return;
    }

    parseInOrder(r->getLeft());
    cout << r->getData() << " | ";
    parseInOrder(r->getRight());
}

template <class T>
void AvlTree<T>::parsePostOrder(const Position& r)
{
    if (r == nullptr)
    {
        return;
    }

    parsePostOrder(r->getLeft());
    parsePostOrder(r->getRight());
    cout << r->getData() << " | ";
}

template <class T>
AvlTree<T>::AvlTree() : root(nullptr) { }

template <class T>
AvlTree<T>::AvlTree(const AvlTree& t) : root(nullptr)
{
    copyAll(t.root, root);
}

template <class T>
bool AvlTree<T>::isEmpty() const
{
    return root == nullptr;
}

template <class T>
void AvlTree<T>::insert(const T& e)
{
    insert(root, e);
}

template <class T>
void AvlTree<T>::deleteData(const T&)
{
    deleteData(root, data);
}

template <class T>
typename AvlTree<T>::Position& AvlTree<T>::getRoot()
{
    return root;
}

template <class T>
typename AvlTree<T>::Position& AvlTree<T>::findData(const T& e)
{
    return findData(root, e);
}

template <class T>
bool AvlTree<T>::isLeaf(const Position& r) const
{
    return r != nullptr && r->getLeft() == r->getRight();
}

template <class T>
typename AvlTree<T>::Position& AvlTree<T>::getLowest(Position& r)
{
  if (r == nullptr || r->getLeft() == nullptr)
{
    return r;
  }

  return getLowest(r->getLeft());
}

template <class T>
typename AvlTree<T>::Position& AvlTree<T>::getHighest(Position& r)
{
    if (r == nullptr || r->getRight() == nullptr)
    {
        return r;
    }
    return getHighest(r->getRight());
}

template <class T>
T AvlTree<T>::retrieve(const Position& r)
{
    if (r == nullptr)
    {
        throw Exception("Posicion invalida, retrieve");
    }
    return r->getData();
}

template <class T>
void AvlTree<T>::deleteAll()
{
    deleteAll(root);
}

template <class T>
AvlTree<T>& AvlTree<T>::operator=(const AvlTree& t)
{
    deleteAll();
    copyAll(t.root, root);
    return *this;
}

template <class T>
void AvlTree<T>::parsePreOrder()
{
    parsePreOrder(root);
}

template <class T>
void AvlTree<T>::parseInOrder()
{
    parseInOrder(root);
}

template <class T>
void AvlTree<T>::parsePostOrder()
{
    parsePostOrder(root);
}

template <class T>
void AvlTree<T>::replaceParent(Position& oldParent, Position& newParent)
{
    if (newParent->getRight() != nullptr)
    {
        replaceParent(oldParent, newParent->getRight());
    } else {
        oldParent->setData(newParent->getData());
        oldParent = newParent;
        newParent = newParent->getLeft();
    }
    updateHeight();
    doBalancing();
    updateHeight();
}

template <class T>
int AvlTree<T>::getBalanceFactor(const Position& r) const
{
    return getHeight(r->getRight()) - getHeight(r->getLeft());
}

template <class T>
void AvlTree<T>::doLeftRot(Position& r)
{
    Position aux(r->getRight());

    r->setRight(aux->getLeft());
    aux->setLeft(r);
    r = aux;

    updateHeight(r->getLeft());
    updateHeight(r);
}

template <class T>
void AvlTree<T>::doRightRot(Position& r)
{
    Position aux(r->getLeft());

    r->setLeft(aux->getRight());
    aux->setRight(r);
    r = aux;

    updateHeight(r->getRight());
    updateHeight(r);
}

template <class T>
void AvlTree<T>::doBalancing(Position& r)
{
    switch (getBalanceFactor(r))
    {
    case -2:
        if (getBalanceFactor(r->getLeft()) == 1)
        {
            doLeftRot(r->getLeft());
        }
        doRightRot(r);
      break;

    case 2:
        if (getBalanceFactor(r->getRight()) == -1)
        {
            doRightRot(r->getRight());
        }
        doLeftRot(r);
      break;
    }
}

#endif // AVLTREE_HPP
