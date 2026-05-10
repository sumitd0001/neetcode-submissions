class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int t;
    KthLargest(int k, vector<int>& nums) : t(k) {
        for (auto& val : nums) 
            if (t > 0) {
                pq.push(val);
                t--;
            }
            else if (pq.top() < val) {
                pq.pop();
                pq.push(val);
            }
    }
    
    int add(int val) {
        int top;
        if (t > 0) {
            pq.push(val);
            top = pq.top();
            t--;
        }
        else {
            if (pq.top() < val) {
                pq.pop();
                pq.push(val);
                top = pq.top();
            }
            else top = pq.top();
        }
        return top;
    }
};
