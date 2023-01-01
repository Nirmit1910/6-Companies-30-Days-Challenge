class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<int,int>m;
        unordered_map<int,int>mp;
        int bulls=0,cows=0;
        for(int i=0;i<secret.size();i++)
        {
            if(secret[i]==guess[i])
            {
                bulls++;
            }
            else
            {
                m[secret[i]-'0']++;
                mp[guess[i]-'0']++;
            }
        }
        
        for(int i=0;i<=9;i++)
        {   
            cows+=min(m[i],mp[i]);
        }
        string ans="";
        ans=to_string(bulls)+"A"+to_string(cows)+"B";

        return ans;
    }
};