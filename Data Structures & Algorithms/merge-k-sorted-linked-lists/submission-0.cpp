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
struct compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val; // Min-heap: smaller values have higher priority
    }
};

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        for (auto node : lists) if (node) pq.push(node);

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while (!pq.empty()) {
            ListNode* s = pq.top();
            pq.pop();

            curr->next = s;
            curr = s;

            if (curr->next) pq.push(curr->next);
        }
        return dummy->next;
    }
};
