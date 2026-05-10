class Solution {
public:
    
    bool isAnagram(string s, string t) {
        int l1 = s.size();
        int l2 = t.size();
        if (l1 != l2) return false;

        int* arr = new int[26];
        for(int i = 0; i<26; ++i) arr[i] = 0;

        for (int i = 0; i<l1; ++i) {
            arr[s[i] - 'a']++;
            arr[t[i] - 'a']--;
        }
        for (int i = 0; i<26; ++i) if(arr[i] != 0) return false;
        return true;

    }































    /*
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
    */
};
