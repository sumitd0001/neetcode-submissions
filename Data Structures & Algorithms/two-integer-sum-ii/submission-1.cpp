class Solution {
public:
    
    
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size()-1;

        while (l < r) {
            if (numbers[l] + numbers[r] == target) return {l+1, r+1};
            else if (numbers[l] + numbers[r] > target) r--;
            else l++;
        }
        return {};
    }

































    /*
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();

        int i = 0, j = n-1;
        while (i < j) {
            if (numbers[i] + numbers[j] == target) {
                break;
            }
            else if (numbers[i] + numbers[j] < target) i++;
            else j--;
        }
        return {i+1, j+1};
    }
    */
};