class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int>m;

        for(auto it:words)
        {
            m[it]++;
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>,myComp>pq;

        for(auto it:m)
        {
            pq.push({it.second,it.first});
            if(pq.size()>k)
            pq.pop();
        }
        vector<string>ans;
        while(pq.size())
        {   
            ans.push_back(pq.top().second);
            cout<<pq.top().first<<"\n";
            pq.pop();
        }
        return ans;
    }
    private:
    struct myComp{
        bool operator()(const pair<int,string>&a,const pair<int,string>&b){
            if(a.first!=b.first)
                return a.first>b.first;
            else
                return a.second<b.second;
        }
    };
};