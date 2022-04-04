//Link: https://leetcode.com/problems/employee-importance/

class Solution {
public:
    unordered_map<int, int> imp;
    unordered_map<int, vector<int>> graph;
    unordered_set<int> vis;
    int importance;
    
    void dfs(int v) {
        if(vis.count(v)) return;
        
        vis.insert(v);
        importance += imp[v];
        
        for(auto u: graph[v]) dfs(u);
    }
    int getImportance(vector<Employee*> employees, int id) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        for(auto x: employees) {
            imp[x->id] = x->importance;
            for(auto i: x->subordinates) 
                graph[x->id].push_back(i);
        }
        
        dfs(id);
        
        return importance;
    }
};
/*
    Definition for Employee.
    class Employee {
    public:
        int id;
        int importance;
        vector<int> subordinates;
    };
*/