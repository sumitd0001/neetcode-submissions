class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> result;
        for (int i = 0; i<n; ++i) {
            string str = strs[i];
            sort(str.begin(), str.end());
            bool flag = false;
            for (int j = 0; j<result.size(); ++j) {
                string temp = result[j][0];
                sort(temp.begin(), temp.end());
                if (str == temp) {
                    result[j].push_back(strs[i]);
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                result.push_back({strs[i]});
            }
        }
        return result;
    }
};
