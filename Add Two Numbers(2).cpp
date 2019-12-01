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
        ListNode *head = new ListNode(0);
        ListNode *pre = head;
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        if ((!l1) && (!l2))
            return NULL;
        int remain = 0;
        while (p1 && p2)
        {
            int x = remain + p1->val + p2->val;
            remain = x >= 10 ? 1 : 0;
            ListNode *newNode = new ListNode(x % 10);
            pre->next = newNode;
            pre = newNode;
            p1 = p1->next;
            p2 = p2->next;
        }
        while (p2)
        {
            int x = remain + p2->val;
            remain = x >= 10 ? 1 : 0;
            ListNode *newNode = new ListNode(x % 10);
            pre->next = newNode;
            pre = newNode;
            p2 = p2->next;
        }
        while (p1)
        {
            int x = remain + p1->val;
            remain = x >= 10 ? 1 : 0;
            ListNode *newNode = new ListNode(x % 10);
            pre->next = newNode;
            pre = newNode;
            p1 = p1->next;
        }
        if (remain)
        {
            ListNode *newNode = new ListNode(remain);
            pre->next = newNode;
        }
        return head->next;
    }
};