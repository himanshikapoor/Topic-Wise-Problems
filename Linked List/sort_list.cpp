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
    ListNode *findMiddle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode *mergeSortedList(ListNode *l1, ListNode *l2)
    {
        ListNode *mergedList = new ListNode();
        ListNode *temp = mergedList;

        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                temp->next = l1;
                l1 = l1->next;
            }
            else
            {
                temp->next = l2;
                l2 = l2->next;
            }

            temp = temp->next;
        }

        if (l1)
            temp->next = l1;

        if (l2)
            temp->next = l2;

        return mergedList->next;
    }

    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode *leftHead = head;
        ListNode *middle = findMiddle(head);

        ListNode *rightHead = middle->next;
        middle->next = nullptr;

        leftHead = sortList(leftHead);
        rightHead = sortList(rightHead);

        return mergeSortedList(leftHead, rightHead);
    }
};