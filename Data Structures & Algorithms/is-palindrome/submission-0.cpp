class Solution {
public:

    bool compareLetters (const char& a, const char& b) {
        //cout<<"a : "<<a<<" b : "<<b<<"\n";
        if (tolower(a) == tolower(b)) return true;
        else return false;
    }

    bool isPalindrome(string s) {
        int l = 0, r = s.size()-1;

        while (l < r) {
            if (!isalnum(s[l])) ++l;
            else if (!isalnum(s[r])) --r;
            else {
                if (((s[l] >= 65 && s[l] <= 90) || (s[l] >= 97 && s[l] <= 122)) && ((s[r] >= 65 && s[r] <= 90) || (s[r] >= 97 && s[r] <= 122))) {
                    //cout<<"letter\n";
                    if (compareLetters(s[l], s[r])) {
                        ++l;
                        --r;
                    }
                    else return false;
                }
                else if ((s[l] >= 48 && s[l] <= 57) && (s[r] >= 48 && s[r] <= 57)) {
                        if (s[l] == s[r]) {
                            ++l;
                            --r;
                        }
                        else return false;
                }
                else return false;
            }
        }
        return true;
    }
};
