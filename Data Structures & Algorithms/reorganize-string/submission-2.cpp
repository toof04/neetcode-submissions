class Solution {
public:
    string reorganizeString(string s) {
        map<char,int>freq;
        for(char i : s){
            freq[i]++;
        }
        priority_queue<pair<int,char>>top2;
        for(auto i : freq){
            top2.push({i.second,i.first});
        }
       string ans="";
        while(top2.size()>=2){
            pair<int,char>top1 = top2.top();
            top2.pop();
            pair<int,char>top12 = top2.top();
            top2.pop();
            
        
            top1.first--;
            if(top1.first)top2.push({top1.first,top1.second});
            top12.first--;
            if(top12.first)top2.push({top12.first,top12.second});
                ans+=top1.second;
            
            ans+=top12.second;
        }
        if(!top2.empty()){
            if(top2.top().first>1)return "";
            ans+=top2.top().second;
        }
        return ans;
    }
};