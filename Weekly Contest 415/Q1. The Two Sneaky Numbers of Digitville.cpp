class Solution 
{
public:
    vector<int> getSneakyNumbers(vector<int>& nums) 
    {
        unordered_map<int,int> freq;
        vector<int> ans;
        for (auto num : nums)
        {
            freq[num]++;
            if (freq[num] == 2) ans.push_back(num);
        } 
        return ans;
    }
};