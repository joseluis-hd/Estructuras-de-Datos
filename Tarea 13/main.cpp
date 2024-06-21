#include <iostream>
#include <functional>
#include <chrono>
#include <random>

#include "AvlTree.hpp"

using namespace std;

int main() {
    setlocale(LC_CTYPE, "spanish");

    int n;
    AvlTree<int> myTree;

    default_random_engine generator(chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> distribution(0, 100000);
    auto randomInt = bind(distribution, generator);

    cout << "===== ÁRBOLES AVL =====" << endl;
    cout << "Elementos a insertar en el árbol: ";
    cin >> n;
    cout << "\nElementos insertados: ";

    for (int i = 0; i < n; ++i)
    {
        int element = randomInt();
        if (i != 0)
            cout << ", ";
        cout << element;
        myTree.insert(element);
    }
    cout << endl;

    cout << "\nRecorrido PreOrder: " << endl;
    myTree.parsePreOrder();
    cout << "\n\nRecorrido InOrder: " << endl;
    myTree.parseInOrder();
    cout << "\n\nRecorrido PostOrder: " << endl;
    myTree.parsePostOrder();

    cout << "\n\nElemento menor en el árbol: " << myTree.retrieve(myTree.getLowest(myTree.getRoot())) << endl;
    cout << "Elemento mayor en el árbol: " << myTree.retrieve(myTree.getHighest(myTree.getRoot())) << endl;

    cout << "Altura del árbol: " << myTree.getHeight() << endl;
    cout << "Altura del subarbol izquierdo: "
         << myTree.getHeight(myTree.getRoot()->getLeft()) << endl;
    cout << "Altura del subarbol derecho: "
         << myTree.getHeight(myTree.getRoot()->getRight()) << endl;

    return 0;
}
