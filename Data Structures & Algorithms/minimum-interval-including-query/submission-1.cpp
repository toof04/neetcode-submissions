class Solution {
public:

struct Compare{
    bool operator()(vector<int>& a, vector<int>&b){
        if(a[0]==b[0])return a[1]>b[1];
        return a[0] > b[0];
    }
};

    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        //sort intervals based on start
        sort(intervals.begin(), intervals.end());
        
        //creating a seperate vector and map as we'd need to bring the queries in order for result
        vector<int>sortedQueries = queries;
        sort(sortedQueries.begin(), sortedQueries.end());

        map<int,int>res;

        priority_queue<vector<int>,vector<vector<int>>, Compare>pq;
        //minheap based on length, end

        int i = 0;

        for(int q : sortedQueries){
            
            //push into pq the intervals whose starting times are less than q
            while( i < intervals.size() and intervals[i][0] <= q){
                pq.push({intervals[i][1] - intervals[i][0] + 1, intervals[i][1]});
                i++;
            }

            //remove elements from pq whose ending times are lesser than q
            while(!pq.empty() and pq.top()[1]<q){
                pq.pop();
            }

            //the top will now have the interval with least size, push the size into answer
            res[q] = pq.empty() ? -1:pq.top()[0];

        }

        vector<int>results;
        for(int j = 0; j< queries.size(); j++){
            results.push_back(res[queries[j]]);
        }
        return results;


    }
};
