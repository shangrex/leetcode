class Solution {
public:
    bool isValid(string n1, string n2, string remain){
        cout << n1 << " "<< n2 << " " << remain << endl;
        if(remain.length() < max(n1.length(), n2.length())) return false;
        if((n1.length() > 1 && n1[0] == '0') || 
            (n2.length() > 1 && n2[0] == '0')){
            return false;
        }
        long long first_num = stol(n1);
        long long second_num = stol(n2);
        // long long remain_num = stol(remain);
        if(to_string(first_num+second_num) == remain){
            return true;
        }
     
        bool flag = false;
        for(int i = 1; i < remain.length(); i++){
            string n3 = remain.substr(0, i);
            string n4 = remain.substr(i);
            // long long n3_int = stol(n3);
            // long long n4_int = stol(n4);
                // cout << first_num << " ";
            if(to_string(first_num + second_num) == n3){
                flag |= isValid(n2, n3, n4);
            }
        }
        return flag;
    }

    bool isAdditiveNumber(string num) {
        /*
        Approach 1. recursive check
        */
        int n = num.length();
        for(int i = 1; i <= n/2; i++){
            for(int j = i+1; j <= n-1; j++){
                // 112348
                //  i 
                //   j
                // i=1, j=1
                // 112

                if(isValid(num.substr(0, i), num.substr(i, j-i), num.substr(j, n-j))){
                    return true;
                }
            }
        }
        return false;
        
    }
};