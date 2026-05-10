class Solution {
public:
    bool isAnagram(string s, string t) {
        int l1 = s.length();
        int l2 = t.length();
        if (l1 != l2) return false;
        if (s == t) return true;
        unordered_map<char, int> umap;

        for (int i = 0; i<l1; ++i) {
            umap[s[i]]++;
            umap[t[i]]--;
        }
        for (auto var : umap) {
            if (var.second != 0) return false;
        }
        return true;
    }
};
