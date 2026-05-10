class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0, r = s.size()-1;
        bool flag = false;
        while (l < r) {
            if (s[l] == s[r]) {
                ++l;
                --r;
            }
            else {
                if (!flag) {
                    if (s[l] == s[r-1] || s[l+1] == s[r]) {
                        if (l == r-1 || l+1 == r) return true;
                        if (s[l] == s[r-1]) {
                            if (l+1 > r-2) return true;
                            else if ((l+1 <= r-2) && s[l+1] == s[r-2]) {
                                l++;
                                r -= 2;
                                flag = true;
                            }
                        }
                        if (!flag && s[l+1] == s[r]) {
                            if (l+2 > r-1) return true;
                            if (((l+2) <= r-1) && s[l+2] == s[r-1]) {
                                l += 2;
                                r--;
                                flag = true;
                            }
                        }
                        if (!flag) return false;
                    }
                    else return false;
                }
                else return false;
            }
        }
        return true;
    }
};