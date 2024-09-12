class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) 
    {
        priority_queue<int> pq;
        vector<int> res;
        for (int i = 0; i < queries.size(); i++)
        {
            int curr = abs(queries[i][0]) + abs(queries[i][1]);
            pq.push(curr);
            while(pq.size() > k)
                pq.pop();
            if (pq.size() < k)
                res.push_back(-1);
            else
                res.push_back(pq.top());
        }    
        return res;
    }
};