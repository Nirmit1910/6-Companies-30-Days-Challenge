class StockPrice {
public:
    unordered_map<int,int>m;
    multiset<int>s;
    int maxi=0;
    int mini=0;
    int curr=0;
    StockPrice() {
    }
    
    void update(int timestamp, int price) {
        if(m.find(timestamp)!=m.end())
        {
            s.erase(s.find(m[timestamp]));
            s.insert(price);
            m[timestamp]=price;
        }
        else
        {
            m[timestamp]=price;
            s.insert(price);
        }
        curr=max(timestamp,curr);
        maxi=*s.rbegin();
        mini=*s.begin();
    }
    
    int current() {
        return m[curr];
    }
    
    int maximum() {
        return maxi;
    }
    
    int minimum() {
        return mini;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */