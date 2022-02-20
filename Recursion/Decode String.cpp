//Link: https://leetcode.com/problems/decode-string/
class Solution {
public:
    string decodeString(string s) {
        string ans;
        for(int i = 0; i < s.length();) {
            if(s[i] >= 'a' and s[i] <= 'z') ans += s[i++];
            else if(s[i] >= '1' and s[i] <= '9') {
                int idx = s.find('[', i), lidx = idx + 1;
                int num = stoi(s.substr(i, idx - i)), cnt = 1;
                while(s[lidx] != ']' or cnt != 0) {
                    lidx++;
                    cnt += s[lidx] == '[';
                    cnt -= s[lidx] == ']';
                }
                string t = decodeString(s.substr(idx + 1, lidx - idx - 1));
                for(int j = 0; j < num; ++j) ans += t;
                i = lidx + 1;
            }
        }
        
        return ans;
    }
};