class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
        st.push(asteroids[0]);
        int i = 1;
        while (i < n) {
            int size = asteroids[i];
            bool collision = 1;
            while (!st.empty() && collision) {
                int x = st.top();
                /*
                if (size > 0 && x < 0) {
                    if (abs(size) > abs(x)) {
                        st.pop();
                        //st.push(size);
                    }
                    else if (abs(size) == abs(x)) {
                        st.pop();
                        collision = 0;
                    }
                    else collision = 0;
                }
                */
                //else 
                if (size < 0 && x > 0) {
                    if (abs(size) > abs(x)) {
                        st.pop();
                    }
                    else if (abs(size) == abs(x)) {
                        st.pop();
                        collision = 0;
                    }
                    else collision = 0;
                }
                else {
                    st.push(size);
                    collision = 0;
                }
            }
            if (collision && st.empty()) st.push(size);
            i++;
        }
        vector<int> res;
        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        if (res.size() > 1) reverse(res.begin(), res.end());
        return res;
    }
};