//https://leetcode.com/problems/sort-list/

//Approach - Merge sort the list for O(n logn) time and O(1) memory (i.e. constant space) time complexity.

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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* temp = NULL;
        while(fast && fast->next){
           temp = slow;
           slow = slow->next;
           fast = fast->next->next;
        }
        
     
        temp->next = NULL;
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);
        ListNode* ans = merge(l1, l2);
        
        return ans;
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2){
        
        ListNode* res = new ListNode(0);
        ListNode* cur = res;
        while(l1!=NULL && l2!=NULL){
            if(l1 -> val <= l2 -> val){
                cur -> next = l1;
                l1 = l1->next;
            }else{
                cur -> next = l2;
                l2 =  l2->next;
            }
            
            cur = cur->next;
        }
        
        if(l1){
            cur -> next = l1;
            l1 = l1->next;
        }
        
        if(l2){
            cur -> next = l2;
            l2 = l2->next;
        }
        
        return res->next;        
    }
    
};