class Solution {
public:
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
};
