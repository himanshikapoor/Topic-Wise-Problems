// Maintain a gap of N between slow and fast pointers
#include <bits/stdc++.h>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (!head || !head->next)
            return nullptr;

        ListNode *s = head;
        ListNode *f = head;

        for (int i = 0; i < n; ++i)
            f = f->next;

        // when head needs to be deleted
        if (!f)
            return s->next;

        while (f->next)
        {
            s = s->next;
            f = f->next;
        }

        ListNode *delNode = s->next;
        s->next = s->next->next;
        delete delNode;

        return head;
    }
};