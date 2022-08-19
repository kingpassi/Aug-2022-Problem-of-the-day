/******************************************************************************
659. Split Array into Consecutive Subsequences

You are given an integer array nums that is sorted in non-decreasing order.

Determine if it is possible to split nums into one or more subsequences 
such that both of the following conditions are true:

Each subsequence is a consecutive increasing sequence (i.e. each integer is 
exactly one more than the previous integer).
All subsequences have a length of 3 or more.
Return true if you can split nums according to the above conditions, or false
otherwise.

A subsequence of an array is a new array that is formed from the original 
array by deleting some (can be none) of the elements without disturbing the
relative positions of the remaining elements. (i.e., [1,3,5] is a subsequence
of [1,2,3,4,5] while [1,3,2] is not).

 

Example 1:

Input: nums = [1,2,3,3,4,5]
Output: true
Explanation: nums can be split into the following subsequences:
[1,2,3,3,4,5] --> 1, 2, 3
[1,2,3,3,4,5] --> 3, 4, 5
Example 2:

Input: nums = [1,2,3,3,4,4,5,5]
Output: true
Explanation: nums can be split into the following subsequences:
[1,2,3,3,4,4,5,5] --> 1, 2, 3, 4, 5
[1,2,3,3,4,4,5,5] --> 3, 4, 5
Example 3:

Input: nums = [1,2,3,4,4,5]
Output: false
Explanation: It is impossible to split nums into consecutive increasing
subsequences of length 3 or more.
*******************************************************************************/
class Solution {
public:
    //app 1: using greedy approach in O(N) 
    
/* for each num in nums first try placing it in one of the existing subseq.
if no subseq. needs that number.
then, try creating a new subseq. of atleast length 3 starting with that num.

if neither of the two condtn is true, we return false
since, that num can't be a part of any subseq.

*/
    bool isPossible(vector<int>& nums) {
        //freq. map denotes no. of elements left to be placed in subseq.
        unordered_map<int,int> freq;
        for(int x: nums) freq[x]++;
        
        //hypothetical map which denotes the "next" number req. by subsequences.
        unordered_map<int,int> need;
        
        for(int n: nums){
            //all occurences of cur num is already taken
            if(freq[n] == 0) continue;
            
            if(need[n] > 0){ // "n" can be a part of some existing subseq.
                need[n]--;
                freq[n]--;
                
                need[n+1]++; //next req. num is now "N+1"
            }
            
            //try creating a new sub. of length atleast three
            else if(freq[n]>0 && freq[n+1]>0 && freq[n+2]>0){
                freq[n]--;
                freq[n+1]--;
                freq[n+2]--;
                
                //next num needed in subseq.
                need[n+3]++;
            }
            
            //above both condtn is false
            else{
                return false;
            }
        }
        
        return true;
    }
};