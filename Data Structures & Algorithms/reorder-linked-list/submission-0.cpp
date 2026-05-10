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
    void reorderList(ListNode* head) {
        vector<ListNode*> result;
        ListNode* curr = head;
        while (curr) {
            result.push_back(curr);
            curr = curr->next;
        }
        int i = 0, j = result.size()-1;
        ListNode* left;
        ListNode* right;
        while (i < j) {
            result[i]->next = result[j];
            i++;
            if (i >= j) break;
            result[j]->next = result[i];
            j--;
        }
        result[i]->next = nullptr;
    }
};
