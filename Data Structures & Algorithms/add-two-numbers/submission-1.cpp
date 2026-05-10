/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n1 = 0, n2 = 0;
        int m = 1;
        ListNode* curr = l1;
        while (curr) {
            n1 += (curr->val)*m;
            m = m*10;
            curr = curr->next;
        }
        if (n1 == 0) return l2;
        //cout<<"n1 : "<<n1<<"\n";
        curr = l2;
        m = 1;
        while (curr) {
            n2 += (curr->val)*m;
            m = m*10;
            curr = curr->next;
        }
        //cout<<"n2 : "<<n2<<"\n";
        if (n2 == 0) return l1;
        n1 += n2;
        ListNode* head = nullptr;
        ListNode* prev = nullptr;
        while (n1) {
            int rem = n1%10;
            ListNode* newnode = new ListNode(rem);
            if (!head) head = newnode;
            if (!prev) prev = newnode;
            else {
                prev->next = newnode;
                prev = newnode;
            }
            n1 = n1/10;
        }
        return head;
    }
};
