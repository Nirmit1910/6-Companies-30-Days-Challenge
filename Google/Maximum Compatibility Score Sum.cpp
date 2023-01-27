class Solution {
public:
    int ans=0,n;
    int used[9] = {};
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        n=students.size();
        dfs(students,mentors,0,0);
        return ans;
    }

    void dfs(vector<vector<int>>& students, vector<vector<int>>& mentors,int i,int score)
    {
        if(i==n)
        {
            ans=max(ans,score);
            return;
        }   

        for(int j=0;j<n;j++)
        {
            if(used[j])
            continue;
            int s=0;
            used[j]=1;
            for (int k=0;k<students[0].size();k++) 
            s += students[i][k] ==mentors[j][k];
            dfs(students,mentors,i+1,score+s);
            used[j]=0;
        }
    }
};