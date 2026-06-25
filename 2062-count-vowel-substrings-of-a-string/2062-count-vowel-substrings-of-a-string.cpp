class Solution {
public:
    bool isVow(char c){
        if(c == 'a' || c == 'e' || c == 'i' ||
            c == 'o' || c == 'u'){
                return true;
        }
        return false;
    }
    int atMost(string s, int k){
        unordered_map<char, int> vow;
        unordered_map<char, int> noVow;
        int ret = 0;
        int n = s.length();
        int right = 0, left = 0;

        while(right < n){
            if(isVow(s[right])){
                vow[s[right]]++;
            }
            else {
                left = right+1;
                right++;
                vow.clear();
                continue;
            }
            while(vow.size() > k && left < right){
                vow[s[left]]--;
                if(vow[s[left]] == 0){
                    vow.erase(s[left]);
                }
                left++;
            }
            ret+= right-left+1;
            right++;
        }
        return ret;
    }
    int countVowelSubstrings(string word) {
        return atMost(word, 5) - atMost(word, 4);
    }
};