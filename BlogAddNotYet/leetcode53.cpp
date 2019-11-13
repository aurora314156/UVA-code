class Solution {
public:
    
    int maxSubArray(vector<int>& nums) {
        
        int sum = 0, curMax = INT_MIN;
        
        for(int n = 0; n < nums.size(); ++n){
            
            sum = max(nums[n], sum + nums[n]);
            curMax = max(sum, curMax);
        }
        
        return curMax;
    }
};