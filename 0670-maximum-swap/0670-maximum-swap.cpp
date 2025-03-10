class Solution {
public:
    /*
    swap the maximun digit
    from left to right and swap the leftmost small number to rightmost number
    Approach 1. 
    brute force O(N^2)
    swap every possiblilites
    space O(N)


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

    Appraoch 2.
    two pass and swap once.
    maxRight store the index of the largest digit to the right of each position
    time complexity O(N)
    space complexity O(N)

    Approach 3. 
    one pass.

    */
    int maximumSwap(int num) {
        string s_num = to_string(num);
        int n = s_num.length();

        vector<int> maxRight(n, 0);

        maxRight[n-1] = n-1;
        for(int i = n-2; i >= 0; i--){
            if(s_num[maxRight[i+1]] >= s_num[i]){
                maxRight[i] = maxRight[i+1];
            }
            else maxRight[i] = i;
        }

        for(int i = 0; i < n-1; i++){
            if(s_num[i] < s_num[maxRight[i]]){
                cout << i << " " << maxRight[i];
                swap(s_num[i], s_num[maxRight[i]]);
                return stoi(s_num);
            }
        }

        return num;
    }
};