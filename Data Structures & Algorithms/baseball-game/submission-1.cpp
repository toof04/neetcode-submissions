class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>s;
        for(string a : operations){
            if(a=="+"){
                if(s.size()<2){cout<<"error";return -1;}
                int t1 = s.top();
                s.pop();
                int t2 = s.top();
                s.pop();
                s.push(t2);
                s.push(t1);
                s.push(t1+t2);
            }
            else if (a=="D"){
                int t1 = s.top();
                s.push(2*t1);
            }
            else if (a=="C"){
                s.pop();
            }
            else{
                s.push(stoi(a));
            }

        }
        int ans = 0;
        while(!s.empty()){
            ans+=s.top();
            s.pop();
        }
        return ans;
    }
};