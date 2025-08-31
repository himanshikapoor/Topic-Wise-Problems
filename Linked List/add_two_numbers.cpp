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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode();
        ListNode *temp = dummy;

        ListNode *t1 = l1;
        ListNode *t2 = l2;

        int carry = 0;

        while (t1 || t2 || carry)
        {
            int res = carry;

            if (t1)
            {
                res += t1->val;
                t1 = t1->next;
            }

            if (t2)
            {
                res += t2->val;
                t2 = t2->next;
            }

            carry = res / 10;
            res = res % 10;

            temp->next = new ListNode(res);
            temp = temp->next;
        }

        temp = dummy->next; // remember this to avoid memory leak
        delete dummy;
        return temp;
    }
};
