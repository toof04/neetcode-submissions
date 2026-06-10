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
    sort(hash.begin(), hash.end());
        int i,j;
        i=0;
        j=hash.size()-1;
        while(i<=j){
            int mid = i + ((j - i) / 2);
            if(hash[mid]==key)return mid;
            if(hash[mid]>key)j=mid-1;
            else i=mid+1;
        }
        return -1;

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