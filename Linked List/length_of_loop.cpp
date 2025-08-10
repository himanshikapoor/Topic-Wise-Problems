#include <bits/stdc++.h>

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

int findLength(Node *intersection)
{
    int d = 1;
    Node *temp = intersection->next;

    while (temp != intersection)
    {
        ++d;
        temp = temp->next;
    }

    return d + 1;
}

int lengthOfLoop(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return findLength(slow);
        }
    }

    return 0;
}
