class MinStack {
public:

    stack<pair<int, int>> st1;
    //stack<pair<int, int>> st2;

    MinStack() {
        
    }
    
    void push(int val) {
        if (st1.empty()) st1.push({val, val});
        else {
            int x = st1.top().second;
            x = min(val, x);
            st1.push({val, x});
        }
    }
    
    void pop() {
        st1.pop();
    }
    
    int top() {
        return st1.top().first;
    }
    
    int getMin() {
        return st1.top().second;
    }
};

/*
class MinStack {
public:

    stack<int> st1;
    stack<pair<int, int>> st2;

    MinStack() {
        
    }
    
    void push(int val) {
        st1.push(val);
        if (!st2.empty()) {
            if (st1.top() < st2.top().first) st2.push({val, 1});
            else if (st1.top() == st2.top().first) st2.top().second++;
        }
        else {
            st2.push({val, 1});
        }
    }
    
    void pop() {
        int x = st1.top();
        st1.pop();
        if (x == st2.top().first) st2.top().second--;
        if (st2.top().second == 0) st2.pop();
    }
    
    int top() {
        return st1.top();
    }
    
    int getMin() {
        return st2.top().first;
    }
};
*/
