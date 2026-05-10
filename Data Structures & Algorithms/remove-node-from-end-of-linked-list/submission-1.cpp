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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* left = new ListNode(-1, head);
        ListNode* slow = left;
        ListNode* fast = head;
        while (n-- && fast) {
            fast = fast->next;
        }
        while (fast ) {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return left->next;
    }
};
