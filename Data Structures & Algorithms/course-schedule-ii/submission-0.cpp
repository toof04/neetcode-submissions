class Solution {

struct node{
    int data;
    int innodes;
    int outnodes;
    vector<node*>next;
    node(int val){
        data = val;
        innodes = 0;
        outnodes = 0;
    }
};

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prereq) {
        vector<node*>nodevec;
        for(int i = 0; i < numCourses; i++){
            node* temp = new node(i);
            nodevec.push_back(temp); 
        }
        
        for(int i = 0; i < prereq.size(); i++){
            nodevec[prereq[i][0]]->innodes++;
            nodevec[prereq[i][1]]->outnodes++;
            nodevec[prereq[i][1]]->next.push_back(nodevec[prereq[i][0]]); 
        }


        queue<node*>zeroInnodes;
        for(int i = 0; i < nodevec.size(); i++){
            if(nodevec[i]->innodes == 0 )zeroInnodes.push(nodevec[i]);
        }
        int done = 0;
        vector<int>ans;
        if(!zeroInnodes.size())return {};
        while(!zeroInnodes.empty()){
            node* front = zeroInnodes.front();
            ans.push_back(front->data);
            if(front->next.size()){
               
                front->outnodes-=front->next.size();
                 for(int i = 0; i<front->next.size();i++){
                    node* n = front->next[i];
                    n->innodes--;
                    if (n->innodes == 0)zeroInnodes.push(n);
                 }
            }

            if(front->innodes == 0)done++;
            zeroInnodes.pop();
        }
        if(done >= numCourses)return ans;
        return {};







    }
};
