#ifndef BST_HPP
#define BST_HPP
#include "TreeNode.hpp"
#include <iomanip>
#include <string>
using namespace std;
class Bst
{
    TreeNode *root;
    void SearchAndAdd(TreeNode *&, const char &);
    bool SearchAndDelete(TreeNode *&, const char &);
    int Height(TreeNode *);
    bool DeleteNode(TreeNode *&);
    void PrintLevel(TreeNode *, int, int);
    void mirrorBST(TreeNode *);
    int treesum(TreeNode *, bool);

public:
    Bst();
    bool isEmpty() const;
    void add(const char &newItem);
    void Delete(const char &data);
    void Clear();
    int Height();
    int Sum();
    void Derinlik(TreeNode *, int, int);
    void PrintConnections(TreeNode *, int, int);

    void Mirror();
    void levelorder();
    ~Bst();
};
#endif