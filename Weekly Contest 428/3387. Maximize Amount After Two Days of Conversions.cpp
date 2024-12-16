class Solution {
public:
    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
        // day one
        queue<pair<string, double>> q1; // {currency, amount}
        queue<pair<string, double>> q2; 
        q1.push({initialCurrency, 1.0});
        set<vector<string>> used1; // we only want to use each path once
        // make all paths for day one
        while(!q1.empty()) {
            auto [currency, amount] = q1.front();
            q1.pop();
            q2.push({currency, amount});
            for (int i = 0; i < pairs1.size(); i++) {
                if (pairs1[i][0] == currency) {
                    q1.push({pairs1[i][1], amount*rates1[i]});
                    used1.insert({pairs1[i][0], pairs1[i][1]});
                }
                else if (pairs1[i][1] == currency && used1.find({pairs1[i][1], pairs1[i][0]}) == used1.end()) {
                    q1.push({pairs1[i][0], amount/rates1[i]});
                    used1.insert({pairs1[i][1], pairs1[i][0]});
                }
            }
        }
        // search for valid end points on day 2 recording the largest
        double bestEnd = 1.0;
        set<tuple<string, string, double>> used2;
        while(!q2.empty()) {
            auto [currency, amount] = q2.front();
            q2.pop();
            if (currency == initialCurrency) bestEnd = max(bestEnd, amount);
            for (int i = 0; i < pairs2.size(); i++) {
                if (pairs2[i][0] == currency) {
                    q2.push({pairs2[i][1], amount*rates2[i]});
                    used2.insert({pairs2[i][0], pairs2[i][1], amount});
                }
                else if (pairs2[i][1] == currency && used2.find({pairs2[i][1], pairs2[i][0], amount}) == used2.end()) {
                    q2.push({pairs2[i][0], amount/rates2[i]});
                    used2.insert({pairs2[i][1], pairs2[i][0], amount});
                }
            }
        }
        return bestEnd;
    }
};

// BFS save largest valid end