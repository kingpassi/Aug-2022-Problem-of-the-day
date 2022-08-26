/******************************************************************************
869. Reordered Power of 2
You are given an integer n. We reorder the digits in any order
(including the original order) such that the leading digit is not zero.

Return true if and only if we can do this so that the resulting number is a power of two.

 

Example 1:

Input: n = 1
Output: true
Example 2:

Input: n = 10
Output: false
*******************************************************************************/
class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        sort(s.begin(),s.end());
		
        vector<string> power;
        for(int i=0;i<=30;i++){
            int p = pow(2,i);
            power.push_back(to_string(p));
        }
        
        for(int i=0;i<=30;i++){
            sort(power[i].begin(),power[i].end());
        }
        
        for(int i=0;i<=30;i++){
            if(power[i] == s ) return true;
        }
        return false;
    }
};