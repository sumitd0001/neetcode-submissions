class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if (n&1) return false;
        stack<char> st;
        unordered_map<char, char> umap = {
            {')' , '('},
            {']' , '['},
            {'}' , '{'}
        };

        for (char c : s) {
            if (umap.count(c)) {
                if (!st.empty()) {
                    if (st.top() == umap[c]) st.pop();
                    else return false;
                }
                else return false;
            }
            else {
                st.push(c);
            }
        }
        return st.empty();
    }
    /*
    bool isValid(string s) {
        int n = s.size();
        if (n&1) return false;
        stack<char> st;
        for (int i = 0; i<n; ++i) {
            if (s[i] == '{' || s[i] == '(' || s[i] == '[') {
                st.push(s[i]);
            }
            else {
                if (!st.empty()) {
                    if (s[i] == ')') {
                        if (st.top() == '(') st.pop();
                        else return false;
                    }
                    else if (s[i] == ']') {
                        if (st.top() == '[') st.pop();
                        else return false;
                    }
                    else {
                        if (st.top() == '{') st.pop();
                        else return false;
                    }
                }
                else return false;
            }
        }
        if (st.empty()) return true;
        return false;
    }
    */
};
