class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int t;
    KthLargest(int k, vector<int>& nums) : t(k) {
        for (auto& val : nums) 
            if (t > 0) {
                //cout<<"val : "<<val<<" pq.top() : "<<pq.top()<<"\n";
                pq.push(val);
                t--;
            }
            else if (pq.top() < val) {
                //cout<<" ctor val : "<<val<<" pq.top() : "<<pq.top()<<"\n";
                pq.pop();
                pq.push(val);
                //cout<<" ctor val : "<<val<<" pq.top() : "<<pq.top()<<"\n";
            }
    }
    
    int add(int val) {
        int top;
        if (t > 0) {
            //cout<<"if val : "<<val<<" pq.top() : "<<pq.top()<<"\n";
            pq.push(val);
            top = pq.top();
            t--;
        }
        else {
            if (pq.top() < val) {
                //cout<<" else if val : "<<val<<" pq.top() : "<<pq.top()<<"\n";
                pq.pop();
                pq.push(val);
                top = pq.top();
            }
            else top = pq.top();
        }
        return top;
    }
};
