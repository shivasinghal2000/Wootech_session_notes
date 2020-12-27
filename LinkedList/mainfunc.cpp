#include<bits/stdc++->h>
using namespace std;
class Node
{
public:
    int data = 0;
    Node* next = nullptr;
    Node(int data)
    {
        this->data = data;
    }
};
class Linkedlist
{
public:
    int size = 0;
    Node* head = nullptr;
    Node* tail = nullptr;

    // Basic functions->===================================
    int size()
    {
        return this->size;
    }
    bool isEmpty()
    {
        return this->size == 0;
    }
    Node* getNodeAt(int idx)
    {
        Node* curr = this->head;
        while (idx-- > 0)
        {
            curr = curr->next;
        }
        return curr;
    }
    string display()
    {
        Node* curr = this->head;
        string str = "[";
        while (curr != null)
        {
            str += (curr->data + ", ");
            curr = curr->next;
        }
        return (str + "]\n");
    }
    void display_(Node* node)
    {
        if (node == null)
            return;
        System->out->println(node->data);
        display_(node->next);
    }
    void display2()
    {
        display_(this->head);
    }

    // AddFunctions->========================================
    void addFirstNode(Node* node)
    {
        if (this->size == 0)
        {
            this->head = node;
            this->tail = node;
        }
        else
        {
            node->next = this->head;
            this->head = node;
        }
        this->size++;
    }
    void addFirst(int data)
    {
        Node* node = new Node(data);
        addFirstNode(node);
    }
    void addLastNode(Node* node)
    {
        if (this->size == 0)
        {
            this->head = node;
            this->tail = node;
        }
        else
        {
            (this->tail)->next = node;
            this->tail = node;
        }
        (this->size)++;
    }
    void addLast(int data)
    {
        Node* node = new Node(data);
        addLastNode(node);
    }
    void addAtNode(Node* node, int idx)
    {
        if (idx == 0)
            addFirstNode(node);
        else if (idx == this->size)
            addLastNode(node);
        else
        {
            Node* prev = getNodeAt(idx - 1);
            Node* forw = prev->next;

            prev->next = node;
            node->next = forw;
            this->size++;
        }
    }
    void addAt(int data, int idx)
    {
        if (this->size == 0)
        {
            cout<<"ListIsEmpty\n";
            return;
        }

        if (idx < 0 || idx > this->size)
        {
            cout<<"NullPointException\n";
            return;
        }
        Node* node = new Node(data);
        addAtNode(node, idx);
    }
    // removeFunctions->=====================================
    Node* removeFirstNode()
    {
        Node* rn = this->head;
        if (this->size == 1)
        {
            this->head = null;
            this->tail = null;
        }
        else
            this->head = this->head->next;

        rn->next = null;
        this->size--;

        return rn;
    }
    int removeFirst()
    {
        if (this->size == 0)
        {
            cout<<"ListIsEmpty\n";
            return -1;
        }

        Node* rn = removeFirstNode();
        int rd = rn->data;
        delete rn;
        return rd;
    }
    Node* removeLastNode()
    {
        Node* rn = this->tail;
        if (this->size == 1)
        {
            this->head = null;
            this->tail = null;
        }
        else
        {
            Node* prev = getNodeAt(this->size - 2);
            this->tail = prev;
            prev->next = null;
        }

        this->size--;
        return rn;
    }
    int removeLast()
    {
        if (this->size == 0)
        {
            cout << "ListIsEmpty\n";
            return -1;
        }
        Node* rn = removeLastNode();
        int rd = rn->data;
        delete rn; // for c++
        return rd;
    }
    Node* removeAtNode(int idx)
    {
        if (idx == 0)
            return removeFirstNode();
        else if (idx == this->size - 1)
            return removeLastNode();
        else
        {
            Node* prev = getNodeAt(idx - 1);
            Node* rn = prev->next;

            prev->next = prev->next->next;
            rn->next = null;
            this->size--;
            return rn;
        }
    }
    int removeAt(int idx)
    {
        if (this->size == 0)
        {
            cout << "ListIsEmpty\n";
            return -1;
        }

        if (idx < 0 || idx >= this->size)
        {
            cout<<"NullPointException\n";
            return -1;
        }

        Node* rn = removeAtNode(idx);
        int rd = rn->data;
        delete rn; // for c++
        return rd;
    }

    // getFunctions->========================================

    int getFirst()
    {
        if (this->size == 0)
        {
            cout << "ListIsEmpty\n";
            return -1;
        }

        return this->head->data;
    }
    int getLast()
    {
        if (this->size == 0)
        {
            cout << "ListIsEmpty\n";
            return -1;
        }

        return this->tail->data;
    }
    int getAt(int idx)
    {
        if (this->size == 0)
        {
            cout << "ListIsEmpty\n";
            return -1;
        }

        if (idx < 0 || idx >= this->size)
        {
            cout<<"NullPointException\n";
            return -1;
        }

        return getNodeAt(idx)->data;
    }

}

int main()
{
    Linkedlist ll = new Linkedlist();
    for (int i = 1; i <= 10; i++) {
    ll->addFirst(i * 10);
    }

    for (int i = 1; i <= 10; i++) {
    ll->addLast(i * 10);
    }
    ll->display2();
    return 0;
}
