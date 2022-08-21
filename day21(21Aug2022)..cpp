/******************************************************************************
936. Stamping The Sequence
You are given two strings stamp and target. Initially, there is a string s 
of length target.length with all s[i] == '?'.

In one turn, you can place stamp over s and replace every letter in the s 
with the corresponding letter from stamp.

For example, if stamp = "abc" and target = "abcba", then s is "?????" initially.
In one turn you can:
place stamp at index 0 of s to obtain "abc??",
place stamp at index 1 of s to obtain "?abc?", or
place stamp at index 2 of s to obtain "??abc".
Note that stamp must be fully contained in the boundaries of s in order to
stamp (i.e., you cannot place stamp at index 3 of s).
We want to convert s to target using at most 10 * target.length turns.

Return an array of the index of the left-most letter being stamped at each turn.
If we cannot obtain target from s within 10 * target.length turns, return
an empty array.

 

Example 1:

Input: stamp = "abc", target = "ababc"
Output: [0,2]
Explanation: Initially s = "?????".
- Place stamp at index 0 to get "abc??".
- Place stamp at index 2 to get "ababc".
[1,0,2] would also be accepted as an answer, as well as some other answers.
Example 2:

Input: stamp = "abca", target = "aabcaca"
Output: [3,0,1]
Explanation: Initially s = "???????".
- Place stamp at index 3 to get "???abca".
- Place stamp at index 0 to get "abcabca".
- Place stamp at index 1 to get "aabcaca".
*******************************************************************************/
class Solution {
public:
    
    // match two strings along with wildcard character '?'
    // '?' matches with all characters (e.g. abc == a?c)
    bool match(string &a,string &b){
        if(a.length() != b.length()) 
            return false;
        for(int i=0;i<a.length();i++)
            if(a.at(i) != b.at(i) && a.at(i) != '?' && b.at(i) != '?') 
                return false;
        return true;
    }
    
    // check if the string is all wildcard characters
    bool allWild(string &s){
        for(int i=0;i<s.length();i++)
            if(s.at(i) != '?') 
                return false;
        return true;
    }
    
    vector<int> movesToStamp(string stamp, string target) {
        int n = target.length(), m = stamp.length();
        vector<int> ans;
        string str ; 
        bool foundMatch = true;
        
        // loop until no more reverse stamping can be done
        while(foundMatch){ 
            foundMatch = false; // reset flag
            for(int i=0;i<n-m+1;i++){
                str = target.substr(i,m);  // get substr of length m
                
                // if its all windcard no need to stamp
                if(allWild(str)) continue; 
                if(match(stamp,str)){  // match substr with stamp
                    foundMatch = true; // set flag
                    ans.push_back(i); // push the i as match is found
                    // replace all chars of str in target to '?'
                    for(int j=0;j<m;j++) target[i+j] = '?'; 
                }
            }
        }
        
        // base case
        if(!allWild(target))  ans.clear();
        if(ans.size() > 10*n) ans.clear();
        
        // reverse answer as we did the whole procedure in reverse
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};