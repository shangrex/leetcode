class Solution {
public:
    /*
    method 1 
    use stack to operate string and compare
    method 2
    trace the two string from the string end to string front (two pointer method)
    
    test case
    b##a##b
    b
    */
    bool backspaceCompare(string s, string t) {
        int i = s.length()-1, j = t.length() -1;
        while(i > -1 || j > -1){
            int i_min = 0, j_min = 0;
            while(i > -1){
                if(s[i] == '#'){
                    i_min += 1;
                }
                else {
                    i_min -= 1;
                }
                if(i_min < 0)break;
                i -= 1;
            }
            
            while(j > -1){
                if(t[j] == '#'){
                    j_min += 1;
                }
                else {
                    j_min -= 1;
                }
                if(j_min < 0)break;
                j -= 1;
            }
            // cout << i << " " << s[i] << " " << j << " " << t[j] << endl;
            // two empty
            if(i < 0 && j < 0) return true;
            else if(i < 0 && j >= 0){
                // check j if empty string
                j_min = 0;
                while(j > -1){
                    if(t[j] == '#'){
                        j_min += 1;
                    }
                    else {
                        j_min -= 1;
                    }
                    if(j_min < 0)break;
                    j -= 1;
                }

                if(j < 0)return true;
                else return false;
            }
            else if(j < 0 && i >= 0){
                i_min = 0;
                while(i > -1){
                    if(s[i] == '#'){
                        i_min += 1;
                    }
                    else {
                        i_min -= 1;
                    }
                    if(i_min < 0)break;
                    i -= 1;
                }
                if(i < 0)return true;
                else return false;            
            }
            if(s[i] != t[j])return false;
            i -= 1;
            j -= 1;
        }
        
        return true;
    }
};