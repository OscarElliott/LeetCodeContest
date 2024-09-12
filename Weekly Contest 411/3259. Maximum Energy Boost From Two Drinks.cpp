class Solution {
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) 
    {
        int n = energyDrinkA.size();
        vector<long long> dpA(n,0);
        vector<long long> dpB(n,0);
        dpA[0] = energyDrinkA[0];
        dpA[1] = energyDrinkA[1]+dpA[0];
        dpB[0] = energyDrinkB[0];
        dpB[1] = energyDrinkB[1]+dpB[0];
        for (int i = 2; i < n; i++)
        {
            dpA[i] = energyDrinkA[i] + max(dpA[i-1],dpB[i-2]);
            dpB[i] = energyDrinkB[i] + max(dpB[i-1],dpA[i-2]);
        }
        return max(dpB[n-1], dpA[n-1]);
    }
};