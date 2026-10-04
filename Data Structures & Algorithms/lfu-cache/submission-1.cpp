class LFUCache {
public:
    struct Node{
        int key;
        int val;
        int freq = 0;
        Node* prev = nullptr;
        Node* next = nullptr;
        Node(int key, int val){
            this->key = key;
            this->val = val;
        }
        Node(){
            key = -1;
            val = -1;
            freq = 0;
            prev = next = nullptr;
        }
    };

    struct List{
        Node* head;
        Node* tail;
        List(){
            head = new Node();
            tail = new Node();
            head->next = tail;
            tail->prev = head;
        }
        bool empty(){
            return head->next == tail;
        }
    };


    int size = 0;
    int capacity = 0;
    int leastfreq = 0;
    
    unordered_map<int, List*>freqtolist;
    unordered_map<int, Node*>key2node;

    void remove(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insert(Node* node, int freq){ //inserting at the front, after head
        if(freqtolist.find(freq)==freqtolist.end()){
            freqtolist[freq] = new List();
        }
        List* list = freqtolist[freq];
        node->next = list->head->next;
        node->prev = list->head;

        list->head->next->prev = node;
        list->head->next = node;
        node->freq = freq;
    }

    void increasefrequency(Node* node){
        int oldfreq = node->freq;
        int newfreq = oldfreq + 1;
        remove(node);
        insert(node, newfreq);
        if(oldfreq == leastfreq){
            if(freqtolist[oldfreq]->empty()){ // main logic to handle least freq
                leastfreq++;
            }
        }
    }


    LFUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(key2node.find(key)==key2node.end())return -1;

        Node* node = key2node[key];
        increasefrequency(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(capacity==0)return;
        if(key2node.find(key)!=key2node.end()){
                Node* node = key2node[key];
                node->val = value;
                increasefrequency(node);
                return;
        }
        if(size == capacity){
            List* list = freqtolist[leastfreq];
            Node* victim = list->tail->prev;
            remove(victim);
            key2node.erase(victim->key);
            delete victim;
            size--;
        }
        Node* node = new Node(key, value);
        key2node[key] = node;
        insert(node,1);
        leastfreq = 1;
        size++;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */