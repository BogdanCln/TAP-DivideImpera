#include <iostream>
#include <fstream>
using namespace std;

ifstream in("data.in");
ofstream out("data.out");

struct node
{
private:
    node *left = NULL, *right = NULL;
    int value;

public:
    void addNode(node*&, int);
    void inorderPrint();
    void preorderPrint();
    void postorderPrint();
};

void node::addNode(node*& root, int val)
{
    if (root == NULL)
    {
        root = new node;
        root -> value = val;
    }
    else
    {
        if (root -> value > val)
            addNode(root -> left, val);
        else
            addNode(root -> right, val);
    }
}

void node::inorderPrint()
{
    if (this != NULL)
    {
        (this -> left) -> inorderPrint();
        out << this -> value << " ";
        (this -> right) -> inorderPrint();
    }
}
void node::preorderPrint()
{
    if (this != NULL)
    {
        out << this -> value << " ";
        (this -> left) -> preorderPrint();
        (this -> right) -> preorderPrint();
    }
}
void node::postorderPrint()
{
    if (this != NULL)
    {
        (this -> left) -> postorderPrint();
        (this -> right) -> postorderPrint();
        out << this -> value << " ";
    }
}

int main()
{
    int n;
    in >> n; // No of nodes

    node *BSTroot = NULL;

    for (int i = 0; i < n; i++)
    {
        int val;
        in >> val;
        BSTroot -> addNode(BSTroot, val);
    }
    
    out << "\nInorder:\t";
    BSTroot -> inorderPrint();
    out << "\nPreorder:\t";
    BSTroot -> preorderPrint();
    out << "\nPosorder:\t";
    BSTroot -> postorderPrint();

    return 0;
}