class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int t = k;
        for (auto& x : nums) {
            if (t > 0) {
                pq.push(x);
                t--;
            }
            else {
                if (pq.top() < x) {
                    pq.pop();
                    pq.push(x);
                }
            }
        }
        return pq.top();
    }
};
