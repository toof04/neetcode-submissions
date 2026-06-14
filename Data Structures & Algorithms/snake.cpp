/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void print(deque<pair<int,int>>q){
    while(!q.empty()){
        int currx = q.front().first;
        int curry = q.front().second;
        cout<<"("<<currx<<","<<curry<<") ";
        q.pop_front();
    }
    cout<<endl;
}
int main()
{
    int k;
    cin>>k;
    
    vector<char>moves;
    for(int i = 0;i<k;i++){
        char a;
        cin>>a;
       moves.push_back(a);
    }
    
    int f;
    cin>>f;
    set<pair<int,int>>s;
    for(int i = 0;i<f;i++){
        int a,b;
        cin>>a>>b;
        s.insert({a,b});
    }
    
    deque<pair<int,int>>q;
    q.push_front({0,0});
    for(char ch : moves){
        int currx = q.front().first;
        int curry = q.front().second;
        
        if(ch == 'U' and currx>0){
            currx--;
            curry;
            q.push_front({currx,curry});
            if(s.find({currx,curry})==s.end()){
                q.pop_back();
            }else{s.erase({currx,curry});}
        }
        else if(ch == 'D' and currx<4){
            currx++;
            curry;
            q.push_front({currx,curry});
            if(s.find({currx,curry})==s.end()){
                q.pop_back();
            }else{s.erase({currx,curry});}
        }
        else if(ch == 'L' and curry>0){
            currx;
            curry--;
            q.push_front({currx,curry});
         if(s.find({currx,curry})==s.end()){
                q.pop_back();
            }
            else{s.erase({currx,curry});}
        }
        else if(ch == 'R' and curry<4){
            currx;
            curry++;
            q.push_front({currx,curry});
            if(s.find({currx,curry})==s.end()){
                q.pop_back();
            }
            else{s.erase({currx,curry});}
        }
        else{
            cout<<"Stop";
            break;
        }
        print(q);
    }
        
    
    return 0;
}