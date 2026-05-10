class Solution {
public:
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
};
