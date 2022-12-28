#ifndef _BST_
#define _BST_

#include <iostream>

class Node
{
public:
    int data;
    Node *right;
    Node *left;
    Node()
    {
        data = 0;
        right = left = NULL;
    };
    Node(int x)
    {
        data = x;
        right = left = NULL;
    };
    bool is_leaf()
    {
        return (left == NULL && right == NULL);
    }
};

class BST
{
private:
    Node *root;
    Node *_insert_rec(int x, Node *n);
    void _print_inorder(Node *n);
    int _max_value(Node *n);
    int _min_value(Node *n);
    int _height(Node *n);
    Node *_remove(int x, Node *n);
    int _non(Node *n);

public:
    BST() { root = NULL; };
    void insert_rec(int x);
    bool empty() { return root == NULL; };
    void print();
    int max_value();
    int min_value();
    int height();
    void remove(int x);
    int non();
};



// Recursive insert
void BST::insert_rec(int x)
{
    root = _insert_rec(x, root);
}

Node *BST::_insert_rec(int x, Node *n)
{

    if (!n)
        return new Node(x);

    if (x > n->data)
        n->right = _insert_rec(x, n->right);
    else
        n->left = _insert_rec(x, n->left);

    // gerek var gibi duruyo ama bi şey returnlemeyince deger degismiyor
    // return n;
}

// Print
void BST::print()
{
    _print_inorder(root);
}

void BST::_print_inorder(Node *n)
{
    if (n == NULL)
        return;

    _print_inorder(n->left);
    std::cout << n->data << " ";
    _print_inorder(n->right);
}

// Max_value
int BST::max_value()
{
    return _max_value(root);
}

int BST::_max_value(Node *n)
{
    if (empty())
    {
        std::cout << "Tree boş";
        return -1;
    }

    if (!n->right)
        return n->data;

    _max_value(n->right);
}

// Min_value
int BST::min_value()
{
    return _min_value(root);
}

int BST::_min_value(Node *n)
{
    if (empty())
    {
        std::cout << "Tree boş";
        return -1;
    }

    if (!n->left)
        return n->data;

    _min_value(n->left);
}

// Height

int BST::height()
{
    return _height(root);
}

int BST::_height(Node *n)
{
    if (!n)
        return -1;

    int leftTreeHeight = _height(n->left);
    int rightTreeHeight = _height(n->right);

    return std::max(leftTreeHeight, rightTreeHeight) + 1;
}

// Remove
void BST::remove(int x)
{
    root = _remove(x, root);
}

Node *BST::_remove(int x, Node *n)
{
    if (!n)
        return NULL;

    if (x > n->data)
        n->right = _remove(x, n->right);
    else if (x < n->data)
        n->left = _remove(x, n->left);
    else
    {
        if (n->is_leaf())
        {
            delete n;
            return NULL;
        }

        if (!n->right)
        {
            delete n;
            return n->left;
        }
        else if (!n->left)
        {
            delete n;
            return n->right;
        }
        else
        {
            int enb = _max_value(n->left);
            n->data = enb;
            n->left = _remove(enb, n->left);
        }
    }
}

// Number of Nodes
int BST::non()
{
    return _non(root);
}

int BST::_non(Node *n)
{
    if (!n)
        return 0;

    return _non(n->left) + _non(n->right) + 1;
}

#endif