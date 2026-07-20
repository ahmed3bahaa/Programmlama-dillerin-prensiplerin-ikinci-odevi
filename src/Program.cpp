/**
 * @file  Program.cpp
 * @description Main sınıfı
 * @course  Veri yapılar
 * @assignment   2.ödev
 * @date  12/24/2024
 * @author  Ahmed bahaa ahmed momtaz
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include "Bst.hpp"
#include "Linkedlist.hpp"
// kutuphaneler eklendi
using namespace std;
Linkedlist *Lists = new Linkedlist();
int main()
{
    ifstream file("agaclar.txt");
    if (!file.is_open())
    {
        cerr << "Dosya Acilmadi , Tekrar Dene\n";
        return 1;
    }
    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        char Charachter;
        Bst *Tree = new Bst();

        while (ss >> Charachter)
        {
            Tree->add(Charachter);
        }
        Lists->add(Tree); // dosyadan okuma
    }
    file.close();
    Lists->PrintNode(); // ekrana yazdirma

    char c;
    char a[5] = {'d', 'w', 's', 'a', 'x'};

    do
    {
        cout << "Secim:... ";
        cin >> c;

        switch (c)
        {
        case 'd':

            Lists->Dfunction(); // ilerleme

            break;
        case 'w':
            Lists->MirrorList(); // aynalama

            break;
        case 's':
            Lists->Delete(); // silme

            break;
        case 'a':

            Lists->Afunction(); // geriye

            break;
        case 'x':

            break;
        default:

            break;
        }
    } while (c != 'x');

    Lists->~Linkedlist(); // yikici

    return 0;
}