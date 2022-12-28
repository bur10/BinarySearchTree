#include "bst.h"
#include <iostream>

using namespace std;

void printTree(BST *tree) {

    cout << "\n\tTREE\n"
        << "------------------\n";
    tree->print();
    cout << "\nmax_value=" << tree->max_value();
    cout << "\nmin_value=" << tree->min_value();
    cout << "\nheight=" << tree->height();
    cout << "\nnon="<<tree->non();
}

int main()
{

    BST *tree = new BST();

    tree->insert_rec(5);
    tree->insert_rec(12);
    tree->insert_rec(8);
    tree->insert_rec(25);
    tree->insert_rec(4);
    tree->insert_rec(2);
    tree->insert_rec(3);
    tree->insert_rec(7);
    tree->insert_rec(9);
    tree->insert_rec(1);

    printTree(tree);

    tree->remove(5);

    printTree(tree);


    return 0;
}













    // tree->insert_rec(30);
    // tree->insert_rec(25);
    // tree->insert_rec(60);
    // tree->insert_rec(40);
    // tree->insert_rec(67);

    // printTree(tree);

    // tree->remove(60);
    // printTree(tree);