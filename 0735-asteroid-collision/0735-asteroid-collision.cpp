class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for (int asteroid : asteroids)
        {
            // ans: 24, 5, 10, -15
            while (asteroid < 0 && !ans.empty() && ans.back() > 0 && ans.back() < -asteroid)
                ans.pop_back();
            // ans: 24

            // ans: 15, -15
            if (asteroid < 0 && !ans.empty() && ans.back() && ans.back() == -asteroid)
                ans.pop_back();
            else if (ans.empty() || asteroid > 0 || ans.back() < 0)
                ans.push_back(asteroid);
        }
        return ans;
    }
};