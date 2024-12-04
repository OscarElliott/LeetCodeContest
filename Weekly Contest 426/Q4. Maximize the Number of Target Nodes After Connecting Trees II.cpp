// TLE 816/824
class Solution {
private:
    int bfs(vector<vector<int>> & adj_list, int start) {
        queue<pair<int,int>> q; 
        int n = adj_list.size();
        //unordered_set<int> visited;
        vector<bool> visited(n+1,0);
        int count = 1;
        q.push({start,0});
        //visited.insert(start);
        visited[start] = true;
        while(!q.empty()) { 
            auto current = q.front();
            int node = current.first;
            int cost = current.second;
            q.pop();
            
            for (auto neighbour : adj_list[node]) {
                if (visited[neighbour]) continue;
                //if (visited.find(neighbour) != visited.end()) continue;
                q.push({neighbour, cost+1});
                //cout << "push " << neighbour << " cost " << cost << endl;
                if (cost % 2 == 1) count++;
                visited[neighbour] = true;
                //visited.insert(neighbour);
            }
        }
        //cout << "final count : " << count << endl;
        return count;
    }
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size()+1;
        int m = edges2.size()+1;
        // make adj list for both graphs
        vector<vector<int>> adj_list_1(n);
        vector<vector<int>> adj_list_2(m);
        for (auto edge : edges1) {
            adj_list_1[edge[0]].push_back(edge[1]);
            adj_list_1[edge[1]].push_back(edge[0]);
        }
        for (auto edge : edges2) {
            adj_list_2[edge[0]].push_back(edge[1]);
            adj_list_2[edge[1]].push_back(edge[0]);
        }
        // count the k BFS depth from each node in graph 1 and update result
        vector<int> result(n,0);
        for (int i = 0; i < n; i++) {
            result[i] += bfs(adj_list_1, i);
        }
        // count the k BFS depth from each node in graph 2 and save the max
        int graph_2_max = 0;
        for (int i = 0; i < m; i++) {
            graph_2_max =  max(bfs(adj_list_2, i), graph_2_max);
        }
        for (int i = 0; i < n; i++) {
            result[i] += graph_2_max;
        }
        return result;
    }
};