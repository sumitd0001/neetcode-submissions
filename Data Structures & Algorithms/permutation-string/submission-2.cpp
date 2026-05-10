class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        vector<int> s1count(26, 0);
        vector<int> s2count(26, 0);

        for (int i = 0; i<n; ++i) {
            s1count[s1[i] - 'a']++;
            s2count[s2[i] - 'a']++;
        }
        int matches = 0;
        for (int i = 0; i<26; ++i) {
            if (s1count[i] == s2count[i]) matches++;
        }
        //if (matches == 26) return true;
        int l = 0;
        for (int r = n; r<m; ++r) {
            if (matches == 26) return true;
            
            int i = s2[r] - 'a';
            s2count[i]++;
            if (s2count[i] == s1count[i]) matches++;
            else if (s2count[i] == s1count[i] + 1) matches--;

            i = s2[l] - 'a';
            s2count[i]--;
            if (s2count[i] == s1count[i]) matches++;
            else if (s2count[i] == s1count[i] - 1) matches--;
            l++;
         }
         return matches == 26;
    }
};
