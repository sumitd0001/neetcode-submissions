class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> time(position.size(), {0, 0});
        
        for (int i = 0; i<n; ++i) time[i] = {position[i], (static_cast<double>(target-position[i])/speed[i])};

        sort(time.begin(), time.end(), greater<pair<int, double>>());

        stack<double> st;

        for (int i = 0; i<n; ++i) {
            if (!st.empty()) {
                if (st.top() < time[i].second) st.push(time[i].second);
            }
            else st.push(time[i].second);
        }
        return st.size();
    }
};
