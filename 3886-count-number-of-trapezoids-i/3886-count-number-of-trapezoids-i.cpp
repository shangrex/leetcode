class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        long long MOD = 1e9+7;
        unordered_map<int, long long> group_y;
        
        for(auto &point : points){
            group_y[point[1]] += 1;
        }

        long long total = 0, ret = 0;
        
        for(auto &group : group_y){
            long long count = group.second*(group.second-1)/2;
            //cout << count << endl;
            ret = (ret + count * total) % MOD;
            total = (count + total) % MOD;
        }
        return (int)ret;
    }
};