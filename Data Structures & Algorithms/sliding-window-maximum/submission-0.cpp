class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>> pq;
        vector<int> result((n-k+1));
        for (int i = 0; i<k; ++i) pq.push({nums[i], i});
        
        queue<pair<int, int>> q;
        int i = 0; int j = k-1;
        while (!pq.empty() && j < n) {
            result[i] = (pq.top().first);
            i++;
            j++;
            while (!pq.empty()) {
                if (pq.top().second < i) {
                    pq.pop();
                    break;
                }
                else {
                    q.push(pq.top());
                    pq.pop();
                }
            }
            while (!q.empty()) {
                pq.push(q.front());
                q.pop();
            }
            if (j < n)
                pq.push({nums[j], j});
        }
        return result;
    }
};
