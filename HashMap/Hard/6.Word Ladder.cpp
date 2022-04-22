//Link: https://leetcode.com/problems/word-ladder/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        
        unordered_map<string, int> dis;
        
        queue<string> q;
        q.push(beginWord);
        
        unordered_set<string> vis;
        vis.insert(beginWord);
        dis[beginWord] = 1;
        
        while(!q.empty()) {
            string v = q.front();
            q.pop();
            
            for(int i = 0; i < v.size(); ++i) {
                for(char x = 'a'; x <= 'z'; ++x) {
                    if(v[i] == x) continue;
                    
                    string s = v;
                    s[i] = x;
                    
                    if(words.count(s) and !vis.count(s)) {
                        dis[s] = dis[v] + 1;
                        q.push(s);
                        vis.insert(s);
                    }
                }
            }
        }
        
        return dis[endWord];
    }
};