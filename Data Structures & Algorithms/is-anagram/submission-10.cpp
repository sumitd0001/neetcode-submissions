class Solution {
public:
    

    bool isAnagram(string s, string t) {
        vector<int> res(26, 0);
        int l1 = s.length();
        int l2 = t.length();

        if (l1 != l2) return false;

        for (int i = 0; i<l1; ++i) {
            res[s[i]-'a']++;
            res[t[i]-'a']--;
        }

        for (const auto& x : res) {
            if (x) return false;
        }
        return true;
    }





































    /*
    bool isAnagram(string s, string t) {
        int l1 = s.size();
        int l2 = t.size();
        if (l1 != l2) return false;

        //goes into heap, little overhead
        //int* arr = new int[26];
        //for(int i = 0; i<26; ++i) arr[i] = 0;
        //this is also heap
        //vector<int> res(26, 0);

        //goes into stack, no overhead, if know the size use it always, 
        //do not try to be smart and allocate memory dynamically evertime
        int arr[26] = {};
        //this is stack
        //std::array<int, 26> arr{0};

        for (int i = 0; i<l1; ++i) {
            arr[s[i] - 'a']++;
            arr[t[i] - 'a']--;
        }
        //for (int i = 0; i<26; ++i) if(arr[i] != 0) return false;
        for (auto& x : arr) if(x) return false;
        return true;

    }
    */































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
