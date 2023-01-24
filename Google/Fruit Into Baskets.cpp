class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        vector<int>v(2,-1);

        unordered_map<int,int>m;
        int ans=0;
        for(int i=0;i<fruits.size();i++)
        {
            if(v[0]!=fruits[i] and v[1]!=fruits[i])
            {
                int temp=0;
                for(auto it:v)
                {
                    temp+=m[it];
                }
                ans=max(ans,temp);
                m[v[0]]=0;
                if(i-1>=0)
                {
                    v[0]=fruits[i-1];
                    v[1]=fruits[i];
                    m[v[1]]=1;
                    // m[fruits[i]]++;
                    int k=i-1;
                    m[v[0]]=0;

                    while(k>=0)
                    {
                        if(fruits[k--]==fruits[i-1])
                        {
                            m[fruits[i-1]]++;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                else
                {
                    v[1]=fruits[i];
                    m[fruits[i]]++;
                }
            }
            else
            {
                m[fruits[i]]++;
            }
            // for(auto it:v)
            // {
            //     cout<<it<<" ";
            // }
            // cout<<"\n";
        }
        int temp=0;
        for(auto it:v)
        {
            temp+=m[it];
        }
        ans=max(ans,temp);
        return ans;
    }
};