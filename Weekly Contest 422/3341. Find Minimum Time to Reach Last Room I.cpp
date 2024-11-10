class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> > pq;
        pq.push({0,0,0});
        int end_x = moveTime.size()-1;
        int end_y = moveTime[0].size()-1;
        set< pair<int,int> > visited;
        while(!pq.empty()){
            // pop top of the pq
            vector<int> current = pq.top();
            pq.pop();
            int time = current[0];
            int x = current[1];
            int y = current[2];
            if (visited.find({x,y}) != visited.end()) continue;
            visited.insert({x,y});
            // check if it is the goal
            if (x == end_x && y == end_y) return time;
            // push all possible paths into the pq
            if (x < end_x){
                int new_time = max(time+1,moveTime[x+1][y]+1);
                pq.push({new_time, x+1,y});
            }
            if (y < end_y){
                int new_time = max(time+1,moveTime[x][y+1]+1);
                pq.push({new_time, x,y+1});
            }
            if (x > 0){
                int new_time = max(time+1,moveTime[x-1][y]+1);
                pq.push({new_time, x-1,y});
            }
            if (y > 0){
                int new_time = max(time+1,moveTime[x][y-1]+1);
                pq.push({new_time, x,y-1});
            }
        }
        return -1;
    }
};
