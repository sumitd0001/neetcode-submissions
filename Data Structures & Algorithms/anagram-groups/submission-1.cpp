class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> result;
        unordered_map<string, vector<string>> umap;
        for (int i = 0; i<n; ++i) {
            string str = strs[i];
            sort(str.begin(), str.end());
            if (umap.find(str) != umap.end()) {
                umap[str].push_back(strs[i]);
            }
            else umap[str].push_back(strs[i]);
        }
        for (auto var : umap) {
            result.push_back(var.second);
        }
        return result;
    }
};
