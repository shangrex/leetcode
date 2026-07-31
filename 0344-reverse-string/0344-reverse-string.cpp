class Solution {
public:
    void reverseString(vector<char>& s) {
        int leftIdx = 0, rightIdx = s.size()-1;
        while(leftIdx < rightIdx){
            swap(s[leftIdx], s[rightIdx]);
            leftIdx++;
            rightIdx--;
        }
    }
};