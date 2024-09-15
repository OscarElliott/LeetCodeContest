class Solution // TLE - NOT ACCEPTED
{
public:
    int minValidStrings(vector<string>& words, string target) 
    {
        unordered_set<string> prefixes;
        for (auto word : words)
        {
            string temp = "";
            for (auto c : word)
            {
                temp.push_back(c);
                prefixes.insert(temp);
            }
        }
        vector<int> DP(target.size(), -1);
        int ans = solve(prefixes, target, 0, DP);
        return (ans == INT_MAX-1) ? -1 : ans;
    }

    int solve(unordered_set<string>& prefixes, const string & target, int i, vector<int> & DP)
    {
        if (i >= target.size()) return 0;
        if (DP[i] != -1) return DP[i];
        int bestPath = INT_MAX-1;
        // set prefix of i+1
        string prefix = "";
        int j = i;
        // while true
        while (true)
        {
            // try prefix
            prefix += target[j];
            // if not in set break
            if (prefixes.find(prefix) == prefixes.end()) break;
            //cout << "prefix : " << prefix << " was found" << endl;
            // solve for that path & increase prefix
            j++;
            bestPath = min(bestPath, 1+solve(prefixes, target,j,DP));
            
        }
        return DP[i] = bestPath;
    }
};