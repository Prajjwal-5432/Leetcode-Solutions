//Link: https://leetcode.com/problems/max-chunks-to-make-sorted/
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        
        int sum = 0, chunks = 0;
        
        for(int i = 0; i < n; ++i) {
            sum += arr[i];
            chunks += sum == (i * (i + 1)) / 2;
        }
        
        return chunks;
    }
};