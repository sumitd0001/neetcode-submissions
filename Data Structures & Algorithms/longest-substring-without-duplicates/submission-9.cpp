class Solution {
public:
    
    //instead of unordered_map, using vector
    int lengthOfLongestSubstring(string s) {
        vector<int> vec(128, -1);
        int n = s.size();
        int maxsize = 0;
        int l = 0;
        for (int r = 0; r < n; ++r) {
            if (vec[s[r]] > -1) l = max(l, vec[s[r]] + 1);
            vec[s[r]] = r;
            maxsize = max(maxsize, r-l+1);
        }
        return maxsize;
    }


    //usign unordered_map
    /*
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> umap;
        int maxsize = 0;
        int l = 0;
        for (int r = 0; r < n; ++r) {
            if (umap.find(s[r]) != umap.end()) l = max(l, umap[s[r]]+1);
            umap[s[r]] = r;
            maxsize = max(maxsize, r-l+1);
        }
        return maxsize;
    }
    */

    //This works, but it is slow, as you are erasing things
    /*
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> uset;
        size_t maxsize = 0;
        int l = 0;
        for (const char& c : s) {
            if (uset.count(c)) {
                while(s[l] != c) {
                    uset.erase(s[l]);
                    l++;
                }
                uset.erase(s[l]); l++;
            }
            uset.insert(c);
            maxsize = max(maxsize, uset.size());
        }
        return maxsize;
    }
    */

    /*
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
    */
    
};
