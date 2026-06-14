class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> ransomMap, magazineMap;

        for(auto &c : ransomNote){
            ransomMap[c] += 1;
        }
        for(auto &c: magazine){
            magazineMap[c] += 1;
        }

        for(auto &c : ransomNote){
            if(magazineMap.find(c) == magazineMap.end()){
                // not exist
                return false;
            }
            if(ransomMap[c] > magazineMap[c]){
                return false;
            }
        }
        return true;
    }
};