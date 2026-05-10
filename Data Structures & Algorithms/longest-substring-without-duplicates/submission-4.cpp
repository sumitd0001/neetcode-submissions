class Solution {
public:
    
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charset;
        int n = s.size();
        int l = 0, maxl = 0, r = 0;
    
        while (r < n) {
            // While we have a duplicate, shrink from the left
            while (charset.find(s[r]) != charset.end()) {
                charset.erase(s[l]);
                l++;
            }
            charset.insert(s[r]);
            maxl = max(maxl, r - l + 1);
            r++;
        }
        return maxl;
    }
    
};
