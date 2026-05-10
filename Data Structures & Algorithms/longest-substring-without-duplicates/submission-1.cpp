class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_set<char> charset;
        int l = 0;
        int r = 0;
        int maxl = 0;
        while (r < n) {
            if (charset.find(s[r]) != charset.end()) {
                while (s[l] != s[r]) {
                    charset.erase(s[l]);
                    ++l;
                }
                if (s[l] == s[r]) {
                    charset.erase(s[l]);
                    ++l;
                }
                charset.insert(s[r]);
                r++;
            }
            else {
                charset.insert(s[r]);
                r++;
            }
            if (maxl < charset.size()) maxl = charset.size();
            //if (maxl < (r - l)) maxl = (r-l);
        }
        return maxl;
    }
};
