class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        vector<vector<int>> result(k, vector<int>(2));
        priority_queue<pair<double, int>> pq;
        double dist;
        int t = k;
        int x, y;
        for (int i = 0; i<n; ++i) {
            x = points[i][0];
            y = points[i][1];
            dist = sqrt(pow((x-0), 2) + pow((y-0), 2));
            if (t > 0) {
                pq.push({dist, i});
                t--;
            }
            else {
                if (pq.top().first > dist) {
                    pq.pop();
                    pq.push({dist, i});
                }
            }
        }
        int i = 0;
        while (!pq.empty()) {
            result[i] = {points[pq.top().second][0], points[pq.top().second][1]};
            pq.pop();
            i++;
        }
        return result;
    }
};
