// accepted
class Solution 
{
public:
    char kthCharacter(int k) 
    {
        string curr = "a";
        while (k > curr.size())
        {
            curr += flipAdd(curr);
            //cout << curr << endl;
        }   
        return curr[k-1];
    }

    string flipAdd(string curr)
    {
        for (int i = 0; i < curr.size(); i++)
        {
            curr[i] = curr[i]+1;
            if (curr[i] > 'z') curr[i] = 'a';
        }
        return curr;
    }
};