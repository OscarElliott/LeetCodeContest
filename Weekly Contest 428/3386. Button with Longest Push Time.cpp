class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int biggestGap = events[0][1];
        int res = events[0][0];
        for (int i = 1; i < events.size(); i++) {
            if (biggestGap < events[i][1]-events[i-1][1]) {
                biggestGap = events[i][1]-events[i-1][1];
                res = events[i][0];
            }
            else if (biggestGap == events[i][1]-events[i-1][1]) res = min(events[i][0], res);
                
        }
        return res;
    }
};