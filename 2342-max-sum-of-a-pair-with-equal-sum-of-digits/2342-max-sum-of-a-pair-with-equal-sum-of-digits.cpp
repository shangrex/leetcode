class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, priority_queue<int>> mp;

        for(auto &num : nums){
            int tNum = num;
            int sumDigit = 0;
            while(num > 0){
                sumDigit += num%10;
                num /= 10;
            }
            mp[sumDigit].push(tNum);
        }

        int ret = -1;
        for(auto i : mp){
            int x = i.second.top();
            i.second.pop();
            if(i.second.empty()) continue;
            int y = i.second.top();
            i.second.pop();
            ret = max(ret, x + y);
        }
        return ret;
    }
};