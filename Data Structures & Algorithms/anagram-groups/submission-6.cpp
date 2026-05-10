class Solution {
public:

    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> umap;
        for (const auto& str : strs) {
            string temp;
            int arr[26] = {};
            for (const auto& x : str) arr[x - 'a']++;
            for (int i = 0; i<26; ++i) {
                if (arr[i]) {
                    temp += (char)('a' + i);
                    temp += to_string(arr[i]);
                    //temp += ',';
                }
            }
            cout<<temp<<"\n";
            umap[temp].push_back(str);
        }
        vector<vector<string>> res;
        res.reserve(umap.size());
        for (const auto& [k ,v] : umap) res.emplace_back(std::move(v));
        return res;
    }






































    /*
    //TC : O(N*M), SC : O(N*M)
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.size() == 0) return {};
        unordered_map<string, vector<string>> umap;

        for (auto& str : strs) {
            vector<int> vec(26, 0);
            for (auto& c : str) vec[c - 'a']++;
            string temp;
            for (int i = 0; i<26; ++i) if (vec[i]) {
                temp += (char)(i + 'a');
                temp += to_string(vec[i]);
            }
            umap[temp].emplace_back(str);
        }
        vector<vector<string>> result;
        result.reserve(umap.size());
        for (const auto& [k, v] : umap) result.emplace_back(std::move(v));
        return result;
    }
    */

    /*
    //TC : O(N*Mlogm), SC : O(N*M)
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (!strs.size()) return {};
        unordered_map<string, vector<string>> umap;
        
        for (auto str : strs) {
            string temp{str};
            sort(temp.begin(), temp.end());
            umap[temp].push_back(str);
        }
        vector<vector<string>> result;
        result.reserve(umap.size());
        for (const auto& [k , v] : umap) result.emplace_back(v);
        return result;
    }
    */

    /*
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
    */
};
