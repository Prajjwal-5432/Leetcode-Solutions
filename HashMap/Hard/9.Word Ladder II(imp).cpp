//Link: https://leetcode.com/problems/word-ladder-ii/

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> mp;
        
        for(auto x: wordList) {
            mp[x] = INT_MAX;
        }
        
        mp[beginWord] = 0;
        vector<vector<string>> ans;
        
        queue<pair<string, vector<string>>> q;
        
        q.push({beginWord, {beginWord}});
        
        while(!q.empty()) {
            string last = q.front().first;
            vector<string> path = q.front().second;
            
            q.pop();
            
            if(last == endWord) {
                ans.push_back(path);
                continue;
            }
            
            for(int i = 0; i < last.size(); ++i) {
                string news = last;
                for(char x = 'a'; x <= 'z'; ++x) {
                    news[i] = x;
                    if(last[i] == x) continue;
                    if(mp[news] < path.size()) continue;
                    
                    mp[news] = path.size();
                    path.push_back(news);
                    
                    q.push({news, path});
                    
                    path.pop_back();
                }
            }
        }
        
        return ans;
    }
};