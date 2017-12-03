#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

ifstream in("data.in");
ofstream out("data.out");

struct node
{
private:
    node *left, *right;
    int value;
    int initialized;

public:
    
    static queue <node*> addOrder;
    static node* BTroot;
    node();
    static void addNode(int);

    void inorderPrint();
    void preorderPrint();
    void postorderPrint();
    
    int inorderRet();
    int preorderRet();
    int postorderRet();
    
    int getvalue() {return value;}
};

queue <node*> node::addOrder;
node* node::BTroot = NULL;
vector <int> inorder, postorder;
int n;

node::node()
{
    left = NULL;
    right = NULL;
    initialized = 0;
}

void node::addNode(int val)
{
    node* root;
    if (BTroot == NULL)
    {
        BTroot = new node;
        root = BTroot;
    }
    else
    {
        root = addOrder.front();
        node::addOrder.pop();
    }
    root -> value = val;
    root -> initialized ++;
    root -> left = new node;
    root -> right = new node;
    out << "\n Added " << val << " on address " << root << " - his childs are " << root -> left << ", " << root -> right;
    node::addOrder.push(root->left);
    node::addOrder.push(root->right);
}

void node::inorderPrint()
{
    if ((this != NULL) && (initialized))
    {
        (this -> left) -> inorderPrint();
        out << this -> value << " ";
        (this -> right) -> inorderPrint();
    }
}
void node::preorderPrint()
{
    if ((this != NULL) && (initialized))
    {
        out << this -> value << " ";
        (this -> left) -> preorderPrint();
        (this -> right) -> preorderPrint();
    }
}
void node::postorderPrint()
{
    if ((this != NULL) && (initialized))
    {
        (this -> left) -> postorderPrint();
        (this -> right) -> postorderPrint();
        out << this -> value << " ";
    }
}
int node::inorderRet()
{
    if ((this != NULL) && (initialized))
    {
        (this -> left) -> inorderPrint();
        return this -> value;
        (this -> right) -> inorderPrint();
    }
}
int node::preorderRet()
{
    if ((this != NULL) && (initialized))
    {
        return this -> value;
        (this -> left) -> preorderPrint();
        (this -> right) -> preorderPrint();
    }
}
int node::postorderRet()
{
    if ((this != NULL) && (initialized))
    {
        (this -> left) -> postorderPrint();
        (this -> right) -> postorderPrint();
        return this -> value;
    }
}

void readInorder()
{
    int val;
    for (int i = 0; i < n; i++)
    {
        in >> val;
        inorder[i] = val;
    }
}

void readPostorder()
{
    int val;
    for (int i = 0; i < n; i++)
    {
        in >> val;
        postorder[i] = val;
    }
}

int skip = 0;

void pushBinaryTree(vector <int> inord, vector <int> postord)
{
    //search for the current node in the inorder vector
    int rootPosInorder;
    for (int i = 0; i < inord.size(); i++)
        if (inord.at(i) == postord.back())
            {
                rootPosInorder = i;
                i = n;
            }

    //left subtree has the values that are on the LHS of current node in inorder
    vector <int> LHS, LHSpost;
    for (int i = 0; i < rootPosInorder; i++)
            LHS.push_back(inord[i]);
    for (int i = 0; i < postord.size(); i++)
    {
        int j = 0;
        while (j != LHS.size())
        {
            if (postord[i] == LHS[j])
            {
                LHSpost.push_back(postord[i]);
                j = LHS.size();
            }
            else
                j++;
        }
    }

    //right subtree has the values that are on the LHS of current node in inorder
    vector <int> RHS, RHSpost;
    for (int i = rootPosInorder + 1; i < inord.size(); i++)
            RHS.push_back(inord[i]);
    for (int i = 0; i < postord.size(); i++)
    {
        int j = 0;
        while (j != RHS.size())
        {
            if (RHS[j] == postord[i])
            {
                RHSpost.push_back(postord[i]);
                j = RHS.size();
            }
            else
                j++;
        }
    }
    
    //add left child
    if(LHS.size() > 0)
    node::addNode(LHSpost.back());
    //add right child
    if(RHS.size() > 0)
    node::addNode(RHSpost.back());
    
    if(LHS.size() > 0)
    pushBinaryTree(LHS, LHSpost);
    
    if(RHS.size() > 0)
    pushBinaryTree(RHS, RHSpost);  
}

int checkValid(vector <int> &inorder, vector<int> &postorder)
{
    vector <int> newInorder, newPostorder;
    newInorder.push_back(node::BTroot -> inorderRet());
    newPostorder.push_back(node::BTroot -> postorderRet());
    if ((inorder.size() == newInorder.size()) && (postorder.size() == newPostorder.size()))
    {
        int ok = 1;
        for (int i = 0; i < inorder.size(); i++)
        {
            //out << "\nI'm at " << i;
            if (inorder[i] != newInorder[i])
                return 0;
            if (postorder[i] != newPostorder[i])
                return 0;
        }
        return ok;
    }
    else
        return 0;
}
int main()
{
    in >> n; // No of nodes
    inorder.resize(n);
    postorder.resize(n);
    readInorder();
    readPostorder();
    
    //add the root
    node::addNode(postorder.back());

    pushBinaryTree(inorder, postorder);

    vector <int> finalIn, finalPost;
    
    out << "\nPreorder:\t";
    node::BTroot -> preorderPrint();
    out << "\nInorder:\t";
    node::BTroot -> inorderPrint();
    out << "\nPostorder:\t";
    node::BTroot -> postorderPrint();
/*
    if (checkValid(inorder, postorder))
        out << "\nValid input data.\t";
    else
        out << "\nInvalid input data.\n";
*/
    return 0;
}