class StockSpanner {
public:
     stack<int>s;

    StockSpanner() {

    }
    
    int next(int price) {
        if(s.empty()){
            s.push(price);
            return 1;}
            stack<int>oldprices;
            int ans = 1;
        while (!s.empty() and s.top() <= price  ){
            oldprices.push(s.top());
            s.pop();
            ans++;
        }
        while(!oldprices.empty()){
            s.push(oldprices.top());
            oldprices.pop();
        }
                    s.push(price);

        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */