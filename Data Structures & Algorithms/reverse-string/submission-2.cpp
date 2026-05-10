class Solution {
public:

    //If you are working in a system (like HFT or Big Data) 
    //where a "string" (or a buffer) could be larger than 2.1 GB, 
    //s.size() will exceed the capacity of a signed int.
    //The Pro Move: Use size_t or auto.
    void reverseString(vector<char>& s) {
        size_t i = 0, r = s.size()-1;
        while (i < r) swap(s[i++], s[r--]);
    }

    /*
    void reverseString(vector<char>& s) {
        std::reverse(s.begin(), s.end());
    }
    */

    /*
    void reverseString(vector<char>& s) {
        int i = 0, r = s.size()-1;
        while (i < r) swap(s[i++], s[r--]);
    }
    */
};