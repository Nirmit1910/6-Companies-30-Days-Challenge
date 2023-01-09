class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>>v;

        for(int i=0;i<capital.size();i++)
        {
            v.push_back({capital[i],profits[i]});
        }
        sort(v.begin(),v.end());
        priority_queue<int>pq;

        int i=0;
        while(i<v.size() and k)
        {
            if(w>=v[i].first)
            {
                pq.push(v[i].second);
                i++;
            }
            else
            {
                if(pq.empty())
                return w;
                w+=pq.top();
                pq.pop();
                k--;
            }
        }
        while(k-- and !pq.empty())
        {
            w+=pq.top();
            pq.pop();
        }
        return w;
    }
};