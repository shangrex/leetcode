class Solution {
public:
    /*
    approach 1 sliding windows
    optimize method 2 record the left boundary
    */
    int lengthOfLongestSubstring(string s) {
  unordered_map<char, int> substr; // char, count
  int left = 0, right = 0;
  int ans = 0;
  while(right < s.size()) {
    char c = s[right];
    right++;
    substr[c]++;
    
    // make sure it is valid
    while(substr[c] > 1) {
      char c2 = s[left];
      substr[c2]--;
      left++;
    }
    
    ans = max(ans, right - left);
  }
  return ans;
    }
};