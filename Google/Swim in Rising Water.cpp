class Solution {
public:
    int directions[4][2] = {{1,0},{0,1},{-1,0},{0,-1}}; 
    int swimInWater(vector<vector<int>>& grid) {

        int n=grid.size();

        vector<vector<int>> visited(n,vector<int>(n,0));
        int ans = 0;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({grid[0][0],{0,0}});

        while(!pq.empty())
        {
            int i=pq.top().second.first;
            int j=pq.top().second.second;

            visited[i][j]=1;

            ans = max(ans, pq.top().first);
            pq.pop();
            
            if(i == n-1 and j == n-1)            
                return ans;
            
            for(auto dir : directions){
                int newX = dir[0] + i;
                int newY = dir[1] + j;
                
                if(newX >= 0 and newX < n and newY >= 0 and newY < n and visited[newX][newY] == 0){
                    pq.push({grid[newX][newY],{newX, newY}});
                    visited[newX][newY] = 1;
                }
            }
        }
    return 0;
    }
};