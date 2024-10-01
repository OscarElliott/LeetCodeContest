// TLE
class Solution 
{
private:
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
public:
    long long countOfSubstrings(string word, int k) 
    {
        int n = word.size();
        int count = 0;

        // Sliding window approach
        for (int i = 0; i < n; ++i) 
        {
            unordered_map<char, int> vowel_freq;
            int consonants = 0;
            for (int j = i; j < n; ++j) 
            {
                if (vowels.count(word[j])) 
                {
                    vowel_freq[word[j]]++;
                } 
                else 
                {
                    consonants++;
                }
                
                // Check if the substring contains all vowels at least once
                if (vowel_freq.size() == 5 && consonants == k) 
                {
                    count++;
                    //cout << i << " " << j << endl;
                }
                
                // If consonants exceed k, stop expanding this window
                if (consonants > k)
                    break;
            }
        }
        
        return count;
    }
};