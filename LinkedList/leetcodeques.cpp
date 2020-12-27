#include <bits/stdc++.h>
using namespace std;
class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 876=================================================
ListNode *middleNode(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (!fast->next)
        return slow;
    return slow->next;
}

//148========================================================
ListNode *middleNode(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (!fast->next)
        return slow;
    return slow->next;
}
ListNode *merge(ListNode *first, ListNode *second)
{
    if (!first)
        return second;
    if (!second)
        return first;
    ListNode *t1 = first, *t2 = second;
    ListNode *head = new ListNode(-1);
    ListNode *cur = head;
    while (t1 && t2)
    {
        if (t1->val <= t2->val)
        {
            cur->next = t1;
            t1 = t1->next;
        }
        else
        {
            cur->next = t2;
            t2 = t2->next;
        }
        cur = cur->next;
        cur->next = NULL;
    }
    if (t1)
    {
        cur->next = t1;
    }
    if (t2)
    {
        cur->next = t2;
    }
    return head->next;
}
ListNode *sortList(ListNode *head)
{
    if (!head || !head->next)
        return head;
    ListNode *mid = middleNode(head);
    ListNode *end = head;
    while (end->next != mid)
    {
        end = end->next;
    }
    end->next = NULL;
    return merge(sortList(head), sortList(mid));
}

