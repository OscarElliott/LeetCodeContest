class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        // the total number of valid selections
        int result = 0;
        // pre_sum will track the sum of previous elements
        int pre_sum = 0;
        // total will be used to calculate difference ahead
        int total = 0;
        // calculate total
        for (auto num : nums) total+=num;
        // check for each index if it is zero -> if the value either side is equal or +-1
        for (auto num : nums) {
            if (num == 0) {
                int difference = abs(total - pre_sum - pre_sum);
                if (difference < 2) {
                    result += (2-difference);
                }
            }
            else pre_sum += num;
        }
        return result;
    }
};