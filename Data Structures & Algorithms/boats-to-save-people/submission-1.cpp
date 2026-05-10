class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(), people.end());

        int l = 0, r = n-1;
        int num = 0;
        while (l <= r) {
            if (people[r] == limit) {
                r--;
                num++;
            }
            else {
                if (people[r] + people[l] <= limit) {
                    r--;
                    l++;
                    num++;
                }
                else {
                    r--;
                    num++;
                }
            }
        }
        return num;
    }
};