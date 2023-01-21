class Solution {
public:
    
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        vector<int>ans;
        if(barcodes.size() <= 1) return barcodes;
        unordered_map<int,int>m;
       
        for(auto it:barcodes)
        {
            m[it]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto it:m)
        {
            pq.push({it.second,it.first});
        }      
        
        while(pq.top().first>0)
        {
            pair<int,int>p1=pq.top();
            ans.push_back(p1.second);
            pq.pop();   
            
            pair<int,int>p2=pq.top();
            if(p2.first>0)
            ans.push_back(p2.second);
            pq.pop();

            p1.first--;
            p2.first--;
            pq.push(p1);
            pq.push(p2);
        }
        return ans;    
    }
};