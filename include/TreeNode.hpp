#ifndef TREENODE_HPP
#define TREENODE_HPP

#include <iostream>
#include <cmath>
using namespace std;

class TreeNode
{
public:
    char data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(const char &dt = char(), TreeNode *lf = NULL, TreeNode *rg = NULL)
    {
        data = dt;
        left = lf;
        right = rg;
    }
};
#endif