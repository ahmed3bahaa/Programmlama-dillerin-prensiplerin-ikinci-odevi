/**
 * @file  Linkedlıst.cpp
 * @description liste sınıfı
 * @course  Veri yapılar
 * @assignment   2.ödev
 * @date  12/24/2024
 * @author  Ahmed bahaa ahmed momtaz
 */
#include "Linkedlist.hpp"
#include <string>
#include <iomanip>
using namespace std;
int counter = 0;         // ok hangi dumude oldugunu kontrol eden degisken
Linkedlist::Linkedlist() // constructor
{
    head = tail = new Node();
    size = 0;
}
int Linkedlist::length()
{
    int length = 0;
    Node *tmp = head->next;
    while (tmp != nullptr)
    {
        tmp = tmp->next;
        length++;
    }

    return length;
}

bool Linkedlist::isEmpty() const
{
    return size == 0;
}
Node *Linkedlist::Findprev(int position)
{
    if (position < 0 || position > size)
        throw "Index out of range";
    int index = 0;
    Node *itr = head;
    for (; itr != NULL; itr = itr->next, index++)
    {
        if (position == index)
            return itr;
    }
    return nullptr;
}

void Linkedlist::add(Bst *obj)
{

    Node *newnode = new Node(obj);
    if (isEmpty())
    {
        head->next = newnode;
    }
    else
    {
        tail->next = newnode;
    }
    tail = newnode;
    size++;
}

void Linkedlist::printtree() const // agac cizdirme
{

    Node *tmp = head->next;

    while (tmp != nullptr)
    {

        tmp->tree->levelorder();

        cout << endl;
        tmp = tmp->next;
    }
    cout << endl;
}

void Linkedlist::printlist(Node *arrow) const // linkedlist cizdirme
{
    int pages = 0;
    Node *tempo = head->next;
    Node *tmp;
    int index = 0;
    while (index != 10 && tempo != nullptr)
    {
        index++;
        tempo = tempo->next;
    }
    if (counter >= 10)
    {

        tmp = tempo;
        system("cls");
    }

    else
    {

        tmp = tempo = head->next;
        system("cls");
    }

    if (size != 0)
    {

        while (tmp != nullptr && pages != 10)
        {
            cout << "..........." << "  ";
            tmp = tmp->next;
            pages++;
        }
        cout << "\n";
        pages = 0;
        tmp = tempo;

        while (tmp != nullptr && pages != 10)
        {

            cout << ":" << setw(9) << (int)tmp % 10000 << ":" << "  ";
            pages++;
            tmp = tmp->next;
        }
        pages = 0;
        cout << "\n";
        tmp = tempo;

        while (tmp != nullptr && pages != 10)
        {
            cout << "..........." << "  ";
            tmp = tmp->next;
            pages++;
        }
        cout << "\n";
        pages = 0;
        tmp = tempo;
        while (tmp != nullptr && pages != 10)
        {
            int sum = tmp->tree->Sum();

            cout << ":" << setw(9) << sum << ":" << "  ";
            pages++;

            tmp = tmp->next;
        }
        cout << "\n";
        pages = 0;
        tmp = tempo;
        while (tmp != nullptr && pages != 10)
        {
            cout << "..........." << "  ";
            tmp = tmp->next;
            pages++;
        }
        cout << "\n";
        pages = 0;
        tmp = tempo;

        while (tmp != nullptr && pages != 10)
        {

            cout << ":" << setw(9) << (int)tmp->next % 10000 << ":" << "  ";
            pages++;
            tmp = tmp->next;
        }

        cout << "\n";
        pages = 0;
        tmp = tempo;
        while (tmp != nullptr && pages != 10)
        {
            cout << "..........." << "  ";
            pages++;
            tmp = tmp->next;
        }
        Node *tmp1 = tempo;
        pages = 0;
        cout << "\n";
        while (tmp1 != arrow)
        {
            cout << "             ";
            tmp1 = tmp1->next;
        }
        tmp1 = tempo;

        cout << "^^^^^^^^^^^\n";

        while (tmp1 != arrow)
        {
            cout << "             ";

            tmp1 = tmp1->next;
        }
        cout << "|||||||||||\n\n";

        tmp1->tree->levelorder();
    }
}
void *Linkedlist::Dfunction() // ilerleme
{
    if (isEmpty())
        throw "Empty list";
    counter++;

    if (counter >= size)
        counter = size - 1;
    if (counter < 0)
        counter = 0;
    Node *tmp = head->next;
    int index = 0;
    while (counter != index)
    {
        index++;
        tmp = tmp->next;
    }
    system("cls");
    printlist(tmp);
}
void *Linkedlist::Afunction() // gerileme
{
    if (isEmpty())
        throw "Empty list";
    counter--;
    if (counter < 0)
        counter = 0;
    if (counter >= size)
        counter = size - 1;
    Node *tmp = head->next;
    int index = 0;
    while (counter != index)
    {
        index++;
        tmp = tmp->next;
    }
    system("cls");
    printlist(tmp);
}
void Linkedlist::MirrorList() // aynalama
{
    if (isEmpty())
        throw "Empty list";
    Node *tmp = head->next;
    int index = 0;
    while (counter != index)
    {
        index++;
        tmp = tmp->next;
    }
    tmp->tree->Mirror();
    system("cls");
    printlist(tmp);
}
void Linkedlist::PrintNode() const
{
    printlist(head->next);
}

Node *Linkedlist::FindNode(int index)
{
    if (index >= size || index < 0)
        throw "index out of range";
    Node *tmp = head->next;
    int position = 0;
    while (index != position)
    {
        tmp = tmp->next;
        position++;
    }
    return tmp;
}
void Linkedlist::Delete() // silme
{

    if (isEmpty())
        throw "Empty list";
    Node *del;
    Node *prev = Findprev(counter);

    del = prev->next;
    prev->next = prev->next->next;
    delete del;
    size--;
    system("cls");

    if (prev != head)
    {
        counter--;

        printlist(prev);
    }

    else
    {
        printlist(prev->next);
    }
}

Linkedlist::~Linkedlist() // yikici fonksiyonu
{
    Node *tmp = head->next;
    while (tmp != nullptr)
    {
        Node *current = tmp->next;
        delete tmp->tree;
        delete tmp;
        tmp = current;
    }
    delete head;
}