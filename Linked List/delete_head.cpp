#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *next;

    Node(int val) : value(val), next(nullptr) {}
};

class MyLL
{
public:
    Node *head;
    int size;

    MyLL() : head(nullptr), size(0) {}

    void add(int v)
    {
        Node *new_node = new Node(v);

        if (!head)
        {
            head = new_node;
            size = 1;
            return;
        }

        Node *mover = head;
        while (mover->next)
            mover = mover->next;

        mover->next = new_node;
        ++size;
    }

    void print()
    {
        Node *curr = head;
        while (curr)
        {
            cout << curr->value << " ";
            curr = curr->next;
        }

        cout << endl;
    }

    void delHead()
    {
        if (!head)
            return;

        Node *temp = head->next;
        delete head;
        head = temp;
        --size;
    }

    ~MyLL()
    {
        Node *ptr = head;
        while (head)
        {
            delete ptr;
            head = head->next;
            ptr = head;
        }
    }
};

int main()
{
    MyLL *l = new MyLL();
    l->add(5);
    l->add(1);
    l->add(7);
    l->add(4);
    l->print();

    l->delHead();
    l->delHead();
    l->delHead();
    l->print();

    return 0;
}