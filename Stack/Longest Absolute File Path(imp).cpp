//Link: https://leetcode.com/problems/longest-absolute-file-path/
//Refer: https://leetcode.com/problems/longest-absolute-file-path/discuss/1241061/C%2B%2B-Easiest-O(n)-solution-with-explanation-Beats-100-0ms
class Solution {
public:
    int lengthLongestPath(string input) {
        string data;
        stringstream ss(input);
        
        unordered_map<int, int> len;
        
        int mxlen = 0;
        
        while(getline(ss, data, '\n')) {
            int tabs = 0;
            
            while(data[tabs] == '\t') tabs++;
            
            if(tabs == 0) len[tabs] = data.size();
            else len[tabs] = len[tabs - 1] + 1 + data.substr(tabs).size();
            
            if(data.find('.') != string::npos) mxlen = max(mxlen, len[tabs]);
        }
        
        return mxlen;
    }
};