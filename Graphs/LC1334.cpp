class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> adj(n);
        
        
        for(auto &it : edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        int city = -1;
        int minReachable = INT_MAX;

        for(int i = 0; i < n; i++){
            
            vector<int> dist(n, INT_MAX);
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

            dist[i] = 0;
            pq.push({0, i});

            while(!pq.empty()){
                auto [d, node] = pq.top();
                pq.pop();

                for(auto &it : adj[node]){
                    int adjNode = it.first;
                    int weight = it.second;

                    if(d + weight < dist[adjNode]){
                        dist[adjNode] = d + weight;
                        pq.push({dist[adjNode], adjNode});
                    }
                }
            }

           
            int count = 0;
            for(int j = 0; j < n; j++){
                if(dist[j] <= distanceThreshold){
                    count++;
                }
            }

            
            if(count <= minReachable){
                minReachable = count;
                city = i;
            }
        }

        return city;
    }
};
