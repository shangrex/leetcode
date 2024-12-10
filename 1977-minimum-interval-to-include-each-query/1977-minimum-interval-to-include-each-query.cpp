class Solution {
public:
    /*
    Hint: priority queue

    pq {length}
    */
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        priority_queue<vector<int>> pq;
        vector<int> Q = queries;
        vector<vector<int>> inter = intervals;
        
        // queue to min length
        unordered_map<int, int> rst;

        sort(Q.begin(), Q.end());
        sort(inter.begin(), inter.end());

        int i = 0, n = inter.size();
        for(auto q : Q){
            while(i < n && inter[i][0] <= q){
                // push to pq
                int l = inter[i][0], r = inter[i][1];
                pq.push({-r+l-1, r});
                i++;
            }

            while(pq.size() && pq.top()[1] < q){
                pq.pop();
            }

            if(pq.size() != 0)
                rst[q] = -pq.top()[0];
            else rst[q] = -1;
        }
        vector<int> rst2;
        for(int q : queries){
            rst2.push_back(rst[q]);
        }
        return rst2;
    }
};