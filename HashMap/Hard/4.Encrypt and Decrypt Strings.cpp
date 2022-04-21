//Link: https://leetcode.com/problems/encrypt-and-decrypt-strings/

class Encrypter {
public:
    unordered_map<string, int> dict;
    unordered_map<char, string> match;
    
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        for(int i = 0; i < keys.size(); ++i)
            match[keys[i]] = values[i];
        
        for(auto x: dictionary) {
            dict[encrypt(x)]++;
        }
    }
    
    string encrypt(string word1) {
        string s;
        for(auto x: word1) {
            if(!match.count(x)) return "";
            s += match[x];
        }
        return s;
    }
    
    int decrypt(string word2) {
        return dict[word2];
    }
};