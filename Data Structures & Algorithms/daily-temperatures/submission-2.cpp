class Solution {
public:
    
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        st.push(n-1);
        vector<int> result(n);
        result[n-1] = 0;
        for (int i = n-2; i >= 0; --i) {
            while (!st.empty()) {
                if (temperatures[st.top()] > temperatures[i]) {
                    result[i] = st.top() - i;
                    st.push(i);
                    break;
                }
                else {
                    st.pop();
                }
            }
            if (st.empty()) {
                result[i] = 0;
                st.push(i);
            }
        }
        return result;
    }
};
