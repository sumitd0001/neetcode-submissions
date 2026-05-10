class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int l1 = word1.size(), l2 = word2.size();
        int i = 0, j = 0;
        string str;
        while ((i < l1) && (j < l2)) {
            str += word1[i++]; 
            str += word2[j++];
        }
        while (i < l1) {
            str += word1[i++];
        }
        while (j < l2) {
            str += word2[j++];
        }
        return str;
    }
};