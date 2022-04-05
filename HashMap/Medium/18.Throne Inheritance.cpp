//Link: https://leetcode.com/problems/throne-inheritance/

class ThroneInheritance {
public:
    unordered_map<string, vector<string>> inherit;
    unordered_set<string> dead;
    vector<string> family;
    string king;
    
    ThroneInheritance(string kingName) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        this->king = kingName;    
    }
    
    void birth(string parentName, string childName) {
        inherit[parentName].push_back(childName);
    }
    
    void death(string name) {
        dead.insert(name);
    }
    
    vector<string> getInheritanceOrder() {
        family.clear();
        
        dfs(king);
        return family;
    }
    
    void dfs(string person) {
        if(!dead.count(person))
            family.push_back(person);
        
        for(auto successor: inherit[person])
            dfs(successor);
    }
};