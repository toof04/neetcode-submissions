class Twitter {
private:
    priority_queue<pair<int,vector<int>>>tweets;//time , <tweetID,userId> 
    map<int,set<int>>userFollowing; //userId,set they follow
    int time = 0;
public:
    Twitter() {
    }
    
    void postTweet(int userId, int tweetId) {
       vector<int>temp={tweetId,userId};
        tweets.push({time++,temp});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>ans;
        priority_queue<pair<int,vector<int>>>temp = tweets;
        int n = 10;
        while(!temp.empty() and n){
            vector<int> tweettop = temp.top().second;
            temp.pop();
            if(tweettop[1] == userId or userFollowing[userId].count(tweettop[1])){
                n--;
                ans.push_back(tweettop[0]);
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        userFollowing[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        userFollowing[followerId].erase(followeeId);
    }
};
