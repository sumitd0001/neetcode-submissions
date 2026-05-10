class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int sum = 0;
        int mx = 0;
        for (auto w : weights) {
            sum += w;
            mx = max(mx, w);
        }
        int l = mx, r = sum;
        int cap = sum;
        while (l <= r) {
            int mid = l + (r-l)/2;
            int curr_cap = 0;
            int total_days = 0;
            for (int i = 0; i<n; ++i) {
                curr_cap += weights[i];
                //cout<<"Inside mid : "<<mid<<" curr_cap : "<<curr_cap<<" total_days : "<<total_days<<" days : "<<days<<"\n";
                if (curr_cap > mid) {
                    total_days += 1;
                    i--;
                    curr_cap = 0;
                }
            }
            if (curr_cap <= mid)  total_days += 1;
            //cout<<"mid : "<<mid<<" curr_cap : "<<curr_cap<<" total_days : "<<total_days<<" days : "<<days<<"\n";
            if (total_days <= days) {
                cap = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return cap;
    }
};