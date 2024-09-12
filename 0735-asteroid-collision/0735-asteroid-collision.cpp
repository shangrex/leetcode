class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(int i = 0; i < asteroids.size(); i++){
            if(asteroids[i] > 0){
                st.push(asteroids[i]);
            }
            else if(!st.empty() && asteroids[i] < 0 && st.top() > 0){
                while(!st.empty()){
                    int t = st.top();
                    if(t == -asteroids[i]){
                        st.pop();
                        break;
                    }
                    if(t < 0){
                        st.push(asteroids[i]);
                        break;
                    }
                    if(t < -asteroids[i]){
                        st.pop();
                        if(st.empty()) {st.push(asteroids[i]);break;}
                    }
                    if(t > -asteroids[i])break;
                }
            }
            else st.push(asteroids[i]);
        }
        
        vector<int>rst;
        while(!st.empty()){
            rst.push_back(st.top());
            st.pop();
        }
        reverse(rst.begin(), rst.end());
        return rst;
    }
};