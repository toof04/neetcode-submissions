class Solution {
struct node{
    int data;
    vector<node*>next;
    node(int val){
        data = val;

    }
};


public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prereq, vector<vector<int>>& queries) {
                vector<node*>nodevec;

        for(int i = 0; i < numCourses; i++){
            node* temp = new node(i);
            nodevec.push_back(temp); 
        }
        
        for(int i = 0; i < prereq.size(); i++){
            nodevec[prereq[i][0]]->next.push_back(nodevec[prereq[i][1]]); 
        }



        vector<bool>ans;
        if(!queries.size())return {};
      
        for(int i = 0 ; i < queries.size() ;i++){
            int first= queries[i][0];
            int second = queries[i][1];
            node* fir = nodevec[first];
              queue<node*>q;
            q.push(fir);
            bool found = false;
            vector<bool>visited(numCourses, false);
            visited[fir->data] = true;
            while(!q.empty()){

                node* front = q.front();
                    q.pop();  
               for(int j = 0 ; j < front->next.size(); j++){
                if(visited[front->next[j]->data])continue;
                visited[front->next[j]->data] = true;
                if(front->next[j]->data == second){

                    found = true;
                    break;
                }
                else q.push(front->next[j]);
               }
               if(found)break;
            }
            ans.push_back(found);
        }

     
        return ans;
        
    }
};