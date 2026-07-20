#ifndef NODE_HPP
#define NODE_HPP
#include <iostream>
#include "Bst.hpp"
using namespace std;
class Node
{
public:
    Bst *tree;
    Node *next;
    Node(Bst *agac = nullptr, Node *sonraki = nullptr)
    {
        tree = agac;
        next = sonraki;
    }
};

#endif