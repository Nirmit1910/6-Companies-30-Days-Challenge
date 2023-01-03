class Solution {
public:
        int ans = 0;
        int maxAns = INT_MIN;
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n=edges.size();
        vector<int>parent(n+1,-1);
        vector<int>dist(n+1,-1);
        map<int,vector<int>>m;
        
        vector<int>vis(n+1,-1);
        for(auto it:edges)
        {
            m[it[0]].push_back(it[1]);
            m[it[1]].push_back(it[0]);
        }

        dfsToParent(0,0,0,parent,dist,m);

        int curr = bob;
        int currDist = 0;
        while(curr!=0){
            if(dist[curr]>currDist){
                amount[curr] = 0;
            }else if(dist[curr] == currDist){
                amount[curr]/=2;
            }
            curr = parent[curr];
            currDist++;
        }
        dfs(0, amount,m,vis);
        return maxAns;
    }

    void dfsToParent(int par,int curr,int dis,vector<int>&parent,vector<int>&dist,map<int,vector<int>>&m)
    {
        dist[curr]=dis;
        parent[curr]=par;

        for(auto it:m[curr])
        {
            if(it==par)
            continue;
            dfsToParent(curr,it,dis+1,parent,dist,m);
        }
    }
    void dfs(int curr,vector<int>&amount,map<int,vector<int>>&m,vector<int>&vis)
    {
       vis[curr]=1;
        ans += amount[curr];
        int trav = 0;
        for(auto currNeighbour: m[curr]){
            if(vis[currNeighbour]==1){
                continue;
            }
            trav++;
            dfs(currNeighbour,amount,m,vis);
        }
        if(trav==0){
            maxAns = max(ans, maxAns);
        }
        
        ans -= amount[curr];
    }
};