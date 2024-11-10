class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> > pq;
        pq.push({0,0,0,0});
        int end_x = moveTime.size()-1;
        int end_y = moveTime[0].size()-1;
        vector<vector<bool>> visited(end_x+1, vector<bool>(end_y+1, 0));
        vector<int> cost = {1,2};
        int index = 0;
        while(!pq.empty()){
            // pop top of the pq
            vector<int> current = pq.top();
            pq.pop();
            int time = current[0];
            int x = current[1];
            int y = current[2];
            index = current[3];
            if (visited[x][y] != 0) continue;
            visited[x][y] = 1;
            // check if it is the goal
            if (x == end_x && y == end_y) return time;
            // push all possible paths into the pq
            int t = cost[index%2];
            if (x < end_x){
                int new_time = max(time+t,moveTime[x+1][y]+t);
                pq.push({new_time, x+1,y, index+1});
            }
            if (y < end_y){
                int new_time = max(time+t,moveTime[x][y+1]+t);
                pq.push({new_time, x,y+1,index+1});
            }
            if (x > 0){
                int new_time = max(time+t,moveTime[x-1][y]+t);
                pq.push({new_time, x-1,y, index+1});
            }
            if (y > 0){
                int new_time = max(time+t,moveTime[x][y-1]+t);
                pq.push({new_time, x,y-1, index+1});
            }
        }
        return -1;
    }
};