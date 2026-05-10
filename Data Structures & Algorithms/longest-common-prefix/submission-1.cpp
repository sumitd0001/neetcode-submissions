class Solution {
public:
    
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int l1 = strs[0].size();
        string str;
        for (int i = 0; i<l1; ++i) {
            for (int j = 1; j<n; ++j) { if (strs[j][i] != strs[0][i]) return str; }
            str += strs[0][i];
        }
        return str;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    /*
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int l = strs[0].size();
        string str;
        for (int i = 0; i<l; ++i) {
            for (int j = 1; j<n; ++j) {
                if (strs[j][i] == '\0') return str;
                else if (strs[j-1][i] == strs[j][i]) continue;
                else return str;
            }
            str += strs[0][i];
        }
        return str;
    }
    */
};