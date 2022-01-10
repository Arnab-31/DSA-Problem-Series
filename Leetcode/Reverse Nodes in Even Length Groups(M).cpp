//https://leetcode.com/problems/reverse-nodes-in-even-length-groups/

class Solution {
public:
   
    ListNode* reverseList(ListNode* cur, int n) {
    ListNode *start = cur, *prev = nullptr;
    while (--n >= 0) {
        swap(cur->next, prev);
        if (--n >= 0)
            swap(prev->next, cur);
    }
    start->next = cur;
    return prev;
}  
ListNode* reverseEvenLengthGroups(ListNode* head) {
    int group = 2, cnt = 0;  
    auto *start = head, *p = head->next;
    while (p != nullptr) {
        if (++cnt == group) { // when we are at the beginning of a new group
            if (group % 2 == 0) {  
                p = start->next;
                start->next = reverseList(start->next, cnt);   //if even group revese list
            }
            start = p; 
            cnt = 0;
            ++group;
        }
        p = p->next;
    }
    if (cnt % 2 == 0 && start->next != nullptr)
        start->next = reverseList(start->next, cnt);
    return head;
}
};