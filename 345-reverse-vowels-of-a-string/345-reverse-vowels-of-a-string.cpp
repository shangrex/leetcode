class Solution {
public:
    
    bool check_in(char c){
        bool check = false;
        char vowels[10] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        for(int i = 0; i < 10; i++){
            if(c == vowels[i])return true;
        }
        return false;
    }
    
    string reverseVowels(string s) {
        /*
        "oabcii" ->"iibcao"
        
        A1 two pointer with head and tail, switch when both are vowels
        */
        int head = 0, tail = s.length()-1;
        while(head < tail){

            if(check_in(s[head]) == false){
                head++;
            }
            else if(check_in(s[tail]) == false){
                tail--;
            }
            else {
                swap(s[head], s[tail]);
                head ++;
                tail --;
            }
        }
        return s;
    }
};