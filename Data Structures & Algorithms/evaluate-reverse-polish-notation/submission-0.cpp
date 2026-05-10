class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> st;
        for (int i = 0; i<n; ++i) {
            if (tokens[i] == "+") {
                int x1 = st.top();
                st.pop();
                int x2 = st.top();
                st.pop();
                st.push(x1 + x2);
            }
            else if (tokens[i] == "*") {
                int x1 = st.top();
                st.pop();
                int x2 = st.top();
                st.pop();
                st.push(x1*x2);
            }
            else if (tokens[i] == "-") {
                int x1 = st.top();
                st.pop();
                int x2 = st.top();
                st.pop();
                st.push(x2-x1);
            }
            else if (tokens[i] == "/") {
                int x1 = st.top();
                st.pop();
                int x2 = st.top();
                st.pop();
                st.push(x2/x1);
            }
            else {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
