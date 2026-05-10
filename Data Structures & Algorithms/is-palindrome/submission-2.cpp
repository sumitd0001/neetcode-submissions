class Solution {
public:

    bool isPalindrome(string s) {
        int l = 0, r = s.size()-1;
        while (l < r) {
            if (!isalnum(s[l])) {
                l++;
                continue;
            }
            if (!isalnum(s[r])) {
                r--;
                continue;
            }
            if (tolower(s[l]) == tolower(s[r])) {
                l++;
                r--;
            }
            else return false;
        }
        return true;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    /*
    bool compareLetters (const char& a, const char& b) {
        if (tolower(a) == tolower(b)) return true;
        else return false;
    }

    bool isPalindrome(string s) {
        int l = 0, r = s.size()-1;

        while (l < r) {
            if (!isalnum(s[l])) ++l;
            else if (!isalnum(s[r])) --r;
            else {
                if (compareLetters(s[l], s[r])) {
                    ++l;
                    --r;
                }
                else return false;
            }
        }
        return true;
    }
    */
};
