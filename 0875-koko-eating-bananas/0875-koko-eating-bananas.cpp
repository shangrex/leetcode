class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // k
        int eat_speed = 1;
        int max_eat_speed = 1;
        
        // find max
        for(auto i : piles)max_eat_speed = max(max_eat_speed, i);
        
        while(eat_speed < max_eat_speed){
            long long int total_hours = 0;
            int middle = (eat_speed+max_eat_speed)/2;
            
            for(int i = 0; i < piles.size(); i++){
                total_hours += (piles[i] / middle);
                if(piles[i]%middle)total_hours+=1;
            }
            // cout << "eat speed" << eat_speed << " " << total_hours << endl;
            
            if(total_hours <= h){
                // success
                max_eat_speed = middle;
            }
            else {
                eat_speed = middle+1;
            }
            
        }
        
        return max_eat_speed;
        
    }
};