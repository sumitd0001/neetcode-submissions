class Solution {
    public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> result(n+1, 0);
        for (const auto& vec : trust) {
            result[vec[1]]++;
            result[vec[0]]--;
        }
        for (int i = 1; i<=n; ++i) {
            if (result[i] == n-1) return i;
        }
        return -1;
    }
};







































/*
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> res(n+1, 0);
        for (auto vec : trust) {
            res[vec[0]]--;
            res[vec[1]]++;
        }
        for (int i = 1; i<= n; ++i) if (res[i] == n-1)return i;
        return -1;
    }
};
*/