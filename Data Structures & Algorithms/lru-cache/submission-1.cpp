class LRUCache {
public:
class Node{
    public:
        int key;
        int value = 0;
        Node* left = nullptr;
        Node* right = nullptr;   
};

void remove(Node* val){
    cache.erase(val->key);
    val->left->right = val->right;
    val->right->left = val->left;
    delete val;
    size--;
}    

void insert(int key, int val){
    Node* newnode = new Node();
    newnode->key = key;
    newnode->value = val;
    if(size==capacity){
        Node* lru = head->right;
        remove(lru);
    }
        Node* last = tail->left;
        last->right = newnode;
        newnode->left = last;
        newnode->right = tail;
        tail->left = newnode;
        size++;
        cache[key] = newnode;
    
}


int capacity = 0;
int size = 0;
unordered_map<int,Node*>cache;
Node* head;
Node* tail;
Node* end;
    LRUCache(int capa) {
        capacity = capa;
        head = new Node();
        tail = new Node();
        head ->right = tail;
        tail->left = head;

    }
    
    int get(int key) {
        if(cache.find(key)!=cache.end()){//found
            Node* val = cache[key];
            int value = val->value;
            remove(val);
            insert(key,value);
            return value;
        }
        else{//not found
            return -1;
        }
    }
    
    void put(int key, int value) {

        if(cache.find(key)!=cache.end()){
            Node* val = cache[key];
            remove(val);
            insert(key, value);
        }
        else{
            insert(key, value);
        }
    }
};
