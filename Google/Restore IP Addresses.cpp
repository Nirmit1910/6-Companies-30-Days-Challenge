class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string>ans;
        string temp="";
        temp+=s[0];
        f(s,ans,temp,1);
        return ans;
    }

    void f(string &s,vector<string>&ans,string temp,int index)
    {
        if(index==s.length())
        {
            temp+=".";
            int dot=0;
            string t="";
            // cout<<temp<<"\n";
            for(int i=0;i<temp.length();i++)
            {
                if(temp[i]=='.')
                {
                    cout<<t<<" ";
                    if(i!=temp.length()-1)
                    dot++;
                    if(t.length()>=4 || t.length()==0)
                    {
                        // cout<<"\n";
                        return;
                    }
                    if(t.length()>=2 and t[0]=='0')
                    {
                        // cout<<"\n";
                        return;
                    }
                    int num=stoi(t);
                    if(num>255)
                    {
                        // cout<<"\n";
                        return;
                    }
                    t="";
                }
                else
                {
                    t+=temp[i];
                }
            }
            temp.pop_back();
            if(dot==3)
            ans.push_back(temp);
            return;  
        }
        temp.push_back('.');
        temp.push_back(s[index]);
        f(s,ans,temp,index+1);

        temp.pop_back();
        temp.pop_back();

        temp.push_back(s[index]);
        f(s,ans,temp,index+1);

    }
};