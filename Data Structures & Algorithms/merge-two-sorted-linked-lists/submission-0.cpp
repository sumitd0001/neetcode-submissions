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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head;
        ListNode* curr1;
        ListNode* curr2;
        if (!list1) return list2;
        if (!list2) return list1;

        if (list1->val < list2->val) {
            head = list1;
            curr1 = head->next;
            curr2 = list2;
            }
        else {
            head = list2;
            curr2 = head->next;
            curr1 = list1;
        }
        ListNode* prev = head;
        while (curr1 && curr2) {
            if (curr1->val < curr2->val) {
                prev->next = curr1;
                prev = curr1;
                curr1 = curr1->next;
            }
            else {
                prev->next = curr2;
                prev = curr2;
                curr2 = curr2->next;
            }
        }
        if (curr1 && !curr2) prev->next = curr1;
        if (curr2 && !curr1) prev->next = curr2;
        return head;
    }
};  
