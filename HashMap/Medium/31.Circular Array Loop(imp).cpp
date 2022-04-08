//Link: https://leetcode.com/problems/circular-array-loop/

class Solution {
public:
    int nextIndex(int i, vector<int> nums) {
        i = (i + nums[i] + nums.size()) % nums.size();
        
        return i;
    }
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 0; i < n; ++i) {
            if(!nums[i]) continue;
            
            int slow = i, fast = nextIndex(i, nums);
            
            while(nums[fast] * nums[i] > 0 and nums[nextIndex(fast, nums)] * nums[i] > 0) {
                if(slow == fast) {
                    if(slow == nextIndex(slow, nums)) {
                        break;
                    }
                    return true;
                }
                slow = nextIndex(slow, nums);
                fast = nextIndex(nextIndex(fast, nums), nums);
            }
            
            slow = i;
            int val = nums[i];
            while(nums[slow] * val > 0) {
                int nxt = nextIndex(slow, nums);
                nums[slow] = 0;
                slow = nxt;
            }
        }
        
        return false;
    }
};