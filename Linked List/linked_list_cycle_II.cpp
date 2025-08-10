// Starting Point of Node - Tortoise Hare Algorithm
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
    ListNode *findStartNode(ListNode *head, ListNode *intersection)
    {
        ListNode *mover = head;

        while (mover != intersection)
        {
            mover = mover->next;
            intersection = intersection->next;
        }

        return mover;
    }

    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                return findStartNode(head, slow);
            }
        }

        return NULL;
    }
};