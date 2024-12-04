class Solution {
private:
    int bfs(vector<vector<int>> & adj_list, int limit, int start) {
        queue<pair<int,int>> q; 
        unordered_set<int> visited;
        int count = 1;
        q.push({start,0});
        visited.insert(start);
        while(!q.empty()) { 
            auto current = q.front();
            int node = current.first;
            int cost = current.second;
            q.pop();
            if(cost >= limit) continue; // don't search anymore hit limit
            
            for (auto neighbour : adj_list[node]) {
                if (visited.find(neighbour) != visited.end()) continue;
                q.push({neighbour, cost+1});
                //cout << "push " << neighbour << " cost " << cost << endl;
                count++;
                visited.insert(neighbour);
            }
        }
        //cout << "final count : " << count << endl;
        return count;
    }
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size()+1;
        int m = edges2.size()+1;
        if (k == 0) return vector<int>(n,1);
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
            result[i] += bfs(adj_list_1, k, i);
        }
        // count the k BFS depth from each node in graph 2 and save the max
        int graph_2_max = 0;
        for (int i = 0; i < m; i++) {
            graph_2_max =  max(bfs(adj_list_2, k-1, i), graph_2_max);
        }
        for (int i = 0; i < n; i++) {
            result[i] += graph_2_max;
        }
        return result;
    }
};