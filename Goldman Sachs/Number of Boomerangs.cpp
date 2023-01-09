class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans=0;
        if(points.size()<=2)
        {
            return 0;
        }
        
        for(int i=0;i<points.size();i++)
        {
            map<long,int>m;
            for(int j=0;j<points.size();j++)
            {
                if(j==i)
                continue;
                long dist=pow(points[i][0]-points[j][0],2)+pow(points[i][1]-points[j][1],2);
                m[dist]++;
            }
            for(auto it:m)
        {
            if(it.second)
            ans+=(it.second-1)*(it.second);
        }
        }

        return ans;
    }
};