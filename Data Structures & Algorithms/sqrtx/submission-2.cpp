class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        long l = 1, r = x;
        while (l <= r) {
            long mid = l + (r-l)/2;
            long long sqr = mid*mid;
            if (sqr == x) return mid;
            else if (sqr > x) r = mid-1;
            else l = mid+1;
        }
        if (l*l > x) return l-1;
        return l;
    }
};