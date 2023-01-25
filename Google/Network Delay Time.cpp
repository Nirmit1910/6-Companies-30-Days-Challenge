class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dist(n+1,1e9);
        
        vector<vector<pair<int,int>>>adj(n+1);
        
        for(auto it:times)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;        
        pq.push({k,0});
        
        dist[k]=0;
        
        while(pq.size())
        {
            auto it=pq.top();
            pq.pop();
            
            int node=it.first;
            int d=it.second;
            
            for(auto it:adj[node])
            {
                int adjNode=it.first;
                int dis=it.second;
                
                if(d+dis<dist[adjNode])
                {
                    dist[adjNode]=d+dis;
                    pq.push({adjNode,dist[adjNode]});
                }
            }
        }
        int ans=0;
        
        for(int i=1;i<=n;i++)
        {
            if(dist[i]==1e9)
                return -1;
            ans=max(ans,dist[i]);
        }
        return ans;
    }
};