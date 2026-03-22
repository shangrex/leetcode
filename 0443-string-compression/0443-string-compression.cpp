class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int ans = 0;
        while(i < chars.size()){
            char letter = chars[i];
            int cnt = 0;
            while(i < chars.size() && chars[i] == letter){
                cnt++;
                i++;
            }

            chars[ans++] = letter;

            if(cnt > 1){
                for(auto c : to_string(cnt)){
                    chars[ans] = c;
                    ans++;
                }
            }
            
        }
        return ans;
    }
};