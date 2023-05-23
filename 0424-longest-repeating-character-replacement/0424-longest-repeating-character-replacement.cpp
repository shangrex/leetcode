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
            // right bound move
            mp[s[right]]++;
            // find the most frequency
            if(max_f < mp[s[right]])max_f = mp[s[right]];
            // left bound move
            if(right-left-max_f+1 > k){
                mp[s[left++]]--;
            }
            // record the result
            rst = max(rst, right-left+1);
        }
        return rst;
    }
};