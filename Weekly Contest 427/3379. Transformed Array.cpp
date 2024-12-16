class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) result[i] = 0;
            else if (nums[i] > 0) result[i] = nums[(i+nums[i])%n];
            else if (nums[i] < 0) {
                int pos = i+nums[i];
                while (pos < 0) pos = (n+pos);
                result[i] = nums[pos];
            }
        }
        return result;
    }
};