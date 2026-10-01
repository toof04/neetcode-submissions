class MedianFinder {
public:
priority_queue<int>leftmaxheap;
priority_queue<int,vector<int>,greater<int>>rightminheap;
int totalsize = 0;
//leftmaxheap top and rightminheap top will always have the middle elements
    MedianFinder() {
    }
    
    void addNum(int num) {
        totalsize++;
       
       //push in left when we are starting or the num belong to left half
       if(leftmaxheap.empty() or num < leftmaxheap.top()){
        leftmaxheap.push(num);
       }else rightminheap.push(num);

        // if the heaps size differ by more than 1 then put it into another heap
       if(leftmaxheap.size() > rightminheap.size() + 1){
        rightminheap.push(leftmaxheap.top());
        leftmaxheap.pop();
       }else if(rightminheap.size() > leftmaxheap.size()){
        leftmaxheap.push(rightminheap.top());
        rightminheap.pop();
       }

    }
    
    double findMedian() {
        int length = totalsize;
        
    if (length % 2) {
        return leftmaxheap.top();
    }

    return (leftmaxheap.top() + rightminheap.top()) / 2.0;
    }
};
