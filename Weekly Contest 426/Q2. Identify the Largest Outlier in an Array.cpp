class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int sum = 0;
        int max_outlier = INT_MIN;
        vector<int> freq(2010,0);
        for (auto num : nums) {
            freq[num+1000]++;
            sum += num;
        }
        // for sum - i - j = j find two values i and j return i
        for (int i = -1000; i < 1001; i++) {
            // if not seen skip
            if (freq[i+1000] == 0) continue;
            freq[i+1000]--;
            for (int j = -1000; j < 1001; j++) {
                if (freq[j+1000] == 0) continue;
                if (sum - i -j == j) {
                    //cout << i << " " << j << endl;
                    max_outlier = max(i,max_outlier);
                }
            }
            freq[i+1000]++;
        }
        return max_outlier;
    }
};

// crazy but try a search freq space approach