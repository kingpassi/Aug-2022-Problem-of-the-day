/******************************************************************************
1338. Reduce Array Size to The Half

You are given an integer array arr. You can choose a set of integers 
and remove all the occurrences of these integers in the array.

Return the minimum size of the set so that at least half of the integers
of the array are removed.

Example 1:
Input: arr = [3,3,3,3,5,5,5,2,2,7]
Output: 2
Explanation: Choosing {3,7} will make the new array [5,5,5,2,2]
which has size 5 (i.e equal to half of the size of the old array).
Possible sets of size 2 are {3,5},{3,2},{5,2}.
Choosing set {2,7} is not possible as it will make the new array 
[3,3,3,3,5,5,5] which has a size greater than half of the size of the old array.

Example 2:
Input: arr = [7,7,7,7,7,7]
Output: 1
Explanation: The only possible set you can choose is {7}. 
This will make the new array empty.
*******************************************************************************/
class Solution {
public:
    //storing value in the map to get the freq of the element of the array
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]]++;
        }
        //storing the freq in vector so that we can easily access highest
        //freq by sorting the  vector
        vector<int> freq;
        int sum=0;
        for(auto x:m){
            freq.push_back(x.second);
            sum+=x.second;
        }
       int size=sum;
       int count=0;
    sort(freq.begin(),freq.end());
        
        //we are using loop till at least half of the integers of the
        //array are removed.
        while(size>(sum/2)){
            size=size-freq.back();
           freq.pop_back();
        //we are storing the count of element that are removed
             count++;
            
        }
       
        return count;
    }
};