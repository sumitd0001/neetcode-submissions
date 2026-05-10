class Solution {
public:
    bool isAnagram(string s, string t) {
        int l1 = s.length();
        int l2 = t.length();
        if (l1 != l2) return false;
        unordered_map<char, int> umap;

        for (int i = 0; i<l1; ++i) {
            umap[s[i]]++;
        }
        for (int i = 0; i<l2; ++i) {
            if (umap.find(t[i]) != umap.end()) {
                if (umap[t[i]] == 0) return false;
                else umap[t[i]]--;
            }
        }
        for (auto var : umap) {
            if (var.second != 0) return false;
        }
        return true;
    }
};
