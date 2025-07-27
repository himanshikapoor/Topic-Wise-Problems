#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(T data, T *next)
    {
        this->data = data;
        this->next = next;
    }
};

int searchInLinkedList(Node<int> *head, int k)
{
    // Write your code here.
    if (head == NULL)
        return 0;

    Node<int> *curr = head;

    while (curr != NULL)
    {
        if (curr->data == k)
        {
            return 1;
        }
        curr = curr->next;
    }

    return 0;
}