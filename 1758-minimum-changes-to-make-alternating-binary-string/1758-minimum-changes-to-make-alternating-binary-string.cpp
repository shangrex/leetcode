class Solution {
public:
    int minOperations(string s) {
        int cnt_1 = 0, cnt_2 = 0;
        for(int i = 0; i < s.length(); i++){
            if(i%2==0 && s[i] != '0') cnt_1++;
            else if(i%2==1 && s[i] != '1') cnt_1++;
        }
        for(int i = 0; i < s.length(); i++){
            if(i%2==0 && s[i] != '1') cnt_2++;
            else if(i%2==1 && s[i] != '0') cnt_2++;
        }
        return min(cnt_1, cnt_2);
    }
};