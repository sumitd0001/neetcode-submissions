class Solution {
public:

    void bt(const int& n, vector<string>& res, string current, int openC, int closeC) {
        if (current.length() == 2*n) {
            res.push_back(current);
            return;
        }

        if (openC < n) bt(n, res, current + "(", openC+1, closeC);
        if (closeC < openC) bt(n, res, current + ")", openC, closeC+1);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string current;
        bt(n, res, current, 0, 0);
        return res;
    }
};
