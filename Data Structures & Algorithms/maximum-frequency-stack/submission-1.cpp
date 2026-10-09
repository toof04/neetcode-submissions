class FreqStack {
public:
    unordered_map<int,int>freq; // character counts
    unordered_map<int,stack<int>>stacks; //stack for every frequency    
    int maxcount = 0;
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val]++;
        int freqval = freq[val];

        stacks[freqval].push(val);
        maxcount = max(maxcount, freqval);
    }
    
    int pop() {
        int res = stacks[maxcount].top();
        freq[stacks[maxcount].top()]--;
        stacks[maxcount].pop();
        if(stacks[maxcount].empty())maxcount--;
        return res;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */