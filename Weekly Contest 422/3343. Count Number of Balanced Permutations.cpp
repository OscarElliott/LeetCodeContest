// TLE: cleanest solution
class Solution 
{
public:
    int countBalancedPermutations(string num) {
        int count  = 0;
        sort(num.begin(), num.end());
        do {
            count += isBalanced(num);
        } while (next_permutation(num.begin(), num.end()));
        return count;
    }

    int isBalanced(string num) {
        int odd = 0;
        int even = 0;
        int n = num.size();
        for (int i  = 0; i < n; i++) {
            if (i % 2 == 0) even+=num[i]-'0';
            else odd += num[i]-'0';
        }
        return (odd == even);
    }
};

// TLE reccursive solution
class Solution 
{
private:
    int mod = 1000000007;
    unordered_set<string> memo;
public:
    int countBalancedPermutations(string num) {
        int count  = 0;
        int n = num.size();
        vector<bool> used(n,false);
        string s = "";
        solve(num, 0, n, used, 0, 0, count, s);
        return count % mod;
    }

    void solve(string num, int i, int n, vector<bool> & used, int odd, int even, int & count, string & s) {
       if (memo.find(s) != memo.end()) return;
        // if i == n
        if (i == n) {
            //cout << s << endl;
            count += (odd == even) % mod;
            memo.insert(s);
        }
        for (int j = 0; j < n; j++) {
            if (used[j]) continue;
            used[j] = true;
            s += num[j];
            if (i % 2 == 0)
                solve(num, i+1, n, used, odd, even+num[j]-'0', count, s);
            else
                solve(num, i+1, n, used, odd+num[j]-'0', even, count, s);
            used[j] = false;
            memo.insert(s);
            s.pop_back();
        }
    }
};