// 206================================================
ListNode *reverseList(ListNode *head)
{
    if (!head || !head->next)
        return head;
    ListNode *prev = NULL;
    ListNode *cur = head;
    ListNode *temp = NULL;
    while (cur)
    {
        temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    return prev;
}

// 234==================================================
ListNode *middleNode(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
ListNode *reverseList(ListNode *head)
{
    if (!head || !head->next)
        return head;
    ListNode *prev = NULL;
    ListNode *cur = head;
    ListNode *temp = NULL;
    while (cur)
    {
        temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    return prev;
}
bool isPalindrome(ListNode *head)
{
    if (!head || !head->next)
        return 1;
    ListNode *first = head;
    ListNode *mid = middleNode(head);
    ListNode *second = reverseList(mid->next);
    mid->next = NULL;

    while (first && second)
    {
        if (first->val != second->val)
            return 0;
        first = first->next;
        second = second->next;
    }
    return 1;
}

// 143======================================================
ListNode *reverseList(ListNode *head)
{
    if (!head || !head->next)
        return head;
    ListNode *prev = NULL;
    ListNode *cur = head;
    ListNode *temp = NULL;
    while (cur)
    {
        temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    return prev;
}
ListNode *middleNode(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
void reorderList(ListNode *head)
{
    if (!head || !head->next)
        return;
    ListNode *mid = middleNode(head);
    ListNode *end = head;
    // 1 2 3 4 5
    while (end->next != mid->next)
        end = end->next;
    ListNode *second = reverseList(mid->next);
    end->next = NULL;
    ListNode *first = head;
    while (second && first)
    {
        ListNode *f_next = first->next;
        first->next = second;
        second = second->next;
        (first->next)->next = f_next;
        first = f_next;
    }
    return;
}

// 19==================================================
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    int size = 0;
    ListNode *temp = head;
    while (temp)
    {
        size++;
        temp = temp->next;
    }
    // cout<<size;
    // n=n%(size+1);
    n = size - n;
    if (n == 0)
        return head->next;
    ListNode *prev = head;
    ListNode *cur = head;
    for (int i = 1; i < n; i++)
    {
        prev = prev->next;
    }
    cur = prev->next;
    prev->next = NULL;
    if (cur && cur->next)
    {
        prev->next = cur->next;
    }
    return head;
}

// 23======================================================
ListNode *merge2list(ListNode *f, ListNode *s)
{
    if (f && !s)
        return f;
    if (s && !f)
        return s;
    ListNode *p1 = f;
    ListNode *p2 = s;
    ListNode *newh = new ListNode(-1);
    ListNode *cur = newh;
    while (p1 && p2)
    {
        if (p1->val <= p2->val)
        {
            cur->next = p1;
            cur = cur->next;
            p1 = p1->next;
        }
        else
        {
            cur->next = p2;
            cur = cur->next;
            p2 = p2->next;
        }
        cur->next = NULL;
    }
    if (p1)
        cur->next = p1;
    if (p2)
        cur->next = p2;
    return newh->next;
}
ListNode *mergelist(vector<ListNode *> &lists, int l, int r)
{
    if (l == r)
        return lists[l];
    int m = (l + r) / 2;
    ListNode *left = mergelist(lists, l, m);
    ListNode *right = mergelist(lists, m + 1, r);
    return merge2list(left, right);
}
ListNode *mergeKLists(vector<ListNode *> &lists)
{
    if (lists.size() == 0)
        return NULL;
    return mergelist(lists, 0, lists.size() - 1);
}

// 141===================================================
bool hasCycle(ListNode *head)
{
    ListNode *slow = head, *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return 1;
    }
    return 0;
}

// 142===================================================
                                // 1 2 3 4 5 6 7 8
                                //       |-------|
                                // f  s    f  s    f  s
                                // 1  6    6  1    6  1
                                // 3  7    8  2    7  2
                                // 5  8    5  3    8  3
                                // 7  4    7  4    4  4
                                // 4  5    4  5
                                // 6  6    6  6
ListNode *detectCycle(ListNode *head)
{
    ListNode *slow = head, *fast = head;
    bool res = 0;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            res = 1;
            break;
        }
    }
    if (res == 0)
        return NULL;
    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

// 160============================================================

              // optmized approach
ListNode *detectCycle(ListNode *head)
{
    ListNode *slow = head, *fast = head;
    bool res = 0;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            res = 1;
            break;
        }
    }
    if (res == 0)
        return NULL;
    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
ListNode *getIntersectionNode(ListNode *h1, ListNode *h2)
{
    if (!h1 || !h2)
        return NULL;
    ListNode *t1 = h1;
    while (t1->next)
        t1 = t1->next;
    t1->next = h2;
    ListNode *intersect = detectCycle(h1);
    t1->next = NULL;
    return intersect;
}


                     // brute force approach
int findlen(ListNode *head)
{
    int size = 0;
    while (head)
    {
        head = head->next;
        size++;
    }
    return size;
}
ListNode *getIntersectionNode(ListNode *h1, ListNode *h2)
{
    int l1 = findlen(h1);
    int l2 = findlen(h2);
    int diff = 0;
    if (l1 > l2)
    {
        diff = l1 - l2;
        while (diff-- > 0)
        {
            h1 = h1->next;
        }
    }
    else
    {
        diff = l2 - l1;
        while (diff-- > 0)
        {
            h2 = h2->next;
        }
    }
    //list's len are equal now
    while (h1 && h2)
    {
        if (h1 == h2)
            return h1;
        h1 = h1->next;
        h2 = h2->next;
    }
    return NULL;
}

// 25============================================
ListNode *oh = NULL, *ot = NULL;
ListNode *th = NULL, *tt = NULL;
int findlen(ListNode *head)
{
    int size = 0;
    while (head)
    {
        head = head->next;
        size++;
    }
    return size;
}
void addfirstNode(ListNode *rnode)
{
    if (th == NULL)
    {
        th = rnode;
        tt = rnode;
    }
    else
    {
        rnode->next = th;
        th = rnode;
    }
}
ListNode *reverseKGroup(ListNode *head, int k)
{
    if (!head || !head->next || k <= 1)
        return head;
    int len = findlen(head);
    if (k > len)
        return head;
    ListNode *cur = head;
    while (cur && len >= k)
    {
        int temp = k;
        while (temp-- > 0)
        {
            ListNode *rnode = cur;
            cur = cur->next;
            rnode->next = NULL;
            addfirstNode(rnode);
        }
        if (oh == NULL)
        {
            oh = th;
            ot = tt;
        }
        else
        {
            ot->next = th;
            ot = tt;
        }
        th = NULL;
        tt = NULL;
        len -= k;
    }
    ot->next = cur;
    return oh;
}

// 92===========================================
ListNode *reverselist(ListNode *head)
{
    ListNode *curr, *prev;
    curr = head;
    prev = NULL;
    while (curr)
    {
        ListNode *f = curr->next;
        curr->next = prev;
        prev = curr;
        curr = f;
    }
    return prev;
}
ListNode *reverseBetween(ListNode *head, int m, int n)
{
    if (m == n)
        return head;
    ListNode *curr, *end, *left, *right;
    curr = head;
    int i = 1;
    left = NULL;
    while (i < m)
    {
        i++;
        left = curr;
        curr = curr->next;
    }
    end = curr;
    while (i < n)
    {
        i++;
        end = end->next;
        right = end->next;
    }
    if (end)
        end->next = NULL;
    if (left)
        left->next = NULL;
    curr = reverselist(curr);
    if (left)
        left->next = curr;
    if (!left)
        head = curr;
    end = curr;
    while (end->next)
        end = end->next;
    end->next = right;
    return head;
}

// 430=================================================
Node *flatten(Node *head)
{
    Node *cur = head;
    while (cur)
    {
        // cout<<cur->val<<endl;
        if (cur->child)
        {
            Node *c_next = cur->next;
            cur->next = cur->child;
            cur->child = NULL;
            (cur->next)->prev = cur;
            Node *temp = cur->next;
            while (temp->next)
                temp = temp->next;
            temp->next = c_next;
            if (c_next)
                c_next->prev = temp;
        }
        cur = cur->next;
    }
    return head;
}
int main()
{
    return 0;
}