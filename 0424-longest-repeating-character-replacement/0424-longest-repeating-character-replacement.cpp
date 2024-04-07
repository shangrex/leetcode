class Solution {
public:
    int characterReplacement(string s, int k) {
        // AABCAA
        // 
        unordered_map<char, int> mp;
        int maxL = 0, maxC = 0, left = 0, right = 0;
        // k = 2
        // AABCDAA
        // 1 -> A mp[A] = 1 , maxC = 0 -> 1
        // 2 -> AA mp[A] = 2 , maxC = 1 -> 2
        // 3 -> AAB mp[A] = 2, mp[B] = 1 1 < 2  , maxC = 2
        // 4 -> AABC mp[A] = 2, mp[B] = 1, mp[C] = 1 1 < 3 , maxC = 2
        // 5 -> AABCD mp[A] = 2, mp[B] = 1, mp[C] = 1, mp[D] = 1,  
        for (; right < s.size(); right++)
        {
            maxC = max(maxC, ++mp[s[right]]);
            while (left <= right && right - left + 1 - maxC > k)
            {
                mp[s[left++]]--;
                for (const auto& p : mp)    maxC = max(maxC, p.second);
            }
            maxL = max(maxL, right - left + 1);
        }
        return maxL;
    }
};