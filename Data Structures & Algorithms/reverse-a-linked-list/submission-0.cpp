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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        
        ListNode* next = nullptr;

        if (head) next = head->next;
        else return head;

        while (next) {
            head->next = prev;
            prev = head;
            head = next;
            next = next->next;
        }
        head->next = prev;
        return head;
    }
};
