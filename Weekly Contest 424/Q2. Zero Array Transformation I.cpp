class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) 
    {
        vector<pair<int,int>> list;
        int n = nums.size();
        for (auto query : queries) {
            list.push_back({query[0], 1});
            list.push_back({query[1]+1, -1});
        }
        sort(list.begin(), list.end());
        map<int, int> valid;
        int sum = 0;
        int i = 0;
        for (auto l : list) {
            sum += l.second;
            valid[l.first] = sum;
        }
        for (int i = 0; i < n; i++) {
            auto it = valid.lower_bound(i);
            if (it->first > i && it != valid.begin()) it--;
            //cout << it->first << " " << it->second << endl;
            if (it != valid.end() && it->second < nums[i])
                return false;
        }
        return true;
    }
};

// no counter proof for dont be greedy so be greedy
//      By this we mean that we should always decrement an element > 0
//      Hence we can simply calculate the maximum decrement for each range using a range map 
//      Then verify if the given array can be 0 minimized