class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        
        for(int i=0;i<n;i++)
        {
            dist[i][i]=0;
        }
        for(vector<int>v:edges){
            dist[v[0]][v[1]]=v[2];
            dist[v[1]][v[0]]=v[2];
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(dist[i][k]!=INT_MAX and dist[k][j]!=INT_MAX and dist[i][k]+dist[k][j]<dist[i][j])
                        dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
        int citycount=INT_MAX;
        int ans;
        for(int i=0;i<n;i++)
        {
            int count=0;
            for(int j=0;j<n;j++)
            {
                if(i!=j and dist[i][j]<=distanceThreshold)
                    count++;
            }
            if(count<=citycount)
            {
                ans=i;
                citycount=count;
            }
        }
        return ans;
    }
};