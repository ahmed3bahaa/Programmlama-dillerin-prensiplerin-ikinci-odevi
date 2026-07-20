#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
#include "Node.hpp"
using namespace std;
class Linkedlist
{
    Node *head;
    Node *tail;
    Node *Findprev(int);
    int size;

public:
    Linkedlist();
    int length();

    bool isEmpty() const;

    void add(Bst *obj);

    void printtree() const;
    void printlist(Node *) const;
    void PrintNode() const;
    void *Dfunction();
    void *Afunction();
    void MirrorList();
    void Delete();

    Node *FindNode(int);

    ~Linkedlist();
};
#endif
