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
    Node(int data)
    {
        this->data = data;
    }
};

int idx = 0;
Node *constructTree(vector<int> &arr)
{
    if(idx==arr.size() || arr[idx]==-1)
    {
        idx++;
        return nullptr;
    }
    Node *node = new Node(arr[idx]);
    idx++;
    node->left = constructTree(arr);
    node->right = constructTree(arr);
    return node;
}

void inOrder(Node *node)
{
    if(node==nullptr)
    return;
    inOrder(node->left);
    cout<<node->data<<" ";
    inOrder(node->right);
}

int size(Node *node)
{
    if(node==nullptr)
        return 0;
    return size(node->left)+size(node->right)+1;
}

int height(Node *node)
{
    if (node == nullptr)
        return 0;
    return max(height(node->left) ,height(node->right)) + 1;
}

int maximum(Node *node)
{
    if (node == nullptr)
        return -1e8;
    return max(max(maximum(node->left), maximum(node->right)),node->data);
}

int minimum(Node *node)
{
    if (node == nullptr)
        return 1e8;
    return min(min(minimum(node->left), minimum(node->right)), node->data);
}

bool find(Node *node, int data)
{
    if(!node)
    return false;
    if(node->data==data)
    return true;
    return find(node->left,data)||find(node->right,data);
}

bool rootToNodePath(Node *node, int data, vector<Node *> &path)
{
    if (node == nullptr)
        return false;
    if (node->data == data)
    {
        path.push_back(node);
        return true;
    }
    bool res = rootToNodePath(node->left, data, path) || rootToNodePath(node->right, data, path);
    if (res)
        path.push_back(node);
    return res;
}

Node *lowestCommonAncestor(Node *root,int p, int q)
{
    vector<Node*> p1,p2;
    bool res = rootToNodePath(root, p, p1) && rootToNodePath(root, q, p2);
    if(!res)
    return NULL;
    Node *LCA = root;
    {
        int c1=p1.size()-1;
        int c2=p2.size()-1;
        while(c1>=0 && c2>=0 &&p1[c1]->data == p2[c2]->data)
        {
            LCA= p1[c1];
            c1--;
            c2--;
        }
    }
    return LCA;
}

int distanceBWNodes(Node *root, int p, int q)
{
    vector<Node *> p1, p2;
    bool res = rootToNodePath(root, p, p1) && rootToNodePath(root, q, p2);
    if (!res)
        return NULL;
    int LCA = 0;
    {
        int c1 = p1.size() - 1;
        int c2 = p2.size() - 1;
        while (c1 >= 0 && c2 >= 0 && p1[c1]->data == p2[c2]->data)
        {
            LCA++;
            c1--;
            c2--;
        }
    }
    return p1.size()+p2.size()-2*LCA;
}

int diameter(Node *root)
{
    if(!root)
    return 0;
    int ld= diameter(root->left);
    int rd = diameter(root->right);
    int lh = height(root->left);
    int rh = height(root->right);
    return max(max(ld,rd),lh+rh+1);
}

//LevelOrder/BFS.=======================================================================

void levelOrder_01(Node *node)
{
    if(!node)
    return;
    queue<Node*> q;
    q.push(node);
    while(q.size()!=0)
    {
        Node *rvtx=q.front();
        q.pop();
        cout<<rvtx->data<<" ";
        if(rvtx->left)
        q.push(rvtx->left);
        if (rvtx->right)
            q.push(rvtx->right);
    }
}

void levelOrder_02(Node *node)
{
    if (!node)
        return;
    queue<Node *> q;
    q.push(node);
    q.push(nullptr);
    while (q.size() != 1)
    {
        Node *rvtx = q.front();
        q.pop();
        if(rvtx == nullptr)
        {
            cout<<endl;
            q.push(nullptr);
            continue;
        }
        cout << rvtx->data << " ";
        if (rvtx->left)
            q.push(rvtx->left);
        if (rvtx->right)
            q.push(rvtx->right);
    }
}

void levelOrder_03(Node *node)
{
    
}

//Views.======================================================================

void leftView(Node *node)
{
    
}

void rightView(Node *node)
{
    
}

void width(Node *node, int level, pair<int, int> &maxMin)
{
    
}

void verticalOrderTraversal(Node *node)
{
    
}

void verticalOrderSum(Node *node)
{
    
}

void verticalView(Node *node)
{
    
}

void BottomView(Node *node)
{
    
}

//Traversal. ===============================================================

Node *rightMost(Node *next, Node *curr)
{
    
}

void morrisInOrderTraversal(Node *node)
{
    
}

void morrisPreOrderTraversal(Node *node)
{
    
}

void traversal(Node *root)
{
    // morrisInOrderTraversal(root);
    // morrisPreOrderTraversal(root);
}

void display(Node *node)
{
    if(node==nullptr)
    return;
    string str="";
    str+= node->left ? to_string(node->left->data):".";
    str+= " <- " +to_string(node->data) + " -> ";
    str += node->right ? to_string(node->right->data) : ".";
    cout<<str<<endl;
    display(node->left);
    display(node->right);
}

void set1(Node *root)
{
    // levelOrder_01(root);
    // levelOrder_02(root);
    // levelOrder_03(root);

    // leftView(root);
    // rightView(root);
    // verticalOrderTraversal(root);
    // verticalView(root);
    // BottomView(root);
}

void solve()
{
    vector<int> arr = {10, 20, 30, 40, -1, -1, 50, -1, -1, 60, 70, -1, 80, -1, -1, -1, 90, 100, -1, 120, -1, -1, 110, 130, -1, -1, -1};
    // vector<int> arr = {-15, 5, -8, 2, -1, -1, 6, -1, -1, 1, -1, -1, 6, 3, -1, -1, 9, -1, 0, 4, -1, -1, -2, 10, -1, -1, -1};

    Node *root = constructTree(arr);
    // inOrder(root);
    // display(root);
    // vector<Node*>path;
    // cout<<rootToNodePath(root,1300,path)<<endl;
    // for(int i=0;i<path.size();i++)
    // cout<<path[i]->data<<" ";
    // cout<<endl;
    // Node *ans=lowestCommonAncestor(root,40,70);
    // cout<<ans->data<<endl;
    // cout<<size(root)<<endl;
    // cout << height(root) << endl;
    // cout << maximum(root) << endl;
    // cout << minimum(root) << endl;
    // cout << diameter(root) << endl;
    levelOrder_01(root);
    cout<<endl;
    levelOrder_02(root);
    // traversal(root);
}

int main()
{
    solve();
    return 0;
}