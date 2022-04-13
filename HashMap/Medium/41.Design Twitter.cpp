//Link: https://leetcode.com/problems/design-twitter/

class Twitter {
public:
    unordered_map<int, unordered_set<int>> follows;
    list<pair<int, int>> tweets;
    
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets.push_front({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        for(auto [x, y]: tweets) {
            if(x == userId or follows[userId].count(x))
                ans.push_back(y);
            if(ans.size() == 10) break;
        }
        
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};