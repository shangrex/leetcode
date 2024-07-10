class UnionFind {
    public:
    unordered_map<int, int>mp;
    unordered_map<int, int>rank;
    UnionFind(int n ){
        //this.unordered_map<int, int>mp;
        for(int i = 0; i < n; i++){
            mp[i] = i;
        }
    }
    
    bool Join(int a, int b){
        int root_a = Find(a);
        int root_b = Find(b);
        
        if(root_a == root_b){
            // same group
            return false;
        }
        
        if(rank[root_a] >  rank[root_b]){
            mp[root_b] = root_a;
        }
        else if(rank[root_b] > rank[root_a]){
            mp[root_a] = root_b;
        }
        else {
            mp[root_b] = root_a;
            rank[root_a] += 1;
        }
        return true;
    }
    
    int Find(int a){
        if(mp[a] == a) return a;
        else return Find(mp[a]);
    }
};

class Solution {
public:
    
    /*
    Approach 1. Kruskal's
    Cauculate all the edges by its weights and sort in ascending order
    connect the edges if it not have cycles untill all is connect
    
    Approach 2. Prim
    start from a points and connect the smallest distance, make two points to a component
    check the smallest weights that connect to that component and connect
    repeat untill they all connect
    */
    int dist(vector<int>node1, vector<int>node2){
        return abs(node1[0]- node2[0]) + abs(node1[1]-node2[1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        // build all the edges by the distance(weight)
        vector<pair<int, pair<int, int>>> edges;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                edges.push_back({dist(points[i], points[j]), {i , j} });
                // cout << edges.back().first << endl;
            }
        }
        
        // sort the edges with ascending order
        sort(edges.begin(), edges.end());
        
        // construct union group
        UnionFind uf(n);
        
        
        int rst = 0;
        int m = edges.size();
        // connect the edges if it have not have cycles
        for(int i = 0; i < m; i++){
            if(uf.Join(edges[i].second.first, edges[i].second.second)){
                rst += edges[i].first;
            }
        }
        
        return rst;
    }
};