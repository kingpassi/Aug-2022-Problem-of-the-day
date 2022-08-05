/******************************************************************************
378. Kth Smallest Element in a Sorted Matrix
Given an n x n matrix where each of the rows and columns is sorted in 
ascending order, return the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the
kth distinct element.

You must find a solution with a memory complexity better than O(n2).

 

Example 1:

Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], 
and the 8th smallest number is 13
Example 2:

Input: matrix = [[-5]], k = 1
Output: -5
*******************************************************************************/
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int m=matrix[0].size();
        priority_queue<int>pq;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pq.size()<k){
                pq.push(matrix[i][j]);
              
                }
                
                else{
                    if(matrix[i][j]<pq.top()){
                        pq.pop();
                    pq.push(matrix[i][j]);
                     
                    }
                   
                }
            }
        }
        return pq.top();
    }
};
