class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> pq;
        for(auto & point : points){
            int distance = point[0]*point[0] + point[1]*point[1];
            pq.push({distance, point});
        }
        
        vector<vector<int>> rst;
        for(int i = 0; i < k; i++){
            pair<int, vector<int>> p = pq.top();
            pq.pop();
            rst.push_back(p.second);
        }
        return rst;
    }
};