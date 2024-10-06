class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        if(sentence2.length() > sentence1.length()){
            swap(sentence1, sentence2);
        }
        
        vector<string> s1, s2;
        
//         while(sentence1.size() > 0){
//             int f = sentence1.find(' ');
//             string s = sentence1.substr(0, f);
//             s1.push_back(s);
//             if(f < 0) break;
//             sentence1 = sentence1.substr(f+1);
//         }
        
//         while(sentence2.size() > 0){
//             int f = sentence2.find(' ');
//             string s = sentence2.substr(0, f);
//             s2.push_back(s);
//             if(f < 0) break;
//             sentence2 = sentence2.substr(f+1);
//         }
        
        stringstream ss1(sentence1), ss2(sentence2);
        string word;
        while(ss1 >> word) s1.push_back(word);
        while(ss2 >> word) s2.push_back(word);
        
        int s1_left = 0, s1_right = s1.size()-1;
        int s2_left = 0, s2_right = s2.size()-1;
        for(int i = 0; i < s2.size(); i++){
            if(s2[s2_left] == s1[s1_left]){
                s2_left++;
                s1_left++;
            }
            else break;
        }
        
        for(int i = s2.size()-1; i>=0; i--){
            if(s2[s2_right] == s1[s1_right]){
                s2_right--;
                s1_right--;
            }
            else break;
        }
        if(s2_left > s2_right)return true;
        return false;
        
    }
};