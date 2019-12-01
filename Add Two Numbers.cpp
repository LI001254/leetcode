/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = NULL, *pre = NULL;
        int remain = 0;
        while (l1 || l2)
        {
            int x1 = l1 ? l1->val : 0;
            int x2 = l2 ? l2->val : 0;
            int x = (x1 + x2 + remain) % 10;
            remain = x1 + x2 + remain >= 10 ? 1 : 0;
            ListNode *newNode = new ListNode(x);
            if (!head)
                head = newNode;
            if (pre)
                pre->next = newNode;
            pre = newNode;
            pre->next = NULL;
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
        }
        if (remain)
        {
            ListNode *newNode = new ListNode(remain);
            pre->next = newNode;
        }
        return head;
    }
};
