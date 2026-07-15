class KthLargest {
private :
int kth;
priority_queue<int,vector<int>,less<int>>pq;
public:
    KthLargest(int k, vector<int>& nums) {
        kth = k;
        for(int i : nums){
            pq.push(i);
        }
    }
    
    int add(int val) {
        pq.push(val);
        priority_queue<int,vector<int>,less<int>>temppq;
        temppq = pq;
        int tempk = kth;
        while(--tempk){
            temppq.pop();
        }
        return temppq.top();
    }
};
