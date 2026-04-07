class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];
        
        for(auto &it : roads){
            int u = it[0], v = it[1], wt = it[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        priority_queue<pair<long long,int>, 
                       vector<pair<long long,int>>, 
                       greater<pair<long long,int>>> pq;

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        int mod = 1e9 + 7;

        dist[0] = 0;
        ways[0] = 1;

        pq.push({0, 0});

        while(!pq.empty()){
            auto [d, node] = pq.top();
            pq.pop();

            for(auto &it : adj[node]){
                int adjNode = it.first;
                int wt = it.second;

                if(d + wt < dist[adjNode]){
                    dist[adjNode] = d + wt;
                    ways[adjNode] = ways[node];
                    pq.push({dist[adjNode], adjNode});
                }
                else if(d + wt == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }

        return ways[n-1] % mod;
    }
};
