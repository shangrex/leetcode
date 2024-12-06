class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        int n = num1.length() + num2.length();

        string rst(n, '0');
        // string rst = "";
        for(int place1 = 0; place1 < num1.length(); place1++){
            int p1 = num1[place1] - '0';
            int carry = 0;
            for(int place2 = 0; place2 < num2.length(); place2++){
                int p2 = num2[place2] - '0';
                int r = rst[place1+place2] - '0';
                int rc = rst[place1+place2+1] - '0'; 
                int d1 = (p1*p2+r)%10;
                // carry = (p1+p2+r)/10;
                
                
                rst[place1+place2] = d1+'0';
              
                rst[place1+place2+1] = rc + (p1*p2+r)/10+'0';
                // if(place2 == num2.length()-1 && carry != 0) rst[place1+1+place2] = '1';    
            }
            
        }
        for(int i = rst.length()-1; i >= 0; i--){
            if(rst[i] == '0')rst.pop_back();
            else break;
        }
        reverse(rst.begin(), rst.end());

        return rst;
    }
};