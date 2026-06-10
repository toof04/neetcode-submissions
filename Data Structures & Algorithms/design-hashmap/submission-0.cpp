class MyHashMap {
private:
    vector<pair<int,int>> hash;
public:
    MyHashMap() {
    }
    
    void put(int key, int value) {
        remove(key);
        hash.push_back(make_pair(key,value));
    }
    
    int get(int key) {
        for(int i = 0; i<hash.size();i++){
            if(key==hash[i].first)return hash[i].second;
        }
        return -1;
    }
    
    void remove(int key) {
           for (auto it = hash.begin(); it != hash.end(); ++it) {
            if (it->first == key) {
                hash.erase(it);
                return;
            }
    }}
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */