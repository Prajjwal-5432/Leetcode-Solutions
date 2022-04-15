//Link: https://leetcode.com/problems/alphabet-board-path/

class Solution {
public:
    string alphabetBoardPath(string target) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL), cout.tie(NULL);
        
        string mp[26][26];
        
        for(char x = 'a'; x <= 'z'; ++x) {
            for(char y = 'a'; y <= 'z'; ++y) {
                if(y == 'z' and x != 'z') {
                    mp[x - 'a'][y - 'a'] = mp[x - 'a']['u' - 'a'] + 'D';
                    continue;
                }
                
                array<int, 2> point1 = {(x - 'a') / 5, (x - 'a') % 5};
                array<int, 2> point2 = {(y - 'a') / 5, (y - 'a') % 5};
                
                int disx = point1[1] - point2[1], disy = point1[0] - point2[0];
                
                string path;
                if(disy <= 0) {
                    path += string(abs(disy), 'D');
                } else {
                    path += string(abs(disy), 'U');
                }
                
                if(disx <= 0) {
                    path += string(abs(disx), 'R');
                } else {
                    path += string(abs(disx), 'L');
                }
                mp[x - 'a'][y - 'a'] = path;
            }
        }
        
        char c = 'a';
        string ans;
        
        for(int i = 0; i < target.length(); ++i) {
            ans += mp[c - 'a'][target[i] - 'a'] + "!";
            c = target[i];
        }
        
        return ans;
    }
};