class Solution {
public:
    // open stack
    // if empty & negative push
    // not 
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>rst;
        for(int i = 0; i < asteroids.size(); i++){
            if(asteroids[i] > 0 || rst.empty() || rst.back() < 0)rst.push_back(asteroids[i]);
            else {
                // input is negative and rst.back > 0
                while(true){
                    // cout << rst.back() << " " << asteroids[i] << endl;
                    if(rst.empty()){
                        rst.push_back(asteroids[i]);
                        break;
                    }
                    else if(rst.back() < 0){
                        rst.push_back(asteroids[i]);
                        break;
                    }
                    else if(rst.back() == -asteroids[i]) {
                        rst.pop_back();
                        break;
                    }   
                    else if(rst.back() > -asteroids[i]){
                        break;
                    }
                    else {
                        rst.pop_back();
                    }
                }
            }
        }
        return rst;
    }
};