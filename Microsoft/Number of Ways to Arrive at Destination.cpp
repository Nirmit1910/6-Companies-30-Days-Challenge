class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>>adj[n];
        
        for(auto it:roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<long long>dist(n,1e18);
        vector<int>ways(n,0);
        
        dist[0]=0;
        ways[0]=1;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0,0});
        int MOD=1e9+7;
        while(!pq.empty())
        {
            auto it=pq.top();
            long long dis=it.first;
            long long node=it.second;
            pq.pop();
            
            for(auto it:adj[node])
            {
                long long adjnode=it.first;
                long long w=it.second;
                
                if(dis+w<dist[adjnode])
                {
                    dist[adjnode]=dis+w;
                    pq.push({dist[adjnode],adjnode});
                    ways[adjnode]=ways[node];
                }
                else if(dis+w==dist[adjnode])
                {
                    ways[adjnode]=ways[adjnode]+ways[node];
                    ways[adjnode]=ways[adjnode]%MOD;
                }
            }
        }
        
        return ways[n-1]%MOD;
    }
};