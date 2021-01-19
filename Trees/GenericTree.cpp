#include <iostream>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

class Node
{
public:
    int data;
    vector<Node *> childs;

    Node(int data)
    {
        this->data = data;
    }
};

Node *createTree(vector<int> &arr)
{
    stack<Node*> st;
    for(int i=0;i<arr.size()-1;i++)
    {
        if(arr[i]==-1) // nullptr
        {
            Node *top = st.top();
            st.pop();
            st.top()->childs.push_back(top);
        }
        else // node create
        {
            st.push(new Node(arr[i]));
        }
    }
    return st.top();
}

void preOrder(Node *node)
{
    if(!node)
    return;
    cout<<node->data<<" ";
    for (Node *child : node->childs)
    preOrder(child);
}

void postOrder(Node *node)
{
    if (!node)
        return;
    for (Node *child : node->childs)
        postOrder(child);
    cout << node->data << " ";
}

int height(Node *node)
{
    if (node == nullptr)
        return 0;
    int h = 0;
    for (Node *child : node->childs)
    h = max(h, height(child));
    return h+1;
}

int size(Node *node)
{
    if (node == nullptr)
        return 0;
    int siz = 0;
    for (Node *child : node->childs)
        siz += size(child);
    return siz + 1;
}

void display(Node *node)
{
    if(!node)
    return;
    string str= to_string(node->data)+ " -> ";
    for(Node *child: node->childs)
    str+= to_string(child->data) + ", ";
    cout<<str<<endl;
    for (Node *child : node->childs)
    display(child);
}

bool find(Node *node, int data)
{
    if(!node)
    return 0;
    if(node->data == data)
    return 1;
    bool res=0;
    for(Node *child : node->childs)
        res= res || find(child,data);
    return res;
}

void levelOrderLlineWise(Node *node)
{
    if (!node)
        return;
    queue<Node *> q;
    q.push(node);
    while (q.size() != 0)
    {
        Node *rvtx = q.front();
        q.pop();
        cout << rvtx->data << " ";
        for(Node *child : node->childs)
        q.push(child);
    }
}

bool nodeToRootPath(Node *node, int data, vector<Node *> &path)
{
    if (node == nullptr)
        return false;
    if (node->data == data)
    {
        path.push_back(node);
        return true;
    }
    bool res=0;
    for (Node *child : node->childs)
        res = nodeToRootPath(child, data, path) || res;
    if (res)
        path.push_back(node);
    return res;
}

void set1(Node *node)
{
    vector<Node *> ans;
    cout<<"Found: "<< nodeToRootPath(node, 140, ans);
    display(node);
}

void solve()
{
    vector<int> arr{10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 100, -1, 110, -1, -1, 90, -1, -1, 40, 120, 140, -1, 150, -1, -1, -1, -1};
    Node *root = createTree(arr);
    // display(root);
    set1(root);
}

int main()
{
    solve();
    return 0;
}