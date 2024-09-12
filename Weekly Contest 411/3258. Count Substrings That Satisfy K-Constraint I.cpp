class Solution {
public:
    int countKConstraintSubstrings(string s, int k) 
    {
        int zeros = 0;
        int ones = 0;
        int len = 0;
        int n = s.size();
        int res = 0;
        int ptr = 0;
        for (int i  = 0; i < n; i++)
        {
            (s[i] == '0') ? zeros++ : ones++;
            len++;
            while (true)
            {
                if (zeros <= k) 
                {
                    res+=len;
                    break;
                }
                else if (ones <= k) 
                {
                    res+= len;
                    break;
                }
                else
                {
                    (s[ptr] == '0') ? zeros-- : ones--;
                    ptr++;
                    len--;
                }
            }   
        }
        return res;
    }
};