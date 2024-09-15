class Solution 
{
public:
    long long maxScore(vector<int>& a, vector<int>& b) 
    {
        int i = 0;
        int j = 0;
        vector<vector<long long>> DP(4, vector<long long>(100000, 0));
        return solve(a, b, i, j, DP);
    }

    long long solve(vector<int>& a, vector<int>& b, int i, int j, vector<vector<long long>> & DP)
    {
        if (i >= 4 || j >= b.size()) return 0;
        // if pre calculated return DP
        if (DP[i][j]) return DP[i][j];
        // use current value and times by a[i]
        long long p1 = static_cast<long long>(a[i]) * static_cast<long long>(b[j]) + solve(a, b, i+1, j+1, DP);
        // skip current value
        long long p2 = numeric_limits<long long>::min();
        if ((j+4-i) < b.size())
            p2 = solve(a, b, i, j+1, DP);
        // total is max of either path
        return DP[i][j] = max(p1,p2);
    }
};