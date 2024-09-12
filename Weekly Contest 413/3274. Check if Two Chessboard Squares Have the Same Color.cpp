class Solution 
{
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) 
    {
        int C1A = (coordinate1[0]-'a') % 2;
        int C2A = (coordinate2[0]-'a') % 2;
        int C1B = (coordinate1[1]-'1') % 2;
        int C2B = (coordinate2[1]-'1') % 2;
        if (C1A == C2A)
        {
            if (C1B == C2B) return true;
            return false;
        }
        if (C1B != C2B) return true;
        return false;
    }
};