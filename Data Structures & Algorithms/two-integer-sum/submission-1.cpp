class Solution {
public:
    
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> umap;

        for (int i = 0; i<n; ++i) {
            int x = target-nums[i];
            if (umap.find(x) != umap.end()) return {umap[x], i};
            umap[nums[i]] = i;
        }
        return {};
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    /*
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> umap;
        for (int i = 0; i<n; ++i) {
            if (umap.find(target - nums[i]) != umap.end()) {
                return {umap[target-nums[i]], i};
            }
            umap.insert({nums[i], i});
        }
        return {};
    }
    */
};
