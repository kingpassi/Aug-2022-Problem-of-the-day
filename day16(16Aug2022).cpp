/******************************************************************************
387. First Unique Character in a String

Given a string s, find the first non-repeating character in it 
and return its index. If it does not exist, return -1.

Example 1:
Input: s = "leetcode"
Output: 0

Example 2:
Input: s = "loveleetcode"
Output: 2

Example 3:
Input: s = "aabb"
Output: -1
*******************************************************************************/
class Solution {
public:
    int firstUniqChar(string s) {
        map<char,int>m;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }
        for(int j=0;j<s.size();j++){
           if(m[s[j]]==1)  return j;
        }
        return -1;
    }
};