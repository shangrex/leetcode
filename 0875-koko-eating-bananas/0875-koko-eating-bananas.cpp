class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int speed = 1;
        int maxSpeed = 1;
        for(auto &i : piles){
            maxSpeed = max(i, maxSpeed);
        }
        int midSpeed;
        while(speed < maxSpeed){
            midSpeed = (speed+maxSpeed)/2;

            int tmpHour = 0;
            for(auto &i: piles){
                tmpHour += (i/midSpeed);
                if(i%midSpeed) tmpHour += 1;
            }

            if(tmpHour > h){
                speed = midSpeed+1;
            }
            else {
                maxSpeed = midSpeed;
            }
        }

        return speed;
    }
};