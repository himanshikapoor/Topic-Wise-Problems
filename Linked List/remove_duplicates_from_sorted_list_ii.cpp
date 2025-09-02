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

        ListNode *temp = head;

        // dummy node is reqd when we want to del curr node
        ListNode *dummy = new ListNode();
        dummy->next = head;

        // a prev node is always required wherever we have to delete a node or we have to break links and create new links
        ListNode *previous_unique = dummy;

        while (temp)
        {
            if (temp && temp->next && temp->val == temp->next->val)
            {
                while (temp && temp->next && temp->val == temp->next->val)
                {
                    temp = temp->next;
                }

                previous_unique->next = temp->next;
            }
            else
                previous_unique = temp;

            temp = temp->next;
        }

        return dummy->next;
    }
};