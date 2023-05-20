class Solution {
public:
    /*
    approach 1
    The problem says that we can make at most k changes to the string (any character can be replaced with any other character). So, let's say there were no constraints like the k. Given a string convert it to a string with all same characters with minimal changes. The answer to this is

length of the entire string - number of times of the maximum occurring character in the string

Given this, we can apply the at most k changes constraint and maintain a sliding window such that

(length of substring - number of times of the maximum occurring character in the substring) <= k
    */
    int characterReplacement(string s, int k) {
        int rst = 0, max_f = 0, right = 0, left = 0;
        char tmp;
        unordered_map<char, int>mp;
        for(int right = 0; right < s.length(); right++){
            mp[s[right]]++;
            max_f = 0;
            for(auto i : mp)max_f = max(i.second, max_f);
            if(right-left-max_f+1 > k){
                mp[s[left]]--;
                left++;
            }
            rst = max(rst, right-left+1);
        }
        return rst;
    }
};