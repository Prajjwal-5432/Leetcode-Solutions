//Link: https://leetcode.com/problems/tweet-counts-per-frequency/

class TweetCounts {
public:
    unordered_map<string, vector<int>> ms;
    unordered_map<string, int> cnt;
    
    TweetCounts() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL), cout.tie(NULL);
        
        cnt["minute"] = 60;
        cnt["hour"] = 3600;
        cnt["day"] = 86400;
    }
    
    void recordTweet(string tweetName, int time) {
        ms[tweetName].push_back(time);    
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int slots = (endTime - startTime) / cnt[freq] + 1;
        
        vector<int> ans(slots, 0);
        
        for(auto time: ms[tweetName]) {
            if(time >= startTime and time <= endTime) 
                ans[(time - startTime) / cnt[freq]]++;
        }
        
        return ans;
    }
};