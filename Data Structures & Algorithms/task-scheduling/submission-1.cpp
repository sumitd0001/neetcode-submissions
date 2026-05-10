class Solution {
public:

    
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> vec(26, 0);
        for (int i = 0; i<tasks.size(); ++i) vec[tasks[i] - 'A']++;

        priority_queue<int> pq;
        for (auto x : vec) if (x) pq.push(x);

        queue<pair<int, int>> q;

        int time = 0;
        while (!pq.empty() || !q.empty()) {
            time++;
            while (!q.empty() && q.front().second <= time) {
                pq.push(q.front().first);
                q.pop();
            }

            if (!pq.empty()) {
                auto temp = pq.top();
                if (temp > 1) q.push({temp - 1, time + n + 1});
                pq.pop();
            }
        }
        return time;
    }

















    /*
    int leastInterval(vector<char>& tasks, int n) {
        int num = tasks.size();
        vector<int> count(26, 0);
        for (int i = 0; i<num; ++i) count[tasks[i] - 'A']++;

        priority_queue<int> maxHeap;
        for (int cnt : count) {
            if (cnt > 0) maxHeap.push(cnt);
        }

        int time = 0;
        queue<pair<int, int>> q;
        while (!maxHeap.empty() || !q.empty()) {
            time++;

            if (maxHeap.empty()) {
                time = q.front().second;
            }
            else {
                int cnt = maxHeap.top() - 1;
                maxHeap.pop();
                if (cnt > 0) q.push({cnt, time+n});
            }
            if (!q.empty() && q.front().second == time) {
                maxHeap.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
    */
};
