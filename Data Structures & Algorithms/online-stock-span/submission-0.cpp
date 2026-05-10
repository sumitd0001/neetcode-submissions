class StockSpanner {
public:
    stack<int> st1;
    stack<int> st2;

    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1;
        if (!st1.empty()) {
            while (!st1.empty() && st1.top() <= price) {
                st2.push(st1.top());
                st1.pop();
                span++;
            }
            while (!st2.empty()) {
                st1.push(st2.top());
                st2.pop();
            }
            st1.push(price);
        }
        else st1.push(price);
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */