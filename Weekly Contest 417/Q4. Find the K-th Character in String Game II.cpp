// NOT accepted
class Solution 
{
public:
    char kthCharacter(long long k, vector<int>& operations)
    {
        char res = 'a';
        int op = -1;
        vector<long long> sections;
        long long i = 1;
        while (k > i)
        {
            sections.push_back(i);
            i*=2;
            op++;
        }
        cout << i/2 << endl;
        cout << op << endl;
        int j = sections.size()-1;
        while (k > 2)
        {
            while(k < sections[j])
            {
                j--;
                op--;
            }
            if (k == sections[j]) k/=2;
            else k = k - sections[j];
            j--;
            res += operations[op--];
            cout << k << res << endl;
        }
        if (k == 2)
            res += operations[0];
        return res;
    }
};