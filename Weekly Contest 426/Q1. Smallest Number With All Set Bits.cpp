class Solution {
private:
    vector<int> targets = {1,3,7,15,31,63,127,255,511,1023};
public:
    int smallestNumber(int n) {
        for (auto target : targets) {
            if (target >= n) return target;
        }
        return -1;
    }
};

// can we BS for value from 1 to 1000