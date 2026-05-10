class Solution {
public:
    int calPoints(vector<string>& operations) {
        int n = operations.size();
        stack<int> st;

        for (int i = 0; i<n; ++i) {
            if (operations[i] == "+") {
                int x1 = st.top();
                st.pop();
                int x2 = st.top();
                st.push(x1);
                st.push(x1 + x2);
            }
            else if (operations[i] == "D") {
                st.push(2*st.top());
            }
            else if (operations[i] == "C") {
                st.pop();
            }
            else {
                st.push(stoi(operations[i]));
            }
        }
        int total = 0;
        while (!st.empty()) {
            total += st.top();
            st.pop();
        }
        return total;
    }
};