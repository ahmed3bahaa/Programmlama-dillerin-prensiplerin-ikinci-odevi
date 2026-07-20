/**
 * @file  Bst.cpp
 * @description ağaç sınıfı
 * @course  Veri yapılar
 * @assignment   2.ödev
 * @date  12/24/2024
 * @author  Ahmed bahaa ahmed momtaz
 */
#include "Bst.hpp"
int L = 0;

void Bst::SearchAndAdd(TreeNode *&subNode, const char &newItem)
{
    if (subNode == NULL)
        subNode = new TreeNode(newItem);
    else if ((int)newItem < (int)subNode->data)
        SearchAndAdd(subNode->left, newItem);
    else if ((int)newItem > (int)subNode->data)
        SearchAndAdd(subNode->right, newItem);
    else
        return;
}
bool Bst::SearchAndDelete(TreeNode *&subNode, const char &data)
{
    if (subNode == NULL)
        return false;
    if (subNode->data == data)
        return DeleteNode(subNode);
    else if (data < subNode->data)
        return SearchAndDelete(subNode->left, data);
    else
        return SearchAndDelete(subNode->right, data);
}
int Bst::Height(TreeNode *subNode)
{
    if (subNode == NULL)
        return -1;
    return 1 + max(Height(subNode->left), Height(subNode->right));
}

int Bst::treesum(TreeNode *subnode, bool isLeft)
{
    if (!subnode)
        return 0;

    int weightedValue = isLeft ? 2 * (int)subnode->data : (int)subnode->data;

    return weightedValue +
           treesum(subnode->left, true) +
           treesum(subnode->right, false);
}

bool Bst::DeleteNode(TreeNode *&subNode) // node silme
{
    TreeNode *DelNode = subNode;

    if (subNode->right == NULL)
        subNode = subNode->left;
    else if (subNode->left == NULL)
        subNode = subNode->right;
    else
    {
        DelNode = subNode->left;
        TreeNode *parent = subNode;
        while (DelNode->right != NULL)
        {
            parent = DelNode;
            DelNode = DelNode->right;
        }
        subNode->data = DelNode->data;
        if (parent == subNode)
            subNode->left = DelNode->left;
        else
            parent->right = DelNode->left;
    }
    delete DelNode;
    return true;
}
void Bst::Derinlik(TreeNode *subNode, int level, int width)
{
    if (!subNode)
        return;
    string leftSpacing = string(width / 4, ' ');
    string connectionLine = string(width / 4, '.');
    if (width < 8)
        leftSpacing = string(width / 4 + 1, ' ');

    if (subNode->left)
    {
        cout << leftSpacing << connectionLine << "";
    }
    else
    {
        cout << leftSpacing << string(width / 4, ' ');
    }

    if (subNode->right)
    {
        cout << connectionLine << leftSpacing;
    }
    else
    {
        cout << string(width / 4, ' ') << leftSpacing;
    }
}

void Bst::PrintConnections(TreeNode *subNode, int level, int width) // agac cizdirme
{

    if (level < 0)
        return;

    if (!subNode)
    {

        cout << string(width, ' ');
        return;
    }

    if (level == 0)
    {
        Derinlik(subNode, level, width);
    }
    else
    {
        PrintConnections(subNode->left, level - 1, width / 2);
        PrintConnections(subNode->right, level - 1, width / 2);
    }
}

void Bst::PrintLevel(TreeNode *subNode, int level, int width) // levelorder cizdrime
{
    if (!subNode)
    {

        cout << string(width, ' ');
        return;
    }

    if (level == 0)
    {
        cout << string(width / 2 - 1, ' ') << subNode->data << string(width / 2, ' ');
    }
    else
    {
        PrintLevel(subNode->left, level - 1, width / 2);
        PrintLevel(subNode->right, level - 1, width / 2);
    }
}

void Bst::mirrorBST(TreeNode *root) // aynalama fonksiyon govdesi
{
    if (!root)
    {
        return;
    }
    TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirrorBST(root->left);
    mirrorBST(root->right);
}

Bst::Bst()
{
    root = NULL;
}
bool Bst::isEmpty() const
{
    return root == NULL;
}
void Bst::add(const char &newItem)
{
    SearchAndAdd(root, newItem);
}
void Bst::Delete(const char &data)
{
    if (SearchAndDelete(root, data) == false)
        throw "Item not found.";
}
void Bst::Clear()
{
    while (!isEmpty())
        DeleteNode(root);
}
int Bst::Height()
{
    return Height(root);
}
int Bst::Sum()
{

    int ans = treesum(root, false);
    return ans;
}
void Bst::Mirror()
{
    mirrorBST(root);
}
void Bst::levelorder()
{
    int h = Height();
    int maxWidth = pow(2, h) * 3;

    for (int level = 0; level <= h; level++)
    {

        PrintLevel(root, level, maxWidth);
        cout << "\n";
        if (level < h)
        {
            PrintConnections(root, level, maxWidth);
            cout << "\n";
        }
    }
}
Bst::~Bst()
{
    Clear();
}