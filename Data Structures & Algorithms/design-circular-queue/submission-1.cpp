class MyCircularQueue {
private:
 struct Node; 
    int limit;
    int curr;
    Node* head;
    Node* rear;
    Node* front;


struct Node{
    int val;
    Node* next;
    Node(){
        val = 0;
        next = nullptr;
    }
    Node(int valu){
        val = valu;
        next = nullptr;
        }
    Node(int valu, Node* point){
        val = valu;
        next = point;
    }    
};
public:
    MyCircularQueue(int k) {
        head = new Node() ;
        rear = head;
        front = head;
        limit  = k;
        curr = 0;
    }
    
    bool enQueue(int val) {
        if(isFull())return false;
        Node* temp = new Node(val);
        if(isEmpty())front=rear=temp;
        else{rear->next = temp;
        rear = temp;}
        curr++;
        return true;
    }
    
    bool deQueue() {
       //remove first not last
       if(isEmpty())return false;
       Node* frontdelete = front;
       front=front->next;
       delete frontdelete;
        curr--;
        return true;
    }
    
    int Front() {
                if (isEmpty()) return -1;

        return front->val;
    }
    
    int Rear() {
                if (isEmpty()) return -1;

        return rear->val;
    }
    
    bool isEmpty() {
        return curr==0;
    }
    
    bool isFull() {
        return curr==limit;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */