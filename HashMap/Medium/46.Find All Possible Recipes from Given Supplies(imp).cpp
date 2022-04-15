//Link: https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/

class Solution {
public:
    unordered_map<string, vector<string>> graf;
    unordered_set<string> vis, canMake, supplies;
    
    bool dfs(string recipe) {
        vis.insert(recipe);
        
        if(supplies.count(recipe)) {
            canMake.insert(recipe);
            return 1;
        }
        if(!graf.count(recipe)) return 0;
        
        int make = 0;
        for(auto x: graf[recipe]) {
            if(!vis.count(x)) {
                vis.insert(x);
                make += dfs(x);
            } else {
                make += canMake.count(x);
            }
        }
        
        if(make == graf[recipe].size()) {
            canMake.insert(recipe);
            return 1;
        }
        return 0;
    }
    
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        this->supplies.insert(supplies.begin(), supplies.end());
        
        for(int i = 0; i < recipes.size(); ++i) {
            for(auto x: ingredients[i]) {
                graf[recipes[i]].push_back(x);
            }
        }    
        
        for(auto x: recipes) {
            if(!vis.count(x)) {
                bool ok = dfs(x);
            }
        }   
        
        vector<string> ans;
        
        for(auto x: recipes) {
            if(canMake.count(x)) ans.push_back(x);
        }
        
        return ans;
    }
};