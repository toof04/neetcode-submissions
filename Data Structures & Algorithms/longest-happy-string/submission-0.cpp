class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>>pq;
        if(a)pq.push({a,'a'});
        if(b)pq.push({b,'b'});
        if(c)pq.push({c,'c'});
        string an = "";
        while(!pq.empty()){
            auto[count1,ch1]=pq.top();
            pq.pop();

            int n  = an.size();
            if(n>=2 and an[n-1]==ch1 and an[n-2]==ch1){
                if(pq.empty())break;
                auto[count2,ch2] = pq.top();
                pq.pop();
                an+=ch2;
                count2--;
                if(count2>0)pq.push({count2,ch2});
                pq.push({count1,ch1});
            }
            else {
                an+=ch1;
                count1--;
                if(count1>0)pq.push({count1,ch1});
            }
        }
        return an;
    }
};