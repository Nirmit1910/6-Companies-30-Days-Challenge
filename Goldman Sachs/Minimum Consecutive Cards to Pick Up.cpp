class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        map<int,int>m;

        int ans=INT_MAX;
        for(int i=0;i<cards.size();i++)
        {
            if(m.find(cards[i])!=m.end())
            {
                ans=min(ans,i-m[cards[i]]);
                m[cards[i]]=i;
            }
            else
            {
                m[cards[i]]=i;
            }
        }
        if(ans==INT_MAX)
        return -1;
        return ans+1;
    }
};