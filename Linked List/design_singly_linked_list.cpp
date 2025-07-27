#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int value) : val(value), next(nullptr) {}
};

class MyLinkedList
{
public:
    Node *head;
    int size;

    MyLinkedList() : head(nullptr), size(0) {}

    int get(int index)
    {
        if (index < 0 || index >= size)
            return -1;

        Node *curr = head;
        for (int i = 0; i < index; ++i)
            curr = curr->next;

        return curr->val;
    }

    void addAtHead(int val)
    {
        addAtIndex(0, val);
    }

    void addAtTail(int val)
    {
        addAtIndex(size, val);
    }

    void addAtIndex(int index, int val)
    {
        if (index < 0 || index > size)
            return;

        if (index == 0)
        {
            Node *new_node = new Node(val);
            new_node->next = head;
            head = new_node;

            ++size;
            return;
        }

        Node *curr = head;
        Node *newNode = new Node(val);
        for (int i = 0; i < index - 1; ++i)
        {
            curr = curr->next;
        }

        newNode->next = curr->next;
        curr->next = newNode;

        ++size;
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= size)
            return;

        if (index == 0)
        {
            head = head->next;
            --size;
            return;
        }

        Node *curr = head;
        for (int i = 0; i < index - 1; ++i)
        {
            curr = curr->next;
        }

        curr->next = curr->next->next;
        --size;
    }
};