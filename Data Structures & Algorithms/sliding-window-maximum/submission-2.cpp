class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>> pq;
        vector<int> result((n-k+1));
        for (int i = 0; i<k; ++i) pq.push({nums[i], i});
        int i = 0; int j = k-1;
        while (!pq.empty() && j < n) {
            if (i <= pq.top().second && pq.top().second <= j) {
                result[i] = pq.top().first;
                i++;
                j++;
                if (j < n) pq.push({nums[j], j});
            }
            else pq.pop();
        }
        return result;
    }
};
