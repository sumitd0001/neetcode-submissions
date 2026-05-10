class Solution {
public:
    int digitSum(int n) {
        int sum = 0;
        while (n) {
            int r = n%10;
            sum += r*r;
            n = n/10;
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> uset;

        while (n != 1) {
            int x = digitSum(n);
            if (uset.count(x)) return false;
            else uset.insert(x);
            n = x;
        }
        return true;
    }
};
