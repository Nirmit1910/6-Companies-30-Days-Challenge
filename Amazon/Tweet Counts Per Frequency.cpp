class TweetCounts {
public:
    unordered_map<string,vector<int>>m;
    TweetCounts() {
        m.clear();        
    }
    
    void recordTweet(string tweetName, int time) {
        m[tweetName].push_back(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        if(freq=="minute")
        {
            vector<int>ans((endTime-startTime)/60+1,0);

            for(auto a:m[tweetName])
            {
                if(a<=endTime and a>=startTime)
                {
                    ans[(a-startTime)/60]++;
                }
            }
            return ans;
        }
        else if(freq=="hour")
        {
            vector<int>ans((endTime-startTime)/3600+1,0);

            for(auto a:m[tweetName])
            {
                if(a<=endTime and a>=startTime)
                {
                    ans[(a-startTime)/3600]++;
                }
            }

            return ans;
        }
        else
        {
            vector<int>ans((endTime-startTime)/(24*3600)+1,0);

            for(auto a:m[tweetName])
            {
                if(a<=endTime and a>=startTime)
                {
                    ans[(a-startTime)/(24*3600)]++;
                }
            }
            return ans;
        }
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */