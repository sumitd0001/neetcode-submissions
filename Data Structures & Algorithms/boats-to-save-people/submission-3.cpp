class Solution {
public:
    
    /*
    Sort it : to get the maximum
        if maximum is greater than limit, can not send everyone
        take right and left , as at most 2 people are allowed
    if rightmost == limit , only 1 can go
    else
        if rightmost + leftmost <= limit, send both
        else if rightmost + leftmost > limit, send rightmost only
    */

    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int n = people.size();

        int l = 0, r = n-1;
        int numberofboats = 0;
        while (l <= r) {
            if (people[r] == limit) {
                numberofboats++;
                r--;
            }
            else {
                if (l != r && people[r] + people[l] <= limit) {
                    r--;
                    l++;
                    numberofboats++;
                }
                else {
                    r--;
                    numberofboats++;
                }
            }
        }
        return numberofboats;
    }




















    /*
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
    */
};