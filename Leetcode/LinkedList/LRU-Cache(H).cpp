//https://leetcode.com/problems/lru-cache/

//Approach - https://www.youtube.com/watch?v=xDEuM5qa0zg&ab_channel=takeUforward



struct Node{
    int key;
    int val;
    Node* next;
    Node* prev;
    
    Node(){
        key = 0;
        val = 0;
        next = NULL;
        prev = NULL;
    }
};
class LRUCache {
public:
    Node* head;
    Node* tail;
    unordered_map<int, Node*>mp;
    int cap;
    LRUCache(int capacity) {
        head = new Node();
        tail = new Node();
        head -> next = tail;
        tail -> prev = head;
        cap = capacity;
    }
    
    
    int get(int key) {
        if(!mp.count(key)) return -1;
        Node* a = mp[key];
        int val = a->val;
        makeRecent(a);
        return val;
    }
    
    void put(int key, int value) {
        
        if(mp.count(key)){
            deleteNode(mp[key]);
        }
        
        if(mp.size() >= cap){
            deleteLeastUsed();
        }
        
        Node* newNode = new Node();
        newNode->key =  key;
        newNode->val = value;
        mp[key] = newNode;        
        
        Node* d = head->next;
        head->next = newNode;
        newNode->prev = head;
        newNode->next = d;
        d->prev = newNode; 
    }
    
    void deleteLeastUsed(){
        Node* a  = tail->prev;
        Node* b =  tail->prev->prev;
        int k = a->key;
        mp.erase(k);
        tail->prev = b;
        b -> next = tail;
    }
    
    void deleteNode(Node* a){
        Node* b = a->prev;
        Node* c = a->next;
        b->next = c;
        c->prev = b;
        mp.erase(a->key);
    }
    
    void makeRecent(Node* a){
        Node* b = a->prev;
        Node* c = a->next;
        b->next = c;
        c->prev = b;
        
        Node* d = head->next;
        head->next = a;
        a->prev = head;
        a->next = d;
        d->prev = a;   
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */