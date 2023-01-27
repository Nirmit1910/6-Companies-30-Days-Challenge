class Solution {
public:
    int ans=1;
    int maxUniqueSplit(string s) {
        unordered_set<string>m;
        string temp="";
        f(s,m,0,0);
        return ans;
    }

    void f(string s,unordered_set<string>&m,int index,int count)
    {
        if(index==s.length())
        {
            ans=max(ans,count);
        }
        string t="";
        for(int i=index;i<s.length();i++)
        {
            t.push_back(s[i]);
            if(m.find(t)==m.end())
            {
                m.insert(t);
                f(s,m,i+1,count+1);
                m.erase(t);
            }
        }
    }
};