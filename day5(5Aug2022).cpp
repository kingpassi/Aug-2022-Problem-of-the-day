/******************************************************************************
377. Combination Sum IV

Given an array of distinct integers nums and a target integer target, 
return the number of possible combinations that add up to target.

The test cases are generated so that the answer can fit in a 32-bit integer.

 

Example 1:

Input: nums = [1,2,3], target = 4
Output: 7
Explanation:
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.
Example 2:

Input: nums = [9], target = 3
Output: 0
*******************************************************************************/
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1,-1);
        dp[0]=1;
        cs(nums,target,dp);
        return dp[target];
    }
    
    int cs(vector<int>& nums, int target,vector<int>&dp){
        if(dp[target]>-1) return dp[target];
        
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=target)
                count+=cs(nums,target-nums[i],dp);  }
        dp[target]=count;
        return count;
        
        
    }
      
    
};