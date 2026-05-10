class Solution {
public:
    int scoreOfString(string s) {
        int l = s.size();
        int diff = 0;
        for (int i = 0; i<l-1; ++i) {
            diff += abs(s[i] - s[i+1]);
        }
        return diff;
    }
};