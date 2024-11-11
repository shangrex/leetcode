class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<int>> map;
        unordered_map<int, set<int>> ex;
        
        for(int i = 0; i < roads.size(); i++){
            map[roads[i][0]].push_back(roads[i][1]);
            ex[roads[i][0]].insert(roads[i][1]);
            ex[roads[i][1]].insert(roads[i][0]);
            map[roads[i][1]].push_back(roads[i][0]);
        }
        int rst = 0;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int size_a = map[i].size();
                int size_b = map[j].size();
                if(ex[i].count(j) > 0) size_a--;
                rst = max(rst, size_a+size_b);
            }
        }
        return rst;
    }
};