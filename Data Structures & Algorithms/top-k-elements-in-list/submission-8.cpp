class Solution {
public:
    

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        int maxf = 0;
        for (const auto& x : nums) {
            umap[x]++;
            maxf = max(maxf, umap[x]);
        }

        vector<vector<int>> freq(maxf+1);

        for (const auto& [key, val] : umap) {
            freq[val].push_back(key);
        }
        vector<int> res;
        res.resize(k);
        int j = 0;
        for (int i = maxf; i>0 && j < k; --i) {
                for (auto& x : freq[i]) {
                    res[j++] = x;
                    if (j == k) return res; 
                }
        }
        return res;
    }















    //using bucket sort as well
    // TC : O(N), SC : O(N)
    /*
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        
        for (auto& x : nums) count[x]++;

        vector<vector<int>> freq(nums.size() + 1);

        for (const auto& [key, val] : count) freq[val].push_back(key);

        vector<int> res; res.reserve(k);
        
        int j = 0;

        for (int i = freq.size()-1; i>0 && j < k; --i)
            for (const auto& x : freq[i]) {res.emplace_back(x); ++j; if (j == k) return res;}

        return res;
    }*/










    /*
    //TC : O(nlogk), SC : O(n+k)
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int, int> umap;
        for (auto& x : nums) umap[x]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto& [key , val] : umap) {
            pq.push({val, key});
            if (pq.size() > k) pq.pop();
        }

        vector<int> result(k);
        for (int i = 0; i<k; ++i) {
            result[i] = pq.top().second;
            pq.pop();
        }
        return result;
    }
    */
    
    
    /*
    bool static comp(const pair<int, int> &a , const pair<int, int> &b) {
        if (a.first >= b.first) return true;
        else return false;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        for (auto x : nums) {
            umap[x]++;
        }
        vector<pair<int, int>> resultpair;

        for (auto p : umap) {
            resultpair.push_back({p.second, p.first});
        }
        sort(resultpair.begin(), resultpair.end(), comp);
        
        vector<int> result(k);
        
        for (int i = 0; i<k; ++i) {
            result[i] = resultpair[i].second;
        }
        return result;
    }
    */
};
