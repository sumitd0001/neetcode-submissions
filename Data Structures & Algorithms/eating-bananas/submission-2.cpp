class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int mx = 0;
        for (auto x : piles) 
            mx = max(mx, x);
            
        int l = 1, r = mx;
        int k = 0;
        while (l <= r) {
            int mid = l + (r-l)/2;
            long long curr_h = 0;

            for (auto x : piles)
                curr_h += ceil((double) x / mid);

            if (curr_h <= h) {
                k = mid;
                r = mid-1;
            }
            else l = mid+1;
            
        }
        return k;
    }
};
