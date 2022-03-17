//Find the center of the linked list , in O(N) time and 0(1) space. Just with one iteration.

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int main() {
    ListNode* fast = head;
    ListNode* slow = head;
    ListNode* temp = NULL;

    while(fast && fast->next){
        temp = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    //temp refers to the node in the middle
    //slow refers to the node next to the middle
}
