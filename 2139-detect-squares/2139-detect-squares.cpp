class DetectSquares {
public:
    // unordered_map<pair<int, int>, int> cnt;
    vector<vector<int>> cnt{1010, vector<int>(1010, 0)};
    unordered_map<int , vector<int>>x_data;
    int rst = 0;

    DetectSquares() {

    }
    
    void add(vector<int> point) {
        cout << "add" << endl;
        cnt[point[0]][point[1]] += 1;
        x_data[point[0]].push_back(point[1]);
    }
    
    int count(vector<int> point) {
        int x1 = point[0], y1 = point[1];
        long rst = 0;

        for(auto &y2 : x_data[x1]){
            if(y2 == y1) continue;

            int sidelen = abs(y2 - y1);

            // right
            if(x1+sidelen < 1010)
                rst += cnt[x1+sidelen][y1] * cnt[x1+sidelen][y2];
            
            // left
            if(x1 - sidelen >= 0)
                rst += cnt[x1-sidelen][y1] * cnt[x1-sidelen][y2];
        }
        cout << rst << endl;
        return rst;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */