class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool>vis(numCourses,0);
        vector<bool>DFSvis(numCourses,0);
        
        vector<int>adj[numCourses];
        
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
            //adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i])
            {
                if(!DFSvisit(i,adj,vis,DFSvis))
                    return false;
            }
        }
        return true;
    }
    bool DFSvisit(int node,vector<int>adj[],vector<bool>&vis,vector<bool>&DFSvis)
    {
        vis[node]=1;
        DFSvis[node]=1;
        
        for(auto it:adj[node])
        {
            if(vis[it]==0)
            {
                if(DFSvisit(it,adj,vis,DFSvis)==false)
                    return false;
            }
            else if(DFSvis[it])
                return false;
        }
        DFSvis[node]=0;
        return true;
    }
};