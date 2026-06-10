class MyHashSet {
private:
    vector<int>hash;

public:
    MyHashSet() {
    }
    
    void add(int key) {
       int ind =  findindex(key);
       
       if(ind==-1) hash.push_back(key);
    }
    
    int findindex(int key){
        auto it = find(hash.begin(), hash.end(), key);
        if(it==hash.end())return -1;
        return distance(hash.begin(),it);
    }
    

    void remove(int key) {
        int ind = findindex(key);
        if(ind!=-1)
            hash.erase(hash.begin()+ind);
    }
      
    
    bool contains(int key) {
        int ind = findindex(key);
        if(ind==-1)return false;
        return true;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */