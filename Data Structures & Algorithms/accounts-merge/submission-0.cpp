class Solution {
public:
    void unions(vector<pair<string,int>>&dictionary, int i, int j ){
        for(auto &k : dictionary){

            if(k.second == j){
                k.second = i;
            }
            
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        //map<string,int>dictionary;
            vector<pair<string,int>>dictionary;
            map<int,string>names;
        int k = 0;
        for(auto i : accounts){
            names.insert({k, i[0]});
            for(int j = 1; j<i.size(); j++){
                    dictionary.push_back({i[j],k});

                    }

                    k++;
            }
            
        for(auto i : dictionary){
            for(auto j : dictionary){
                if(i==j)continue;
                if(i.first==j.first){
                    unions(dictionary,i.second,j.second);
                }
            }
        }

   
        set<pair<string,int>>conn;
                 for(auto k : dictionary){
                        conn.insert({k.first,k.second});
        }
              for(auto k : conn){
            cout<<k.first<<"->"<<k.second<<endl;
        }
        cout<<"names : "<<endl;
        for(auto k : names){
            cout<<k.first<<"->"<<k.second<<endl;
        }
        map<int,vector<string>>ma;
        for(auto k : conn){
            ma[k.second].push_back(k.first);
        }

        for(auto i : ma){
            cout<<names[i.first]<<"->";
            for (auto j : i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }

vector<vector<string>>x;
        for(auto i : ma){
            vector<string>temp;
            temp.push_back(names[i.first]);
            for (auto j : i.second){
                temp.push_back(j);
            }
        x.push_back(temp);
        }
        return x;
    }
};