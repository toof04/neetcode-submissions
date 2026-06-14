class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
         stack<int>s;
         if(asteroids.size()>0)s.push(asteroids[0]);
         for(int i = 1;i<asteroids.size();i++){
                bool abroke = false;

                if (asteroids[i]<0 and !s.empty() and s.top()>0) {
                    
                    while(!s.empty() and s.top()>0 ){
                    if(abs(asteroids[i]) > abs(s.top())){s.pop();}
                    else if(abs(asteroids[i]) == abs(s.top())){s.pop();abroke = true;break;}
                    else {abroke = true;break;}
                    }
                    
                }

                if(!abroke) s.push(asteroids[i]);

            }
        stack<int>s1;
        while(!s.empty()){
            s1.push(s.top());
            s.pop();
        } 
        vector<int>ans;
                while(!s1.empty()){
            ans.push_back(s1.top());
            s1.pop();
        } 
        return ans;
    }
};