class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<pair<int,int>,int>m;

        for(auto it:rectangles)
        {
            m[{it[0],it[1]}]++;
            m[{it[0],it[3]}]--;
            m[{it[2],it[1]}]--;
            m[{it[2],it[3]}]++;
        }
        int c=0;
        for(auto it:m)
        {
            if(it.second)
            {
                if(abs(it.second)!=1)
                return false;
                c++;
            }
        }

        return c==4;
    }
};