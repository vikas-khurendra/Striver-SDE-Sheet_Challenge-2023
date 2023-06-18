
*******************************  LeetCode *************************************

// Problem :

Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

// Input and Output :

Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]

Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]

// Code :

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (head == NULL || k == 1)
        {
            return head;
        }

        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *prevGroupTail = dummy;
        ListNode *currGroupHead = head;

        // count length of LL

        int len = 0;
        ListNode *temp = head;
        while (temp)
        {
            len++;
            temp = temp->next;
        }

        while (len >= k)
        {
            ListNode *cur = currGroupHead;
            ListNode *pre = NULL;
            ListNode *nex = NULL;

            for (int i = 0; i < k; i++)
            {
                nex = cur->next;
                cur->next = pre;
                pre = cur;
                cur = nex;
            }

            prevGroupTail->next = pre;
            prevGroupTail = currGroupHead;
            currGroupHead = cur;
            len = len - k;
        }

        prevGroupTail->next = currGroupHead;
        ListNode *newHead = dummy->next;
        delete dummy;

        return newHead;
    }
};