#include <bits/stdc++.h>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode *curr = head;

        while (curr && curr->next)
        {
            if (curr->val == curr->next->val)
            {
                ListNode *delNode = curr->next;
                curr->next = curr->next->next;
                delete delNode;
            }
            else
            {
                // move pointer to next only when two adj nodes are not duplicate
                curr = curr->next;
            }
        }

        return head;
    }
};