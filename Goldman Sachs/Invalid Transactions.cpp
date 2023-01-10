class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<string>name,city,res;
        vector<int>time,amount;
        int flag=0;
        for(auto i:transactions)
        {
            stringstream ss(i);
            string st;

            while(getline(ss,st,',')){
                if(flag==0)
                {
                    name.push_back(st);
                    flag=1;
                }
                else if(flag==1)
                {
                    time.push_back(stoi(st));
                    flag=2;
                }
                else if(flag==2)
                {
                    amount.push_back(stoi(st));
                    flag=3;
                }
                else if(flag==3)
                {
                    city.push_back(st);
                    flag=0;
                }
            }
        }
        int j=0;
        for(auto it:amount)
        {
            if(it>1000)
            {
                res.push_back(transactions[j]);
            }
            j++;
        }

                
        for(int i=0;i<transactions.size();i++)
        {
            for(int j=0;j<transactions.size();j++)
            {
                if(name[i]==name[j] and city[i]!=city[j])
                {
                    if(abs(time[i]-time[j])<=60)
                    {
                        if(amount[i]<=1000){
                            res.push_back(transactions[i]);
                            break;
                        }
                    }
                }
            }
        }
        return res;
    }
};