class Solution {
public:
    /*
    Hint: calculate the remaining time that arrive targe.
    Sorted from the starting position, if only one fleet, then the remaining time should be strict
    decreasing
    
    Approach 1. scan from the back
    Approach 2. monothonic stack 
    */
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>>pr;
        for(int i = 0; i < position.size(); i++){
            pr.push_back({position[i], (double)((double)target-(double)position[i])/(double)speed[i]});
        }
        sort(pr.begin(), pr.end(), [](auto &a, auto &b){
            return a.first < b.first;
        });
        
        // approach 1.
        // int rst = 1;
        // double tmp = pr[pr.size()-1].second;
        // for(int i = pr.size()-2; i >= 0; i--){
        //     if(pr[i].second > tmp){
        //         rst++;
        //         tmp =  pr[i].second;
        //     }
        // }
        // return rst;
        
        
        // approach 2.
        stack<double>st;
        for(int i = 0; i < pr.size(); i++){
            while(!st.empty() && st.top() <= pr[i].second){
                st.pop();
            }
            st.push(pr[i].second);
        }
        return st.size();
        
    }
};