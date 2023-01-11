class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string ans="";


        if((numerator<0 and denominator>0) || (denominator<0 and numerator>0))
        {
            ans+="-";
        }
        long long a=abs(numerator);
        long long b=abs(denominator);
        ans+=to_string(a/b);

        if(a%b==0)
        return ans;

        ans+=".";

        long long rem=a%b;

        string rec="";
        map<long long,int>m;

        while(rem)
        {
            if(m.find(rem)!=m.end())
            {
                int ind=m[rem];
                string rep=rec.substr(ind);
                rec.erase(ind);
                rec+="("+rep+")";
                break;
            }
            else
            {
                cout<<rem<<" ";
                long long c=rem*10/b;
                cout<<c<<"\n";
                m[rem]=rec.length();
                rec+=to_string(c);
                rem=rem*10%b;
            }
        }
        ans+=rec;
        return ans;
    }
};