#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Node
{
public:
    int data;
    Node *left = nullptr;
    Node *right = nullptr;
    int height = 0;
    int bal = 0; // diff between left and right subtree
    Node(int data)
    {
        this->data = data;
    }
};
void display(Node *node)
{
    if (node == nullptr)
        return;
    string str = "";
    str += node->left ? to_string(node->left->data) : ".";
    str += " <- " + to_string(node->data) + " -> ";
    str += node->right ? to_string(node->right->data) : ".";
    cout << str << endl;
    display(node->left);
    display(node->right);
}

// AVL_Util.============================================================================
void updateHeightBalance(Node* node)
{
    int left_h=0;
    int right_h=0;
    
    if(node->left != nullptr)
        left_h = node->left->height;
    if (node->right != nullptr)
        right_h = node->right->height;
        
    node->height = max(left_h,right_h)+1;
    node->bal= left_h - right_h;
}
// left left skew -> RIGHT ROTATE
Node* rightrotate(Node* A)
{
    Node *B= A->left;
    Node *BKaRight= B->right;
    B->right=A;
    A->left= BKaRight;
    updateHeightBalance(A);
    updateHeightBalance(B);
    return B;
}

// right right skew -> LEFT ROTATE
Node* leftrotate(Node* A)
{
    Node *B= A->right;
    Node *BKaLeft= B->left;
    B->left = A;
    A->right= BKaLeft;
    updateHeightBalance(A);
    updateHeightBalance(B);
    return B;
}

Node* rotateSubTree(Node* node)
{
    updateHeightBalance(node);
    if(node->bal > 2) // left skew, left right case
    { 
        if(node->left->bal > 1)
        {
            // left skew tree
            return rightrotate(node);
        }
        else
        {
            //left right case
            node->left = leftrotate(node->left);
            // now it will be left skew tree so right rotate 
            return rightrotate(node);
        }
    }
    else if(node->bal < -2)
    {
        if (node->right->bal < -1)
        {
            // right skew tree
            return leftrotate(node);
        }
        else
        {
            //right left case
            node->right = rightrotate(node->right);
            // now it will be right skew tree so left rotate
            return leftrotate(node);
        }
    }
    return node;
}

// BST_Functions.==========================================================================
Node* addData(Node* root, int data)
{
    if(root==NULL)
        return (new Node(data));
    if(data < root->data)
        root->left = addData(root->left,data);
    else
        root->right = addData(root->right, data);
    return rotateSubTree(root);
}

int maximum(Node* node)
{
    Node *curr=node;
    while(curr->right)
    curr=curr->right;
    return curr->data;
}
Node* removeData(Node* root, int data)
{
    if(!root)
    return nullptr;
    if(data > root->data)
    {
        root->right = removeData(root->right,data);
    }
    else if(data < root->data)
    {
        root->left = removeData(root->left, data);
    }
    else
    {
        if(!root->left && !root->right)
        return NULL;
        if(!root->left)
        return root->right;
        if(!root->right)
        return root->left;
        int maxele= maximum(root->left);  // or root->right ka leftmost
        root->data= maxele;
        root->left= removeData(root->left,maxele);
    }
    return rotateSubTree(root);
}
void solve()
{
    vector<int> arr(15);
    for (int i = 0; i < arr.size(); i++)
        arr[i] = (i + 1) * 10;

    Node* root = nullptr;
    for (int ele : arr)
        root = addData(root, ele);
    rotateSubTree(root);
    display(root);
    cout<<endl;
    // int i = 0;
    // for (int ele : arr)
    // {
    //     root = removeData(root, ele);
    //     if (i++ == 6)
    //         break;
    // }
    // display(root);
}
int main()
{
    solve();
    return 0;
}
