/******************************************************************************
234. Palindrome Linked List

Given the head of a singly linked list, return true if it is a palindrome.

Example 1:
Input: head = [1,2,2,1]
Output: true

Example 2:
Input: head = [1,2]
Output: false
*******************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> palindrome;
        ListNode *itr=new ListNode;
        itr=head;
        while(itr){
            palindrome.push(itr->val);
            itr=itr->next;
        }
        while(head){
            if(head->val==palindrome.top()){
                palindrome.pop();
            }
            head=head->next;
        }
        return palindrome.empty()?true:false;
    }
};
