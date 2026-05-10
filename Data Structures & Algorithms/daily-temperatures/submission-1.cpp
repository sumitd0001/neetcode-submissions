class Solution {
public:
    
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<pair<int, int>> st;
        st.push({temperatures[n-1],n-1});
        vector<int> result(n);
        result[n-1] = 0;
        for (int i = n-2; i >= 0; --i) {
            while (!st.empty()) {
                if (st.top().first > temperatures[i]) {
                    result[i] = st.top().second - i;
                    st.push({temperatures[i], i});
                    break;
                }
                else {
                    st.pop();
                }
            }
            if (st.empty()) {
                result[i] = 0;
                st.push({temperatures[i], i});
            }
        }
        return result;
    }
};
