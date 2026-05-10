class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int> pq(stones.begin(), stones.end());
        int x, y;
        int sw = 0;
        while(pq.size() > 1) {
            x = pq.top();
            pq.pop();
            y = pq.top();
            pq.pop();
            sw = abs(x - y);
            pq.push(sw);
        }
        return pq.top();

    }
};
