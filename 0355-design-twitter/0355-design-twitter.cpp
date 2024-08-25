class Twitter {
private:
    unordered_map<int, vector<pair<int,int>>>user_post;
    unordered_map<int, vector<int>>follows;
    long long time;    
public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        // user_post[userId].insert(user_post[userId].begin(),tweetId);
        pair<int, int> t = {time++, tweetId};
        //cout << "add" << userId << " " << t.second << endl;
        user_post[userId].push_back(t);
        // follow itself
        if(follows.find(userId) == follows.end())follows[userId].push_back(userId);
    }
    
    vector<int> getNewsFeed(int userId) {
        
        vector<int>rst;
        priority_queue<pair<int, int>> p;
  
        // search the selected follower to see the followee
        for(auto follower : follows[userId]){
            cout << userId << " " << follower<< endl;
            // add all the followee post
            for(auto post : user_post[follower]){
                //cout << post.first << " " << post.second << endl;
                p.push(post);
            }
        }
        
        int rst_limit = 0;
        while(!p.empty() && rst_limit < 10){
            pair<int, int>t = p.top();
            //cout << t.first << " " << t.second << endl;
            rst.push_back(t.second);
            p.pop();
            rst_limit++;
        }
        return rst;
    }
    
    void follow(int followerId, int followeeId) {
        if(follows.find(followerId) == follows.end())follows[followerId].push_back(followerId);
        
        for(auto followee : follows[followerId]){
            if(followee == followeeId) return;
        }
        follows[followerId].push_back(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(follows.find(followerId) != follows.end()){
            for(int i = 0; i < follows[followerId].size(); i++){
                if(follows[followerId][i] == followeeId){
                    follows[followerId].erase(follows[followerId].begin()+i);
                }
            }
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */