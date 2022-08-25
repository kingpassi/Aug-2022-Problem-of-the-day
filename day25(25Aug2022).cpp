/******************************************************************************
383. Ransom Note
Given two strings ransomNote and magazine, return true if ransomNote can be
constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

 

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true
*******************************************************************************/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        unordered_map<char, int> rm;
        unordered_map<char, int> mz;
        
        for(auto x: ransomNote) rm[x]++;
        for(auto x: magazine) mz[x]++;
        
        for(auto x : rm)
        {
            if(mz[x.first]<x.second)
                return false;
        }
        return true;
     }
};