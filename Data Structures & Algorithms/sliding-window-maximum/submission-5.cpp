class Solution {
public:

    //solve it using deque, O(N)
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int r = 0;
        int n = nums.size();
        deque<int> dq;
        vector<int> res;
        while (r < n) {
            while (!dq.empty() && dq.front() <= r - k) dq.pop_front();
            while (!dq.empty() && nums[dq.back()] < nums[r]) dq.pop_back();
            dq.push_back(r);
            if (r >= k-1) res.push_back(nums[dq.front()]);
            r++;
        }
        return res;
    }

    /*
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>> pq;
        vector<int> res(n-k+1);
        int l = 0, r = 0;
        while (r < k) {
            pq.push({nums[r], r});
            r++;
        }
        r--;
        while (r < n) {
            if (l <= pq.top().second && r >= pq.top().second) {
                res[l] = pq.top().first;
                l++;
                r++;
                pq.push({nums[r], r});
            }
            else pq.pop();
        }
        return res;
    }
    */

    //O(nlogn)
    /*
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
    */
};
