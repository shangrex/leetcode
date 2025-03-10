class Solution {
public:
    /*
    swap the maximun digit
    */
    int maximumSwap(int num) {
        string s_num = to_string(num);
        
        int cmp_num = num;
        for(int left = 0; left < s_num.length(); left++){
            for(int right = left+1; right < s_num.length(); right++){
                swap(s_num[left], s_num[right]);
                int tmp = stoi(s_num);
                if(cmp_num < tmp) {
                    cmp_num = tmp;
                }
                swap(s_num[left], s_num[right]);
            }
        }


        return cmp_num;
    }
};