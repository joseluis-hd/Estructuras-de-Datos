#include <iostream>
#include <random>
#include <chrono>
#include <functional>
#include <ctime>

#include "BinaryTree.hpp"

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "spanish");
    BiTree<int> myTree;
    int n, i, element;
    default_random_engine generator(chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution <int> distribution(0, 100000);
    auto randomInt = bind(distribution, generator);
    cout << "===== ÁRBOLES BINARIOS =====" << endl;
    cout << "Elementos a insertar en el árbol: ";
    cin >> n;

    cout << "\nElementos insertados: ";
    for (i = 0; i < n; ++i)
    {
        element = randomInt();
        if (i != 0)
            cout << ", ";
        cout << element;
        myTree.insert(element);
    }
    cout << endl;

    cout << "\nRecorrido PreOrder: " << endl;
    myTree.parsePreOrder();
    cout << endl;

    cout << "\nRecorrido InOrder: " << endl;
    myTree.parseInOrder();
    cout << endl;

    cout << "\nRecorrido PostOrder: " << endl;
    myTree.parsePostOrder();
    cout << endl << endl;

    cout << "Elemento menor en el árbol: " << myTree.retrieve(myTree.getLowest(myTree.getRoot())) << endl;
    cout << "Elemento mayor en el árbol: " << myTree.retrieve(myTree.getHighest(myTree.getRoot())) << endl;
    cout << "Altura del subarbol izquierdo: "
    << myTree.getHeight(myTree.getRoot()->getLeft()) << endl;
    cout << "Altura del subarbol derecho: "
     << myTree.getHeight(myTree.getRoot()->getRight()) << endl;
}
