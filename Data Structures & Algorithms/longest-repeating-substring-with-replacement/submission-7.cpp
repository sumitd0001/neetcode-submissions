class Solution {
public:
    
    int characterReplacement(string s, int k) {
        int n = s.size();
        unordered_set<char> charset;
        int res = 0;
        for (auto c : s)
            charset.insert(c);
        
        for (auto c : charset) {
            int l = 0, r = 0, count = 0;
            while (r < n) {
                if (s[r] == c) count++;
                while ((r-l+1) - count > k) {
                    if (s[l] == c) count--;
                    ++l;
                }
                res = max(res, r-l+1);
                ++r;
            }
        }
        return res;
     }
    



















    
    /*
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0, r = 0;
        int mx = 0;
        int maxfrequecy = 0;
        
        unordered_map<char, int> count;
        while (r < n) {
            count[s[r]]++;
            maxfrequecy = max(maxfrequecy, count[s[r]]);

            while ((r-l+1) - maxfrequecy > k) {
                count[s[l]]--;
                l++;
            }
            mx = max(mx, r-l+1);
            r++;
        }
        return mx;
    }
    */
};
