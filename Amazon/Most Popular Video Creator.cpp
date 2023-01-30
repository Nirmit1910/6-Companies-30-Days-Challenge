
class Solution {

    
public:
    static bool comparator(pair<long long,string>&p1,pair<long long,string>&p2)
    {
        if(p1.first!=p2.first)
        return p1.first>p2.first;
        else
            return p1.second<p2.second;
    }
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        vector<vector<string>>ans;
        
        map<string,long long>m;//creator,popularity;
        
        map<string,vector<pair<long long,string>>>mp;
        long long maxv=0;
        for(int i=0;i<creators.size();i++)
        {
            m[creators[i]]+=views[i];
            if(maxv<=m[creators[i]])
            {
                maxv=m[creators[i]];
            }
        }
        
        for(int i=0;i<creators.size();i++)
        {
            mp[creators[i]].push_back({views[i],ids[i]});
        }
        
        
        for(auto it:m)
        {
            if(it.second==maxv)
            {
                string cr=it.first;
                sort(mp[cr].begin(),mp[cr].end(),comparator);
                vector<string>temp;
                temp.push_back(cr);
                temp.push_back(mp[cr][0].second);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};