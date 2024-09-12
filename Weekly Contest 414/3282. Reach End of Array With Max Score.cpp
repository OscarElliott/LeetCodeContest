class Solution 
{
public:
    long long findMaximumScore(vector<int>& nums) 
    {
        int n = nums.size();
        long long sum = 0;
        int largest = nums[0];
        for (int i  = 1; i < n; i++)
        {
            sum += largest;
            largest = max(largest, nums[i]);
        }
        return sum;
    }
};